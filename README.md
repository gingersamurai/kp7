# Отчет по курсовому проекту  7 по курсу
# "Фундаментальная информатика"

**студент группы:** М8О-110Б-21, Малышев Назим Бахтиярович\
**Контакты:** nazimmalyshev47@gmail.com\
**работа выполнена:** 14.05.2022\
**Преподаватель:** Никулин Сергей Петрович

## 1. Тема
Разреженные матрицы

## 2. Цель работы
Овладеть навыками работы с разреженными матрицами.

## 3. Задание
16 порядковый номер. варианты 4, 5, 1

## 4. Оборудование 
**CPU:** amd ryzen 5 5500U\
**RAM:** 16 GB\
**SSD:** 512 GB\
**MONITOR:** 2560 x 1440

## 5. Программное обеспечивание 
**Операционная система семейства:** ubuntu, **версия** 20.04 LTS\
**Интерпретатор команд:** bash, **версия** 5.0.17(1)-release.\
**Система программирования**: --, **версия**-- \
**Редактор текстов:** vs code, **версия** 1.66.1\
**Утилиты операционной системы:** --\
**Прикладные системы и программы:** --

## 6. Идея, метод, алгоритм
1. преобразование в структуру
    + в одном массиве хранить индексы в n-ичной сс.
    + в другом массиве хранить значения для индексов
    + если в первом нет нужного индекса, значит там ноль
    + в конце первого массива -1
2. выполение задания
    + сделать функцию линейного поиска индекса в разреженной матрице
    + если есть, то значение, иначе 0
    + если вектор * столбец матрицы = 0, то в результат 0
    + иначе добавляем как в п.1

# 7. Сценарий выполнения работы
1. реализация разреженной матрицы в matrix.c matrix.h
4. реализация основного файла main.c
5. настройка сборки и запуска проекта в makefile
6. тестирование
7. написание отчета 

# 8. Распечатка протокола

**main.c**
```c
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
    print(matr);
    printf("--------------------------\n");
}
```

**matrix.h**
```c
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

// печатает матрицу в обоих представлениях
void print(matrix *matr);

// найти элемент 
int find(matrix * matr, int key);

// выполнить задание
matrix task(matrix * matr);







#endif
```


**queue.c**
```c
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


```



**makefile**
```make
run: main
	./main
main: queue.o main.o
	gcc queue.o main.o -o main
queue.o: queue.c
	gcc -c queue.c -o queue.o
main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f main.o queue.o main

```

### пример работы
```
gingersamurai@matebook14:~/coding/lab/kp7$ make
gcc -c matrix.c -o matrix.o
gcc -c main.c -o main.o
gcc matrix.o main.o -o main
./main
enter count of raws and columns: 3 5 
enter matrix:
2 0 1 0 0 
3 4 0 0 0 
0 0 0 0 8 
--------------------------
before transformation:
--------------------------

LB: [ 0 2 5 6 14 -1 ]
YE: [ 2 1 3 4 8 ]

full matrix:
2 0 1 0 0 
3 4 0 0 0 
0 0 0 0 8 
--------------------------
enter vector with 3 element:
1 1 1

not null count: 4
after transformation
--------------------------

LB: [ 0 1 2 4 -1 ]
YE: [ 5 4 1 8 ]

full matrix:
5 4 1 0 8 
--------------------------
gingersamurai@matebook14:~/coding/lab/kp7$ make
./main
enter count of raws and columns: 3 5 
enter matrix:
2 0 1 0 0 
3 4 0 0 0 
0 0 0 0 8 
--------------------------
before transformation:
--------------------------

LB: [ 0 2 5 6 14 -1 ]
YE: [ 2 1 3 4 8 ]

full matrix:
2 0 1 0 0 
3 4 0 0 0 
0 0 0 0 8 
--------------------------
enter vector with 3 element:
-3 2 0

not null count: 2
after transformation
--------------------------

LB: [ 1 2 -1 ]
YE: [ 8 -3 ]

full matrix:
0 8 -3 0 0 
--------------------------
gingersamurai@matebook14:~/coding/lab/kp7$ MAKE
MAKE: команда не найдена
gingersamurai@matebook14:~/coding/lab/kp7$ make 
./main
enter count of raws and columns: 5 7
enter matrix:
0 0 0 0 1 0 0
1 0 0 0 3 0 3
5 0 0 0 3 0 0  
0 0 0 0 0 0 0
0 0 0 0 0 0 0
--------------------------
before transformation:
--------------------------

LB: [ 4 7 11 13 14 18 -1 ]
YE: [ 1 1 3 3 5 3 ]

full matrix:
0 0 0 0 1 0 0 
1 0 0 0 3 0 3 
5 0 0 0 3 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
--------------------------
enter vector with 5 element:
1 0 0 0 0 

not null count: 1
after transformation
--------------------------

LB: [ 4 -1 ]
YE: [ 1 ]

full matrix:
0 0 0 0 1 0 0 
--------------------------
gingersamurai@matebook14:~/coding/lab/kp7$ make 
./main
enter count of raws and columns: 5
7
enter matrix:
0 0 0 0 1 0 0 
1 0 0 0 3 0 3 
5 0 0 0 3 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
--------------------------
before transformation:
--------------------------

LB: [ 4 7 11 13 14 18 -1 ]
YE: [ 1 1 3 3 5 3 ]

full matrix:
0 0 0 0 1 0 0 
1 0 0 0 3 0 3 
5 0 0 0 3 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
--------------------------
enter vector with 5 element:
1 1 1 1 1

not null count: 3
after transformation
--------------------------

LB: [ 0 4 6 -1 ]
YE: [ 6 7 3 ]

full matrix:
6 0 0 0 7 0 3 
--------------------------
gingersamurai@matebook14:~/coding/lab/kp7$ 

```


## 9. Дневник отладки
--

## 10. Замечания автора
--
## 11. Выводы
Мной была изучена такая структура, как разреженные матрицы.\
Разреженные матрицы – очень полезная структура,
которая может решать различные задачи