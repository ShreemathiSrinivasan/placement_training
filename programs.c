PROGRAM 1 swapping of numbers

#include <stdio.h>

int main() {
    int num1, num2;

    // Input
    printf("Enter the first number (num1): ");
    scanf("%d", &num1);

    printf("Enter the second number (num2): ");
    scanf("%d", &num2);

    // Swapping without a temporary variable
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

    // Output
    printf("After swapping:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    return 0;
}


PROGRAM 2 NO OF YEARS,DAYS,WEEKS

#include <stdio.h>

int main() {
    int totalDays;

    // Input
    printf("Enter the total number of days: ");
    scanf("%d", &totalDays);

    // Calculate years, weeks, and remaining days
    int years = totalDays / 365;
    int weeks = (totalDays % 365) / 7;
    int remainingDays = (totalDays % 365) % 7;

    // Output
    printf("Number of Years: %d\n", years);
    printf("Number of Weeks: %d\n", weeks);
    printf("Number of Days: %d\n", remainingDays);

    return 0;
}


PROGRAM 3:POLYNOMIAL


#include <stdio.h>

// Function to evaluate the polynomial
double evaluatePolynomial(int degree, int coefficients[], double x) {
    double result = 0.0;

    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, degree - i);
    }

    return result;
}

int main() {
    int degree;

    // Input degree of the polynomial
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    // Input coefficients
    int coefficients[degree + 1];
    printf("Enter the coefficients (from x^%d to x^0): ", degree);
    for (int i = 0; i <= degree; i++) {
        scanf("%d", &coefficients[i]);
    }

    // Input value of x
    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // Evaluate the polynomial
    double result = evaluatePolynomial(degree, coefficients, x);

    // Output
    printf("P(%lf) = %lf\n", x, result);

    return 0;
}
