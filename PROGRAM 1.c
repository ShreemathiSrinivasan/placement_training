PROGRAM 1

call by value

#include <stdio.h>

// Function to swap values using Call By Value
void swapByValue(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 10;

    printf("Before swapping using Call By Value: a = %d, b = %d\n", a, b);

    // Call the function passing values
    swapByValue(a, b);

    printf("After swapping using Call By Value: a = %d, b = %d\n", a, b);

    return 0;
}

call by reference

#include <stdio.h>

// Function to swap values using Call By Reference
void swapByReference(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 5, b = 10;

    printf("Before swapping using Call By Reference: a = %d, b = %d\n", a, b);

    // Call the function passing addresses
    swapByReference(&a, &b);

    printf("After swapping using Call By Reference: a = %d, b = %d\n", a, b);

    return 0;
}

PROGRAM 2

#include <stdio.h>
#include <stdlib.h>

int* findDuplicates(int N, int arr[]) {
    int* duplicates = (int*)malloc(N * sizeof(int));
    int i, idx, count = 0;

    for (i = 0; i < N; i++) {
        idx = abs(arr[i]);
        if (arr[idx] >= 0) {
            arr[idx] = -arr[idx];
        } else {
            duplicates[count++] = idx;
        }
    }

    if (count == 0) {
        duplicates[0] = -1;
        return duplicates;
    } else {
        // Sort the duplicates in ascending order
        for (i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (duplicates[i] > duplicates[j]) {
                    int temp = duplicates[i];
                    duplicates[i] = duplicates[j];
                    duplicates[j] = temp;
                }
            }
        }
        return duplicates;
    }
}

int main() {
    int N1 = 4;
    int arr1[] = {0, 3, 1, 2};
    int* result1 = findDuplicates(N1, arr1);

    printf("Example 1 Output: ");
    for (int i = 0; result1[i] != -1 && i < N1; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    free(result1);

    int N2 = 5;
    int arr2[] = {2, 3, 1, 2, 3};
    int* result2 = findDuplicates(N2, arr2);

    printf("Example 2 Output: ");
    for (int i = 0; result2[i] != -1 && i < N2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");
    free(result2);

    return 0;
}


PROGRAM 3

#include <stdio.h>

void printUnion(int arr1[], int n, int arr2[], int m) {
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            printf("%d ", arr1[i++]);
        } else if (arr2[j] < arr1[i]) {
            printf("%d ", arr2[j++]);
        } else {
            printf("%d ", arr2[j++]);
            i++;
        }
    }

    while (i < n) {
        printf("%d ", arr1[i++]);
    }

    while (j < m) {
        printf("%d ", arr2[j++]);
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    printf("Union of the arrays: ");
    printUnion(arr1, n, arr2, m);

    return 0;
}
