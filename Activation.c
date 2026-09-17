#include <math.h>
#include <stdio.h>
#include <stdbool.h>
bool iszero(double x) {
    return fabs(x) < 1e-9;
}
double soft_sign(double x) {
    return x/(1+fabs(x));
}
double soft_sign_derivative(double x) {
    const double h = 1e-5;
    return (soft_sign(x+h)-soft_sign(x-h))/(2*h);
}
int test_soft_sign() {
    if (!iszero(soft_sign(0))) {
        printf("test for soft_sign has failed\n");
        return 1;
    }
    if (!iszero(soft_sign(1)-0.5)) {
        printf("test for soft_sign has failed\n");
        return 1;
    }
    if (!iszero(soft_sign(-1)+0.5)) {
        printf("test for soft_sign has failed\n");
        return 1;
    }
    return 0;
}
int derivative_test_soft_sign() {
    if (!iszero(soft_sign_derivative(-1))) {
        printf("test for soft_sign has failed\n");
        return 1;
    }
    if (!iszero(soft_sign_derivative(0)-1)) {
        printf("test for soft_sign has failed\n");
        return 1;
    }
    if (!iszero(soft_sign_derivative(1)-0.5)) {
        printf("test for soft_sign has failed\n");
        return 1;
    }
    return 0;
}
int main() {
    if (test_soft_sign()==0) {
        printf("tests for soft_sign have succeeded\n");
    }
    if (derivative_test_soft_sign()==0) {
        printf("tests for soft_sign derivative have succeeded\n");
    }
    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("the soft sign function is %lf\n", soft_sign(x));
    printf("the derivative function is %lf\n", soft_sign_derivative(x));
}