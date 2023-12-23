PROGRAM 1 23-12-23

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Adding one to the last digit
    digits[digitsSize - 1] += 1;
    
    // Checking for carry
    int carry = 0;
    for (int i = digitsSize - 1; i >= 0; i--) {
        digits[i] += carry;
        carry = digits[i] / 10;
        digits[i] %= 10;
    }
    
    // If there's a carry after the loop, we need to resize the array
    if (carry > 0) {
        *returnSize = digitsSize + 1;
        int* result = (int*)malloc((*returnSize) * sizeof(int));
        result[0] = carry;
        for (int i = 1; i < *returnSize; i++) {
            result[i] = digits[i - 1];
        }
        return result;
    } else {
        *returnSize = digitsSize;
        return digits;
    }
}

int main() {
    // Example 1: Incrementing [1, 2, 3]
    int arr1[] = {1, 2, 3};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int returnSize1;

    int *result1 = plusOne(arr1, size1, &returnSize1);

    printf("Input: [1, 2, 3]\nOutput: [");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d", result1[i]);
        if (i != returnSize1 - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    free(result1);

    // Example 2: Incrementing [9]
    int arr2[] = {9};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int returnSize2;

    int *result2 = plusOne(arr2, size2, &returnSize2);

    printf("\nInput: [9]\nOutput: [");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d", result2[i]);
        if (i != returnSize2 - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    
    free(result2);

    return 0;
}


PROGRAM 2

#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int furthest = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > furthest) {
            return false;
        }
        furthest = (i + nums[i]) > furthest ? (i + nums[i]) : furthest;
        if (furthest >= numsSize - 1) {
            return true;
        }
    }
    
    return furthest >= numsSize - 1;
}

int main() {
    // Example 1: [2,3,1,1,4]
    int nums1[] = {2, 3, 1, 1, 4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);

    bool result1 = canJump(nums1, size1);
    printf("Input: [2, 3, 1, 1, 4]\nOutput: %s\n", result1 ? "true" : "false");

    // Example 2: [3,2,1,0,4]
    int nums2[] = {3, 2, 1, 0, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);

    bool result2 = canJump(nums2, size2);
    printf("\nInput: [3, 2, 1, 0, 4]\nOutput: %s\n", result2 ? "true" : "false");

    return 0;
}


PROGRAM 3

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        currentSum = (nums[i] > currentSum + nums[i]) ? nums[i] : currentSum + nums[i];
        maxSum = (currentSum > maxSum) ? currentSum : maxSum;
    }

    return maxSum;
}

int main() {
    // Example 1: [-2,1,-3,4,-1,2,1,-5,4]
    int nums1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);

    int result1 = maxSubArray(nums1, size1);
    printf("Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]\nOutput: %d\n", result1);

    // Example 2: [1]
    int nums2[] = {1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);

    int result2 = maxSubArray(nums2, size2);
    printf("\nInput: [1]\nOutput: %d\n", result2);

    // Example 3: [5,4,-1,7,8]
    int nums3[] = {5, 4, -1, 7, 8};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);

    int result3 = maxSubArray(nums3, size3);
    printf("\nInput: [5, 4, -1, 7, 8]\nOutput: %d\n", result3);

    return 0;
}
