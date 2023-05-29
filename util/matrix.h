#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int rows; // number of rows
    int cols; // number of columns
    float** data; // a pointer to an array of n_rows pointers to rows
};
typedef struct Matrix Matrix;

Matrix* make_matrix(int rows, int cols) {
    Matrix* m = malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(sizeof(float*) * rows);
    for(int i = 0; i < rows; i++) {
        m->data[i] = malloc(sizeof(float) * cols);
    }
    return m;
}

Matrix* make_matrix_from_array(int rows, int cols, float* data) {
    Matrix* m = make_matrix(rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m->data[i][j] = data[i * cols + j];
        }
    }
    return m;
}

void print_matrix(Matrix* m) {
    for(int i = 0; i < m->rows; i++) {
        for(int j = 0; j < m->cols; j++) {
            printf("%f ", m->data[i][j]);
        }
        printf("\n");
    }
}
