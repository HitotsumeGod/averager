#include <stdio.h>
#include <stdlib.h>
#include "eq.h"

double *findquartiles(double *narr, size_t narrs) {

	int med;
	double *quarts;
	
	med = narrs / 2;
	if ((quarts = malloc(sizeof(double) * 3)) == NULL) {
		printf("Memory allocation error. Report to Peter immediately.");
		exit(EXIT_FAILURE);
	}
	if (narrs % 2 == 0) {
                if (med % 2 == 0) {
                        quarts[0] = (*(narr + (med / 2 - 1)) + *(narr + (med / 2))) / 2;
                        quarts[1] = (*(narr + med - 1) + *(narr + med)) / 2;
                        quarts[2] = (*(narr + ((med / 2 - 1) + med)) + *(narr + ((med / 2) + med))) / 2;
                } else {
                        quarts[0] = *(narr + ((med + 1) / 2) - 1);
                        quarts[1] = (*(narr + med - 1) + *(narr + med)) / 2;
                        quarts[2] = *(narr + ((((med + 1) / 2) + med) - 1));
        	}
        } else {
                ++med;
                quarts[0] = *(narr + (med / 2) - 1);
                quarts[1] = *(narr + (med - 1));
                quarts[2] = *(narr + (med + (med / 2) - 1));
        }
        return quarts;

}
