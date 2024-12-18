#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

Matrix* createMONO_matrix(int rows, int cols, int fill_value);
Matrix* create_matrix(int rows, int cols);
void destroy_matrix(Matrix* mat);

Matrix* fill_random_matrix(Matrix *mat, int min, int max); 
Matrix* add_matrices(Matrix* a, Matrix* b);
Matrix* subtract_matrices(Matrix* a, Matrix* b);
Matrix* multiply_matrices(Matrix* a, Matrix* b);
Matrix* transpose_matrix(Matrix* mat);
Matrix* copy_matrix(Matrix* mat);
void print_matrix(Matrix* mat);

#endif 

