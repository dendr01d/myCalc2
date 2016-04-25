#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


//why didn't I just use c++ x_x
int MAX_LIST_LENGTH = 100;


void printList(int array[], int length) {
    for (int j = 0; j < length; ++j) {
        printf("%-3d", array[j]);
    }
    printf("\n");
}

static int getBit(int n, int bit) {
    //right shift and then eliminate all but 1 bit
    return ((n >> bit) & 0x1); 
}

void radixSort(int array[], int length) {
    //shadow array
    int shadow[MAX_LIST_LENGTH];
    int ind = 0;
    
    for (int i = 0; i < 32; ++i) {
        ind = 0;
        
        //first copy all the numbers where bit i is 0
        //  into the shadow array
        for (int j = 0; j < length; ++j) {
            if (getBit(array[j], i) == 0) {
                shadow[ind] = array[j];
                ++ind;
            }
        }
        
        //if we copied either ALL or NONE of them, then this bit
        //  won't help us sort and we might as well skip to the next round
        if (ind == 0 || ind == length) {
            continue;
        }
        
        //now do the ones where the bit is 1
        for (int j = 0; j < length; ++j) {
            if (getBit(array[j], i) == 1) {
                shadow[ind] = array[j];
                ++ind;
            }
        }
        
        //now copy them all back
        for (int j = 0; j < length; ++j) {
            array[j] = shadow[j];
        }   
    }
}
