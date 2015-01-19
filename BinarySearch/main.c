//
//  main.c
//  BinarySearch
//
//  Created by Renato Camilio on 1/13/15.
//  Copyright (c) 2015 Renato Camilio. All rights reserved.
//

#include <stdio.h>
#include <math.h>


int binarySearch(int array[], int value, int min, int max) {
    if (max < min) {
        return -1;
    }
    
    int middleIndex = (min + max) / 2;

    if (array[middleIndex] > value) {
        return binarySearch(array, value, min, middleIndex - 1);
    } else if (array[middleIndex] < value) {
        return binarySearch(array, value, middleIndex + 1, max);
    } else {
        return middleIndex;
    }
}



int main(int argc, char * argv[]) {
    int numbers[] = { 1, 2, 2, 3, 4, 4, 4 };
    int numbersSize = sizeof(numbers) / sizeof(int);

    int result = binarySearch(numbers, 4, 0, numbersSize - 1);
    printf("found at index %i\n", result);

    return 0;
}
