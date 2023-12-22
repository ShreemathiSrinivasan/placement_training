PROGRAM 1

#include <stdio.h>

int main() {
    int matrix[3][3];
    
    // Get values from the user
    printf("Enter values for the 3x3 matrix:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("Enter element at position [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Display the matrix
    printf("\nMatrix:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

PROGRAM 2

#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    
    // Get input from the user
    printf("Enter input string: ");
    scanf("%s", input);

    // Process the input and generate the output
    for (int i = 0; input[i] != '\0';) {
        char current_char = input[i];
        i++;

        int count = 0;
        while (isdigit(input[i])) {
            count = count * 10 + (input[i] - '0');
            i++;
        }

        for (int j = 0; j < count; j++) {
            printf("%c", current_char);
        }
    }

    printf("\n");

    return 0;
}


PROGRAM 3

#include <stdio.h>

int main() {
    int rows, i, j;

    // Get the number of rows from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Print the pattern
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
