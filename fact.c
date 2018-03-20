#include <stdio.h>

int MAX_LIST_LEN = 100;

void factor(int n) {
    int factors[MAX_LIST_LEN];
    int numFactors = 0;
    
    int div = 1;
    
    while (div <= n) {
        if (n % div == 0) {
            factors[numFactors] = div;
            ++numFactors;
            n /= div;
        }
        else {
            ++div;
        }    
    }

    printf("1");
    
    for (int i = 1; i < numFactors; ++i) {
        printf(", %d", factors[i]);
    }
    
    printf("\n\n");
}
