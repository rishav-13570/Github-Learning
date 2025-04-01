#include <stdio.h>

float f(float x) {
    return 1 / (1 + x * x);
}

int main() {
    float a, b, val, h;
    int n, i;

    printf("Enter the upper limit: ");
    scanf("%f", &b);
    printf("Enter the lower limit: ");
    scanf("%f", &a);
    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of intervals must be greater than zero.\n");
        return 1;
    }

    h = (b - a) / n;

    float x[n + 1], y[n + 1];

    for (i = 0; i <= n; i++) {
        x[i] = a + (i * h);
        y[i] = f(x[i]);
    }

    float sum = y[0] + y[n];
    for (i = 1; i < n; i++) {
        sum += 2 * y[i];
    }
    
    val = (h / 2) * sum;

    printf("Integral value using Trapezoidal Rule: %f\n", val);
    
    return 0;
}
