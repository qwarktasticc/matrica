#include "matrix.h"

Matrix* create_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        fprintf(stderr, "Число строк и столбцов должно быть положительным целым числом.\n");
        return NULL;
    }
    Matrix* mat = (Matrix*)malloc(sizeof(Matrix));
    if (mat == NULL) {
        fprintf(stderr, "Ошибка выделения памяти.\n");
        return NULL;
    }
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int*)calloc(rows * cols, sizeof(int)); 
    if (mat->data == NULL) {
        fprintf(stderr, "Ошибка выделения памяти.\n");
        free(mat);
        return NULL;
    }
    return mat;
}

Matrix* createMONO_matrix(int rows, int cols, int fill_value) {
    Matrix* mat = create_matrix(rows, cols);
    if (mat == NULL) return NULL;
    for (int i = 0; i < rows * cols; i++) {
        mat->data[i] = fill_value;
    }
    return mat;
}


Matrix* transpose_matrix(Matrix* mat) {
    if (!mat) {
        fprintf(stderr, "Указатель на матрицу некорректен.\n");
        return NULL;
    }
    Matrix* result = create_matrix(mat->cols, mat->rows);
    if (!result) return NULL;
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[j * mat->rows + i] = mat->data[i * mat->cols + j]; 
        }
    }
    return result;
}

Matrix* copy_matrix(Matrix* mat) {
    if (!mat) {
        fprintf(stderr, "Указатель на матрицу некорректен.\n");
        return NULL;
    }
    Matrix* result = create_matrix(mat->rows, mat->cols);
    if (!result) return NULL;
    memcpy(result->data, mat->data, mat->rows * mat->cols * sizeof(int)); 
    return result;
}

void destroy_matrix(Matrix* mat) {
    if (mat) {
        free(mat->data);
        free(mat);
    }
}

Matrix* fill_random_matrix(Matrix *mat, int min, int max) {
    if (!mat) return NULL;
    srand(time(NULL)); 
    for (int i = 0; i < mat->rows * mat->cols; i++) {
        mat->data[i] = min + rand() % (max - min + 1);
    }
    return mat;
}

Matrix* createMONO_matrix(int rows, int cols, int fill_value) {
    if (rows <= 0 || cols <= 0) {
        fprintf(stderr, "Некорректные размеры матрицы.\n");
        return NULL;
    }
    Matrix* mat = (Matrix*)malloc(sizeof(Matrix));
    if (!mat) {
        fprintf(stderr, "Ошибка выделения памяти для структуры матрицы.\n");
        return NULL;
    }
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int*)calloc(rows * cols, sizeof(int));
    if (!mat->data) {
        fprintf(stderr, "Ошибка выделения памяти для данных матрицы.\n");
        free(mat);
        return NULL;
    }
    for (int i = 0; i < rows * cols; i++) {
        mat->data[i] = fill_value;
    }

    return mat;
}



void print_matrix(Matrix* mat) {
    if (!mat) {
        fprintf(stderr, "Некорректный указатель на матрицу.\n");
        return;
    }
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}


Matrix* subtract_matrices(Matrix* a, Matrix* b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        fprintf(stderr, "Матрицы должны иметь одинаковые размеры для вычитания.\n");
        return NULL;
    }
    Matrix* result = create_matrix(a->rows, a->cols);
    if (!result) {
        return NULL;
    }
    for (int i = 0; i < a->rows * a->cols; i++) {
        result->data[i] = a->data[i] - b->data[i];
    }
    return result;
}


Matrix* sum_matrices(Matrix* a, Matrix* b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        fprintf(stderr, "Матрицы должны иметь одинаковые размеры для суммирования.\n");
        return NULL;
    }
    Matrix* result = create_matrix(a->rows, a->cols);
    if (!result) {
        return NULL;
    }
    for (int i = 0; i < a->rows * a->cols; i++) {
        result->data[i] = a->data[i] + b->data[i];
    }
    return result;
}


Matrix* multiply_matrices(Matrix* a, Matrix* b) {
    if (a->cols != b->rows) {
        fprintf(stderr, "Количество столбцов в A должно быть равно количеству строк в B для умножения.\n");
        return NULL;
    }
    Matrix* result = create_matrix(a->rows, b->cols);
    if (!result) {
        return NULL;
    }
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            result->data[i * b->cols + j] = sum;
        }
    }
    return result;
}

