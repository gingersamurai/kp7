#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

matrix *read_matrix(){
    matrix *matr =(matrix *) malloc(sizeof(matrix));
    printf("enter count of colums and count of raws: ");
    scanf("%d %d", &matr->size_n, &matr->size_m);
    for (int i = 0; i < matr->size_n; i++){
        for (int j = 0; j < matr->size_m; j++){
            
        }
    }
}