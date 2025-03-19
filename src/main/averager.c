#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 50

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
	res = 0;
	int i;
	for (i = 0; i < numlines; i++) {
		res += *(numarr + i);
	}
	printf("%lu\n", res / numlines);
	if (fclose(fptr) == -1) {
		perror("fclose err");
		exit(EXIT_FAILURE);
	}
	free(buf);
	free(numarr);
	return 0;

}
