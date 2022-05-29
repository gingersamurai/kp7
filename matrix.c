#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

matrix *read_matrix(){
    matrix *matr =(matrix *) malloc(sizeof(matrix));
    printf("enter count of raws and columns: ");
    scanf("%d %d", &matr->size_n, &matr->size_m);
    printf("enter matrix:\n");
    int cur = 0;
    for (int i = 0; i < matr->size_n; i++){
        for (int j = 0; j < matr->size_m; j++){
            int x;
            scanf("%d", &x);
            if (x != 0){
                matr->lb[cur] = i * matr->size_m + j;
                matr->ye[cur] = x;
                cur++;
            }
        }
    }
    matr->lb[cur] = -1;
    return matr;
}

void print(matrix *matr){
    
    printf("\nLB: [ ");
    for (int i = 0; matr->lb[i] != -1; i++){
        printf("%d ", matr->lb[i]);
    }
    printf("]\n");

    printf("YE: [ ");
    for (int i = 0; matr->lb[i] != -1; i++){
        printf("%d ", matr->ye[i]);
    }
    printf("]\n\n");
    printf("full matrix:\n");
    int cur = 0;
    for(int i = 0; i < matr->size_n; i++){
        for (int j = 0; j < matr->size_m; j++){
            if (matr->lb[cur] > i*matr->size_m+j) printf("0 ");
            else if (matr->lb[cur] == i*matr->size_m+j){
                printf("%d ", matr->ye[cur]);
                cur++;
            } else {
                printf("\nTROUBLE\n");
                exit(1);
            }
            
        }
        printf("\n");
    }
}