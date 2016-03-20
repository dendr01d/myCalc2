#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void printList(int array[], int length) {
    for (int j = 0; j < length; ++j) {
        printf("%-3d", array[j]);
    }
    printf("\n");
}

void radixSort(int array[], int length) {
    //here are some buckets, their (nominal) sizes, and an index holder
    int *bucket0 = malloc(length * sizeof(bucket0));
    int *bucket1 = malloc(length * sizeof(bucket1));
    int size0 = 0;
    int size1 = 0;

    //for every digit in an int (the bitmask's bit will eventually be shifted off the end)
    for (unsigned int i = 1; i != 0; i <<= 1) {
        
        //use bit masking to count and sort each number into buckets
        size0 = 0;
        size1 = 0;
        for (int j = 0; j < length; ++j) {
            if ((array[j] & i) == 0) {
                bucket0[j - size1] = array[j];
                ++size0;
            }
            else {
                bucket1[j - size0] = array[j];
                ++size1;
            }
        }
        
        //copy the numbers back into the original array
        int counter = 0;
        
        for (int j = 0; j < size0; ++j) {
            array[counter] = bucket0[j];
            ++counter;
        }
        for (int j = 0; j < size1; ++j) {
            array[counter] = bucket1[j];
            ++counter;
        }
        
        //debug output
        #ifdef DEBUG
            printf("\n\nMask: %d\n", i);
            printf("0 Bucket: ");
            printList(bucket0, size0);
            printf("1 Bucket: ");
            printList(bucket1, size1);
            printf("\n");
            printList(array, length);
        #endif
    }
        
    //clear the buckets
    free(bucket0);
    free(bucket1);

}
