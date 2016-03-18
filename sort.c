#include <climits>

using namespace std;

void radixSort(int array[], int length) {
    //for every digit in an int (32 of them)
    for (int i = 1; i < INT_MAX; i *= 2) {
        int numZ, numO;
        
        //use bit masking to see what the current digit is and count them
        for (int j = 0; j < length; ++j) {
            if (array[j] & i) {
                ++numO;
            }
            else {
                ++numZ;
            }
        }
        
        //create buckets to store the values
        int *zeroes = new int[numZ];
        int *ones = new int[numO];
        
        int *zP = zeroes;
        int *oP = ones;
        
        //sort the numbers into the buckets
        for (int j = 0; j < length; ++j) {
            if (array[j] & i) {
                &oP = array[j];
                ++oP;
            }
            else {
                &zP = array[j];
                ++zP;
            }
        }
        
        //copy the numbers back into the original array
        
        int *zP = zeroes;
        int *oP = ones;
        int counter = 0;
        
        for (int j = 0; j < numZ; ++j) {
            array[counter] = &zP;
            ++counter;
        }
        for (int j = 0; j < numO; ++j) {
            array[counter] = &zP;
            ++counter;
        }
        
        //debug output
        #ifdef DEBUG
            for (int j = 0; j < length; ++j) {
                printf("%-3d", array[j];
            }
            printf("\n");
        #endif
    }

}
