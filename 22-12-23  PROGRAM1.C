22-12-23  PROGRAM1

#include <stdio.h>
#include <math.h>

int main() {
    char shape;
    float size;

    // Input
    printf("Enter the shape (S for Square, C for Circle): ");
    scanf(" %c", &shape);

    // Check for the shape and calculate the area
    if (shape == 'S' || shape == 's') {
        printf("Enter the side length of the square: ");
        scanf("%f", &size);

        float area_square = size * size;
        printf("Area of Square = %.2f\n", area_square);
    } else if (shape == 'C' || shape == 'c') {
        printf("Enter the radius of the circle: ");
        scanf("%f", &size);

        float area_circle = M_PI * size * size;
        printf("Area of Circle = %.2f\n", area_circle);
    } else {
        printf("Invalid shape input. Please enter 'S' for Square or 'C' for Circle.\n");
    }

    return 0;
}


#include <stdio.h>
#include <math.h>

int main() {
    char shape;
    float size;

    // Input
    printf("Enter the shape (S for Square, C for Circle): ");
    scanf(" %c", &shape);

    // Check for the shape and calculate the area
    if (shape == 'S' || shape == 's') {
        printf("Enter the side length of the square: ");
        scanf("%f", &size);

        float area_square = size * size;
        printf("Area of Square = %.2f\n", area_square);
    } else if (shape == 'C' || shape == 'c') {
        printf("Enter the radius of the circle: ");
        scanf("%f", &size);

        float area_circle = M_PI * size * size;
        printf("Area of Circle = %.2f\n", area_circle);
    } else {
        printf("Invalid shape input. Please enter 'S' for Square or 'C' for Circle.\n");
        return 1;  // Return an error code
    }

    return 0;
}


PROGRAM 2

#include <stdio.h>

void printFrequency(int arr[], int n) {
    int i = 0;
    while (i < n) {
        // Count occurrences of current element
        int count = 1;
        while (i < n - 1 && arr[i] == arr[i + 1]) {
            count++;
            i++;
        }

        // Print element and its frequency if more than one appearance
        if (count > 1) {
            printf("%d->%d", arr[i], count);
            if (i < n - 1) {
                printf(",");
            }
        }

        i++;
    }
    printf("\n");
}

int main() {
    int N = 12;
    int Array[] = {1, 1, 1, 2, 4, 4, 4, 4, 5, 6, 9, 9};

    printf("Sample Input:\nN = %d\nArray = {", N);
    for (int i = 0; i < N; i++) {
        printf("%d", Array[i]);
        if (i < N - 1) {
            printf(",");
        }
    }
    printf("}\n");

    printf("Sample Output:\n");
    printFrequency(Array, N);

    return 0;
}


PROGRAM 3

#include <stdio.h>
#include <string.h>

void justifySentence(char sentence[], int screenLength) {
    int words = 0;
    int len = strlen(sentence);

    // Count the number of words in the sentence
    for (int i = 0; i < len; i++) {
        if (sentence[i] == ' ') {
            words++;
        }
    }
    words++; // Include the last word

    // Calculate the number of spaces needed
    int spacesNeeded = screenLength - len;

    // Calculate the number of spaces to be added between words
    int spacesBetweenWords = spacesNeeded / (words - 1);

    // Calculate the number of extra spaces to be added to some words
    int extraSpaces = spacesNeeded % (words - 1);

    // Justify the sentence by replacing spaces with stars
    for (int i = 0; i < len; i++) {
        if (sentence[i] == ' ') {
            int count = spacesBetweenWords;
            while (count > 0) {
                printf("*");
                count--;
            }

            // Add extra space to some words
            if (extraSpaces > 0) {
                printf("*");
                extraSpaces--;
            }
        } else {
            printf("%c", sentence[i]);
        }
    }

    printf("\n");
}

int main() {
    char sentence1[] = "Welcome to Zoho Corporation";
    int screenLength1 = 34;

    char sentence2[] = "Welcome to Zoho Corporation";
    int screenLength2 = 36;

    printf("Sample Input 1:\nSentence = %s\nScreen length = %d\n", sentence1, screenLength1);
    printf("Sample Output 1:\n");
    justifySentence(sentence1, screenLength1);

    printf("\nSample Input 2:\nSentence = %s\nScreen length = %d\n", sentence2, screenLength2);
    printf("Sample Output 2:\n");
    justifySentence(sentence2, screenLength2);

    return 0;
}

