#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 50

int compa(const void *a, const void *b);

int main(int argc, char *argv[]) {

	FILE *fptr;
	unsigned long numlines, res;
	int count, c, med;
	float *numarr, q1, q2, q3;
	char *buf, *dotline;
	if (argc != 2) {
		printf("%s\n", "Improper format. Please launch the applicaton with a single argument (the filename of the file to be read from). Example : \"averager.exe myfile.txt\".");
		exit(EXIT_FAILURE);
	}
	if ((fptr = fopen(argv[1], "r")) == NULL) {
		printf("%s\n", "File not found. Please provide the file in the same directory as this program and then provide the filename.");
		exit(EXIT_FAILURE);
	}
	count = 0;
	while ((c = fgetc(fptr)) != EOF)
		if (c == '\n')
			count++;
	numlines = count;
	rewind(fptr);
	if ((buf = malloc(sizeof(char) * BUFLEN)) == NULL || (numarr = malloc(sizeof(int) * numlines)) == NULL) {
		printf("%s\n", "Memory allocation error. Immediately report to Peter.");
		exit(EXIT_FAILURE);
	}		
	count = 0;
	while (fgets(buf, BUFLEN, fptr) != NULL) {
		*(numarr + count) = atof(buf);
		count++;
	}
	qsort(numarr, count, sizeof(float), compa);
	res = 0;
	int i;
	for (i = 0; i < numlines; i++) 
		res += *(numarr + i);
	med = numlines / 2;
	if (numlines % 2 == 0) {
		if (med % 2 == 0) {
			q1 = (*(numarr + (med / 2 - 1)) + *(numarr + (med / 2))) / 2;
			q2 = (*(numarr + med - 1) + *(numarr + med)) / 2;
			q3 = (*(numarr + ((med / 2 - 1) + med)) + *(numarr + ((med / 2) + med))) / 2;
		} else {
			q1 = *(numarr + ((med + 1) / 2) - 1);
			q2 = (*(numarr + med - 1) + *(numarr + med)) / 2;
			q3 = *(numarr + ((((med + 1) / 2) + med) - 1));
		}
	} else {
		++med;
		q1 = *(numarr + (med / 2) - 1);
		q2 = *(numarr + (med - 1));
		q3 = *(numarr + (med + (med / 2) - 1));
	}
	dotline = "-------------------------------";
	printf("%s\n1st Quartile is : %.2f\nMedian is : %.2f\n3rd Quartile is : %.2f\nInterquartile Range is : %.2f\n%s\n", dotline, q1, q2, q3, q3 - q1, dotline);
	if (fclose(fptr) == -1) {
		printf("%s\n", "File close error. Report to Peter immediately.");
		exit(EXIT_FAILURE);
	}
	free(buf);
	free(numarr);
	return 0;

}

int compa(const void *a, const void *b) {

	return *(int *) a - *(int *) b;

}
