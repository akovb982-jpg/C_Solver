# include <stdio.h>
# include <math.h>
# include <stdbool.h>


bool is_zero(double x){
    return fabs(x) < 1e-9;
}

double arctan(double x){

    double epsilon = 1e-9;
    double result = 0.0;
    double term = x;
    int n = 1;

    while (fabs(term) > epsilon) {
        result += term;
        term *= -x * x * (2 * n - 1) / (2 * n + 1);
        n++;
    }

    return result;
}

double arctan_derivative(double x) {
    return 1.0 / (1.0 + x * x);
}



int test_arctan(){

    if(!is_zero(arctan(0.0))){
        printf("Test failed: arctan(0.0) should be 0.0\n");
        return 1;
    }
    if(!is_zero(arctan(1.0) - M_PI/4)){
        printf("Test failed: arctan(1.0) should be approximately π/4\n");
        return 1;
    }
    
    if(!is_zero(arctan(1.0) - M_PI/4)){
        printf("Test failed: arctan(1.0) should be approximately π/4\n");
        return 1;
    }
    return 0;
}

int test_arctan_derivative(){
    if(!is_zero(arctan_derivative(0.0) - 1.0)){
        printf("Test failed: arctan_derivative(0.0) should be 1.0\n");
        return 1;
    }
    if(!is_zero(arctan_derivative(1.0) - 0.5)){
        printf("Test failed: arctan_derivative(1.0) should be approximately 0.5\n");
        return 1;
    }
    if(!is_zero(arctan_derivative(-1.0) - 0.5)){
        printf("Test failed: arctan_derivative(-1.0) should be approximately 0.5\n");
        return 1;
    }
    return 0;
}