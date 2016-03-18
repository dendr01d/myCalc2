#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pow.h"
#include "sort.h"

#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3
#define POW 4
#define MOD 5
#define SORT 6

#define OPTIONS 7

//operations can only be 4 letters long
static const char options[][5] = { {"add"}, {"sub"}, {"mul"}, {"div"}, {"pow"}, {"mod"}, {"sort"}};

void printUsage() {
    printf("Usage: myCalc <operation> a b (c, d, e...)\n");
    printf("Operations: add, sub, mul, div, pow, mod, sort\n");
	exit(1);
}

int whichOption(char *str){
    for (int i = 0; i < OPTIONS; ++i) {
        if (strcmp(str, options[i]) == 0) {
            return i;
        }
    }
    return 0;
}

int main (int argc, char *argv[]) {
    if (argc < 4) {
	    printUsage();
    }

    int a = atoi(argv[2]);
    int b = atoi(argv[3]);

    #ifdef DEBUG
    printf("Just so you know, this is in debug mode!\n");
    #endif
    
    int array[argc - 2];
    
    switch(whichOption(argv[1])) {
        case ADD:
            printf("%d\n", a + b);
            break;
        
        case SUB:
            printf("%d\n", a - b);
            break;
        
        case MUL:
            printf("%d\n", a * b);
            break;
        
        case DIV:
            printf("%d\n", a / b);
            break;
        
        case POW:
            printf("%d\n", myPow(a, b));
            break;
        
        case MOD:
            printf("%d\n", a % b);
            break;
        
        case SORT:
            for (int i = 2; i < argc; ++i) {
                array[i-2] = atoi(argv[i]);
            }
            #ifdef DEBUG
            printf("this is the array I'm working on...\n");
            printList(array, argc - 2);
            #endif
            radixSort(array, argc - 2);
            printList(array, argc - 2);
            break;
        
        default:
            printUsage();
            break;
    }
    
    return 0;
}
