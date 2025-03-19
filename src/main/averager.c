#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 50

int compa(const void *a, const void *b);

int main(int argc, char *argv[]) {

	FILE *fptr;
	unsigned long numlines, res;
	int *numarr, count, c;
	char *buf;
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
		perror("malloc err");
		exit(EXIT_FAILURE);
	}		
	count = 0;
	while (fgets(buf, BUFLEN, fptr) != NULL) {
		*(numarr + count) = atoi(buf);
		count++;
	}
	qsort(numarr, count, sizeof(int), compa);
	res = 0;
	int i;
	for (i = 0; i < numlines; i++) 
		res += *(numarr + i);
	printf("Median is %lu\n1st Quartile is %lu\n2nd Quartile is %lu\n", *(numarr + ((numlines + 1) * 2/4)), *(numarr + ((numlines + 1) * 1/4)), *(numarr + ((numlines + 1) * 3/4)));
	if (fclose(fptr) == -1) {
		perror("fclose err");
		exit(EXIT_FAILURE);
	}
	free(buf);
	free(numarr);
	return 0;

}

int compa(const void *a, const void *b) {

	return *((int *) a) - *((int *) b);

}
