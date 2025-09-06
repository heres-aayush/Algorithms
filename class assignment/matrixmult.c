#include <stdio.h>
#include <limits.h>

// optimal parenthesization recursively
void printOptimalParenthesis(int s[][5], int i, int j, char *name) {
    if (i == j) {
        printf("%c", (*name)++);
        return;
    }
    printf("(");
    printOptimalParenthesis(s, i, s[i][j], name);
    printOptimalParenthesis(s, s[i][j] + 1, j, name);
    printf(")");
}

// display matrices
void displayMatrices(int m[][5], int s[][5], int n) {
    // Print m matrix
    printf("\nMatrix m:\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j >= i)
                printf("%7d ", m[i][j]);
            else
                printf("       ");
        }
        printf("\n");
    }
    
    // s matrix
    printf("\nMatrix s:\n");
    for (int i = 1; i < n - 1; i++) {
        for (int j = 2; j < n; j++) {
            if (j > i)
                printf("%7d ", s[i][j]);
            else
                printf("       ");
        }
        printf("\n");
    }
}

// minimum cost of multiplying matrices
void matrixChainOrder(int p[], int n) {
    int m[n][n]; 
    int s[n][n]; 
    
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }
    
    for (int chainLength = 2; chainLength < n; chainLength++) {
        for (int i = 1; i < n - chainLength+1 ; i++) {
            int j = i + chainLength - 1;
            m[i][j] = INT_MAX;
            
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    
    printf("Minimum number of multiplications is %d\n", m[1][n - 1]);
    
    // Display matrices
    displayMatrices(m, s, n);
    
    // Print optimal parenthesization
    printf("\nOptimal Parenthesization: ");
    char name = 'A';
    printOptimalParenthesis(s, 1, n - 1, &name);
    printf("\n");
}

int main() {
    int p[] = {13, 5, 89, 3, 34 }; //dimensions  (number of matrices+1)
    int n = sizeof(p) / sizeof(p[0]);
    
    matrixChainOrder(p, n); //p
    
    return 0;
}

