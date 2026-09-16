// Task 'з'
#include <stdio.h>
#include <math.h>
#include <stdbool.h>



// check if a floating-point number is practically zero
bool is_zero(double x) {
    return fabs(x) < 1e-9;
}

// main function
double sigmweight(double x) {
    return x / (1.0 + exp(-x));
}

double sigmweight_derivative(double x) {
    double exp_nx = exp(-x);
    double denom = 1.0 + exp_nx;
    return (1.0 + (x + 1.0) * exp_nx) / (denom * denom);
}

double numerical_derivative(double x, double h) {
    return (sigmweight(x + h) - sigmweight(x - h)) / (2.0 * h);
}



// Run basic tests for zero
int test_sigmweight() {
    if (!is_zero(sigmweight(0.0))) {
        printf("Test failed: sigweight(0) != 0\n");
        return 1;
    }

    if (!is_zero(sigmweight_derivative(0.0) - 0.5)) {
        printf("Test failed: sigmweight_derivative(0) != 0.5\n");
        return 1;
    }

    return 0;
}



//TESTS
void print_test_table() {
    double h = 1e-5;
    double x, diff;

    x = -10.00;
    diff = fabs(sigmweight_derivative(x) - numerical_derivative(x, h));
    printf("%6.2f | %9.6f | %9.6f | %9.6f | %9.2e\n", 
        x, sigmweight(x), sigmweight_derivative(x), numerical_derivative(x, h), diff);

    x = -1.00;
    diff = fabs(sigmweight_derivative(x) - numerical_derivative(x, h));
    printf("%6.2f | %9.6f | %9.6f | %9.6f | %9.2e\n", 
        x, sigmweight(x), sigmweight_derivative(x), numerical_derivative(x, h), diff);

    x = -0.50;
    diff = fabs(sigmweight_derivative(x) - numerical_derivative(x, h));
    printf("%6.2f | %9.6f | %9.6f | %9.6f | %9.2e\n", 
        x, sigmweight(x), sigmweight_derivative(x), numerical_derivative(x, h), diff);

    x = 0.00;
    diff = fabs(sigmweight_derivative(x) - numerical_derivative(x, h));
    printf("%6.2f | %9.6f | %9.6f | %9.6f | %9.2e\n", 
        x, sigmweight(x), sigmweight_derivative(x), numerical_derivative(x, h), diff);

    x = 0.50;
    diff = fabs(sigmweight_derivative(x) - numerical_derivative(x, h));
    printf("%6.2f | %9.6f | %9.6f | %9.6f | %9.2e\n", 
        x, sigmweight(x), sigmweight_derivative(x), numerical_derivative(x, h), diff);

    x = 1.00;
    diff = fabs(sigmweight_derivative(x) - numerical_derivative(x, h));
    printf("%6.2f | %9.6f | %9.6f | %9.6f | %9.2e\n", 
        x, sigmweight(x), sigmweight_derivative(x), numerical_derivative(x, h), diff);

    x = 10.00;
    diff = fabs(sigmweight_derivative(x) - numerical_derivative(x, h));
    printf("%6.2f | %9.6f | %9.6f | %9.6f | %9.2e\n", 
        x, sigmweight(x), sigmweight_derivative(x), numerical_derivative(x, h), diff);
}



int main() {
    test_sigmweight();
    print_test_table();
}