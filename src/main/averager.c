#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eq.h"

#define BUFLEN 50

int compa(const void *a, const void *b);

int main(int argc, char *argv[]) {

	FILE *fptr;
	unsigned long numlines, res;
	int count, c;
	size_t fname_size;
	double *numarr, *quarts;
	char *buf, *dotline, *fname, *prefix;
	if (argc != 2) {
		printf("%s\n", "Improper format. Please launch the applicaton with a single argument (the filename of the file to be read from). Example : \"averager.exe myfile.txt\".");
		exit(EXIT_FAILURE);
	}
	prefix = "src/res/";
	if ((fname = malloc(sizeof(char) * ((fname_size = strlen(argv[1]) + strlen(prefix) + 1)))) == NULL) {
		printf("%s\n", "Memory allocation error. Immediately report to Peter.");
		exit(EXIT_FAILURE);
	}
	if (snprintf(fname, fname_size, "%s%s%c", prefix, argv[1], '\0') == -1) {
		printf("%s\n", "String formatting error. Immediately report to Peter.");
		exit(EXIT_FAILURE);
	}
	if ((fptr = fopen(fname, "r")) == NULL) {
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
	quarts = findquartiles(numarr, numlines);
	dotline = "-------------------------------";
	printf("%s\n1st Quartile is : %.2f\nMedian is : %.2f\n3rd Quartile is : %.2f\nInterquartile Range is : %.2f\n%s\n", dotline, quarts[0], quarts[1], quarts[2], quarts[0] - quarts[2], dotline);
	if (fclose(fptr) == -1) {
		printf("%s\n", "File close error. Report to Peter immediately.");
		exit(EXIT_FAILURE);
	}
	free(quarts);
	free(fname);
	free(buf);
	free(numarr);
	return 0;

}

int compa(const void *a, const void *b) {

	return *(int *) a - *(int *) b;

}
