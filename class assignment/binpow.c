#include <stdio.h>

int linSteps = 0, binSteps = 0;  // Global counters

// O(n)
int linPow(int X, int n) {
    linSteps++;  
    if (n == 0) return 1;  
    return X * linPow(X, n - 1);
}

// O(log n) 
int binPow(int X, int n) {
    binSteps++;  
    if (n == 0) return 1;

    int halfPower = binPow(X, n / 2);  
    if (n % 2 == 0)
        return halfPower * halfPower;
    else
        return X * halfPower * halfPower;
}

int main() {
    printf("Enter the base and power : ");
    int X, n;
    scanf("%d %d" , &X , &n);
    int result1 = linPow(X, n);
    printf("linPow(%d, %d) = %d, Steps = %d\n", X, n, result1, linSteps);
    int result2 = binPow(X, n);
    printf("binPow(%d, %d) = %d, Steps = %d\n", X, n, result2, binSteps);
    return 0;
}
