#include <stdio.h>
#include <stdlib.h>

int findDuplicate(int* nums, int numsSize) {
    int upperBound = numsSize - 1, i = 0;
    int *frequency = malloc(upperBound * sizeof(int));
    for (; i < upperBound; i++) {
        frequency[i] = 0;
    }
    for (i = 0; i < numsSize; i++) {
        frequency[nums[i] - 1] = frequency[nums[i] - 1] + 1;
    }
    for (i = 0; i < numsSize; i++) {
        if (frequency[nums[i] - 1] > 1) {
            return nums[i];
        }
    }
    return -1;
}



int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 5};
    printf("%d \n", findDuplicate(arr, 10));
    int arr1[] = {1,3,4,2,2};
    printf("%d \n", findDuplicate(arr1, 5));
    int arr2[] = {3,1,3,4,2};
    printf("%d \n", findDuplicate(arr2, 5));
    int arr3[] = {3,3,3,3,3};
    printf("%d \n", findDuplicate(arr3, 5));
    return (0);
}
