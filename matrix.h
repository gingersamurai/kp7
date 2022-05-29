#ifndef MATRIX_H
#define MATRIX_H

#define MAXSIZE 100

typedef struct {
    int lb[MAXSIZE*MAXSIZE];
    int ye[MAXSIZE*MAXSIZE];
    int size_n;
    int size_m;
} matrix;

// считывание матрицы
matrix *read_matrix();













#endif