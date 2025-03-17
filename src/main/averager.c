#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 50

int main(int argc, char *argv[]) {

	FILE *fptr;
	unsigned int res, count;
	char *buf;
	if (argc != 2) {
		printf("%s\n", "Improper format. Please launch the applicaton with a single argument (the filename of the file to be read from). Example : \"averager.exe myfile.txt\".");
		exit(EXIT_FAILURE);
	}
	if ((buf = malloc(sizeof(char) * BUFLEN)) == NULL) {
		perror("malloc err");
		exit(EXIT_FAILURE);
	}
	if ((fptr = fopen(argv[1], "r")) == NULL) {
		printf("%s\n", "File not found. Please provide the file in the same directory as this program and then provide the filename.");
		exit(EXIT_FAILURE);
	}
	res = 0, count = 0;
	while (fgets(buf, BUFLEN, fptr) != NULL) {
		res += atoi(buf);
		count++;
	}
	printf("%s%u%c\n", "Numerical average is ", res / count, '.');
	if (fclose(fptr) == -1) {
		perror("fclose err");
		exit(EXIT_FAILURE);
	}
	free(buf);
	return 0;

}
