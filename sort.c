#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void printList(int array[], int length) {
    for (int j = 0; j < length; ++j) {
        printf("%-3d", array[j]);
    }
    printf("\n");
}

void printMaskedList(int array[], int length, int mask) {
    for (int j = 0; j < length; ++j) {
        printf("%-3d", array[j] & mask);
    }
    printf("\n");
}


void radixSort(int array[], int length) {
    //here are some buckets, their (nominal) sizes, and an index holder
    int* bucket0 = malloc(length * sizeof(bucket0));
    int* bucket1 = malloc(length * sizeof(bucket1));
    int size0 = 0;
    int size1 = 0;
    int ind0 = 0;
    int ind1 = 0;
    
    int mask = 1;

    //for every digit in an int (32 of them)
    for (int i = 0; i < 32; ++i) {
        
        
        //use bit masking to see what the current digit is and count them
        size0 = 0;
        size1 = 0;
        for (int j = 0; j < length; ++j) {
            if ((array[j] & i) == 0) {
                ++size0;
            }
            else {
                ++size1;
            }
        }
        
        //sort the numbers into the buckets
        ind0 = 0;
        ind1 = 0;
        for (int j = 0; j < length; ++j) {
            if ((array[j] & i) == 0) {
                bucket0[ind1] = array[j];
                ++ind0;
            }
            else {
                bucket1[ind1] = array[j];
                ++ind1;
            }
        }
        
        //copy the numbers back into the original array
        
        ind0 = 0;
        ind1 = 0;
        int counter = 0;
        
        #ifdef DEBUG
            printf("\n0 Bucket: ");
        #endif
        for (int j = 0; j < size0; ++j) {
            array[counter] = bucket0[ind0];
            #ifdef DEBUG
                printf("%d ", bucket0[ind0]);
            #endif
            ++ind0;
            ++counter;
        }
        #ifdef DEBUG
            printf("\n1 Bucket: ");
        #endif
        for (int j = 0; j < size1; ++j) {
            array[counter] = bucket1[ind1];
            #ifdef DEBUG
                printf("%d ", bucket1[ind1]);
            #endif
            ++ind1;
            ++counter;
        }
        
        //debug output
        #ifdef DEBUG
            printf("\nMask: %d\n", mask);
            printList(array, length);
            printMaskedList(array, length, mask);
        #endif
        
        //increment the mask
        mask <<= 1;
    }
        
    //clear the buckets
    free(bucket0);
    free(bucket1);

}
