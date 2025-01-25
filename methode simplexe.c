#include <stdio.h>
#include <stdlib.h>
#include <float.h>

void simplex(int num_vars, int num_constraints, double c[], double A[][num_vars + num_constraints], double b[]) {
    int i, j;
    double tableau[num_constraints + 1][num_vars + num_constraints + 1];
    for (i = 0; i < num_constraints; i++) {
        for (j = 0; j < num_vars; j++) {
            tableau[i][j] = A[i][j];
        }
        tableau[i][num_vars + i] = 1; 
        tableau[i][num_vars + num_constraints] = b[i];
    }
    for (j = 0; j < num_vars; j++) {
        tableau[num_constraints][j] = -c[j];
    }
    while (1) {
        int pivot_col = -1;
        double min_value = 0;
        for (j = 0; j < num_vars + num_constraints; j++) {
            if (tableau[num_constraints][j] < min_value) {
                min_value = tableau[num_constraints][j];
                pivot_col = j;
            }
        }
        if (pivot_col == -1) break;  
        
        int pivot_row = -1;
        double min_ratio = DBL_MAX;
        for (i = 0; i < num_constraints; i++) {
            if (tableau[i][pivot_col] > 0) {
                double ratio = tableau[i][num_vars + num_constraints] / tableau[i][pivot_col];
                if (ratio < min_ratio) {
                    min_ratio = ratio;
                    pivot_row = i;
                }
            }
        }
        if (pivot_row == -1) {
            printf("Le problème est non borné.\n");
            return;
        }
        double pivot_value = tableau[pivot_row][pivot_col];
        for (j = 0; j <= num_vars + num_constraints; j++) {
            tableau[pivot_row][j] /= pivot_value;
        }
        for (i = 0; i <= num_constraints; i++) {
            if (i != pivot_row) {
                double factor = tableau[i][pivot_col];
                for (j = 0; j <= num_vars + num_constraints; j++) {
                    tableau[i][j] -= factor * tableau[pivot_row][j];
                }
            }
        }
    }
    double solution[num_vars];
    for (j = 0; j < num_vars; j++) {
        solution[j] = 0;
        for (i = 0; i < num_constraints; i++) {
            if (tableau[i][j] == 1) {
                solution[j] = tableau[i][num_vars + num_constraints];
                break;
            }
        }
    }
    printf("Solution optimale : ");
    for (j = 0; j < num_vars; j++) {
        printf("%.2f ", solution[j]);
    }
    printf("\nValeur maximale : %.2f\n", tableau[num_constraints][num_vars + num_constraints]);
}

int main() {
    int num_vars, num_constraints;
    printf("Entrez le nombre de variables : ");
    scanf("%d", &num_vars);
    printf("Entrez le nombre de contraintes : ");
    scanf("%d", &num_constraints);

    double c[num_vars];
    printf("Entrez les coefficients de la fonction objectif : ");
    for (int i = 0; i < num_vars; i++) {
        scanf("%lf", &c[i]);
    }

    double A[num_constraints][num_vars + num_constraints];
    printf("Entrez les coefficients des contraintes :\n");
    for (int i = 0; i < num_constraints; i++) {
        for (int j = 0; j < num_vars; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    double b[num_constraints];
    printf("Entrez les termes constants des contraintes : ");
    for (int i = 0; i < num_constraints; i++) {
        scanf("%lf", &b[i]);
    }

    simplex(num_vars, num_constraints, c, A, b);

    return 0;
}
