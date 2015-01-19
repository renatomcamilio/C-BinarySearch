//
//  main.c
//  BinarySearch
//
//  Created by Renato Camilio on 1/13/15.
//  Copyright (c) 2015 Renato Camilio. All rights reserved.
//

#include <stdio.h>
#include <math.h>

typedef struct BSrange {
    int firstIndex;
    int ocurrencies;
} BSRange;

BSRange *binarySearch(int array[], int value, int min, int max, BSRange *range) {
    if (max < min) {
        return range;
    }
    
    int middleIndex = (min + max) / 2;

    if (array[middleIndex] > value) {
        return binarySearch(array, value, min, middleIndex - 1, range);
    } else if (array[middleIndex] < value) {
        return binarySearch(array, value, middleIndex + 1, max, range);
    } else {
        range->ocurrencies += 1;
        
        if (range->firstIndex < 0) {
            range->firstIndex = middleIndex;
        } else if (range->firstIndex > middleIndex) {
            range->firstIndex = middleIndex;
        }
        
        binarySearch(array, value, min, middleIndex - 1, range);
        binarySearch(array, value, middleIndex + 1, max, range);
        
        return range;
    }
}



int main(int argc, char * argv[]) {
    int numbers[] = { 1, 2, 2, 3, 4, 4, 4 };
    int numbersSize = sizeof(numbers) / sizeof(int);
    BSRange range = { .firstIndex = -1, .ocurrencies = 0 };

    binarySearch(numbers, 4, 0, numbersSize - 1, &range);
    printf("result: {%i, %i}\n", range.firstIndex, range.ocurrencies);

    return 0;
}
