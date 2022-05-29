#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

matrix *read_matrix(){
    matrix *matr = (matrix *) malloc(sizeof(matrix));
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
    for (int i = 0; matr->lb[i-1] != -1; i++){
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
                if (matr->lb[cur] == -1) printf("0 ");
                else {
                    printf("\nTROUBLE %d %d %d\n",matr->lb[cur], i, j);
                    exit(1);
                }
            }
            
        }
        printf("\n");
    }
}

int find(matrix * matr, int key){
    for (int i = 0; matr->lb[i] != 1; i++) {
        if (matr->lb[i] == key) return i;
    }
    return -1;
}

matrix task(matrix *matr){
    int vec[matr->size_n];
    printf("enter vector with %d element:\n", matr->size_n);
    for (int i = 0;i < matr->size_n; i++){
        scanf("%d", &vec[i]);
    }
    
    matrix res;
    res.size_m = matr->size_m;
    res.size_n = 1;
    int cur = 0;
    for (int j = 0; j < matr->size_m; j++){
        int x = 0;
        for (int i = 0; i < matr->size_n;i++){
            int id = find(matr, i * matr->size_m + j);
            if (id != -1) {
                x += matr->ye[id] * vec[i]; 
            }
        }
        if (x != 0) {
            res.lb[cur] = j;
            res.ye[cur] = x;
            cur++;
        }
    }
    res.lb[cur] = -1;    
    printf("\nnot null count: %d\n", cur);
    return res;
}
