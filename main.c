#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"



int main(){
    matrix *matr = read_matrix();
    printf("--------------------------\n");
    printf("before transformation:\n");
    printf("--------------------------\n");
    print(matr);
    printf("--------------------------\n");
    *matr = task(matr);
    printf("after transformation\n");
    printf("--------------------------\n");
    // printf("%d %d\n", matr->size_n, matr->size_m);
    print(matr);
    printf("--------------------------\n");
}