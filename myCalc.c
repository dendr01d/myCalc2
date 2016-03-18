#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pow.h"


int main (int argc, char *argv[]) {
    if (argc != 4) {
	printf("usage: myCalc <add/sub/mul/div/pow> a b\n");
	exit(1);
    }

    int a = atoi(argv[2]);
    int b = atoi(argv[3]);

    #ifdef DEBUG
    printf("Just so you know, this is in debug mode!\n");
    #endif

    if (strcmp(argv[1], "add") == 0) {
        printf("%d\n", a + b);
    }
    else if (strcmp(argv[1], "sub") == 0) {
        printf("%d\n", a - b);
    }
    else if (strcmp(argv[1], "mul") == 0) {
        printf("%d\n", a * b);
    }
    else if (strcmp(argv[1], "div") == 0) {
        printf("%d\n", a / b);
    }
    else if (strcmp(argv[1], "pow") == 0) {
        printf("%d\n", myPow(a, b));
    }
    else if (strcmp(argv[1], "mod") == 0) {
        printf("%d\n", a % b);
        
    else {
        printf("usage: myCalc <add/sub/mul/div/pow/mod> a b\n");
	exit(1);
    }  

    return 0;
}
