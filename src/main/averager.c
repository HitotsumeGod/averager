#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 50

int main(int argc, char *argv[]) {

	FILE *fptr;
	long fsize;
	int *numarr, count;
	char *buf;
	if (argc != 2) {
		printf("%s\n", "Improper format. Please launch the applicaton with a single argument (the filename of the file to be read from). Example : \"averager.exe myfile.txt\".");
		exit(EXIT_FAILURE);
	}
	if ((fptr = fopen(argv[1], "r")) == NULL) {
		printf("%s\n", "File not found. Please provide the file in the same directory as this program and then provide the filename.");
		exit(EXIT_FAILURE);
	}
	if (fseek(fptr, 0, SEEK_END) == -1) {
		perror("fseek err");
		exit(EXIT_FAILURE);
	}
	if ((fsize = ftell(fptr)) == -1) {
		perror("ftell err");
		exit(EXIT_FAILURE);
	}
	rewind(fptr);
	if ((buf = malloc(sizeof(char) * BUFLEN)) == NULL || (numarr = malloc(sizeof(int) * fsize)) == NULL) {
	       perror("malloc err");
		exit(EXIT_FAILURE);
	}		
	count = 0;
	while (fgets(buf, BUFLEN, fptr) != NULL) {
		//printf("%d\t", atoi(buf));
		*(numarr + count) = atoi(buf);
		count++;
	}
	unsigned long res = 0;
	int i;
	for (i = 0; i < fsize; i++) {
		res += *(numarr + i);
	}
	printf("king%d\n", i);
	printf("%lu\n", res / fsize);
	if (fclose(fptr) == -1) {
		perror("fclose err");
		exit(EXIT_FAILURE);
	}
	free(buf);
	free(numarr);
	return 0;

}
