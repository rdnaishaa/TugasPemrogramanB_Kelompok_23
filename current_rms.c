#include <stdio.h>
#include <math.h>

#define T 1.0                       // Period of 1 second
#define PHI 3.14159                 // declaration of phi value
#define EXACT_INTEGRAL 15.41261     // integral result of i^2(t) over one period (for verification)

// Current signal function
double current(double t) {
    if (t < T/2.0) {
        return 10.0 * exp(-t/T) * sin((2*PHI*t)/T);
    }
    return 0.0;
}

// trapezoidal rule for newton-cotes integration
double trapezoidal_rule(int n, double a, double b) {
    double h = (b - a)/n;
    double sum = 0.0;
    
    // First point
    sum += 0.5 * current(a) * current(a);
    
    // Middle points
    for (int i = 1; i < n; i++) {
        double t = a + i*h;
        sum += current(t) * current(t);
    }
    
    // Last point
    sum += 0.5 * current(b) * current(b);
    
    return sum * h;
}

// Simpson's 1/3 rule for newton-cotes integration
double simpsons_rule(int n, double a, double b) {
    double h = (b - a)/n;           // calculate gap between points
    double sum = current(a)*current(a) + current(b)*current(b);
    
    for (int i = 1; i < n; i++) {
        double t = a + i*h;         // calculate the t value to evaluate the current function

        // simpson's coefficients
        if (i % 2 == 0) {
            sum += 2.0 * current(t) * current(t);   // if i is even, multiply by 2
        } else {
            sum += 4.0 * current(t) * current(t);   // if i is odd, multiply by 4
        }
    }
    return sum * h / 3.0;
}

int main() {
    double a = 0.0;     // start of integration
    double b = T/2.0;  // upper limit of integration. only integrate from 0 to T/2 since i(t) is zero after T/2
    
    printf("Calculating integral of i^2(t) over one period (T = %.2f seconds)\n", T);
    printf("Exact integral value: %.5f\n\n", EXACT_INTEGRAL);
    
    // Trapezoidal rule calculations
    printf("trapezoidal rule:\n");
    for (int n = 1; n <= 128; n *= 2) {
        double integral = trapezoidal_rule(n, a, b);
        double error = fabs((integral - EXACT_INTEGRAL)/EXACT_INTEGRAL) * 100;
        printf("segment %d, %.5f, %.5f%%\n", n, integral, error);
    }
    
    // Simpson's 1/3 rule calculations
    printf("\nsimpson 1/3 rule:\n");
    for (int n = 2; n <= 32; n *= 2) {
        double integral = simpsons_rule(n, a, b);
        double error = fabs((integral - EXACT_INTEGRAL)/EXACT_INTEGRAL) * 100;
        printf("segment %d, %.5f, %.5f%%\n", n, integral, error);
    }
    
    // Calculate RMS from the exact integral
    double rms = sqrt(EXACT_INTEGRAL/T);
    printf("\nRMS current: %.5f A\n", rms);
    
    return 0;
}