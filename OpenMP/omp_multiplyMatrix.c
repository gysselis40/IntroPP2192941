//Objetivo: Este código es una versión paralelizada del
//código anterior que utiliza la librería OpenMP para acelerar el cálculo. 
//El bucle exterior se ha paralelizado para que los hilos trabajen en diferentes 
//iteraciones del bucle y aceleren el cálculo.

//Modificado: 22 Septiembre 2023

//Autor: Gysselis Vásquez


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h> 

void multiplyMatrix(int R1, int C1, int R2, int C2, int m1[R1][C1], int m2[R2][C2])
{
    int result[R1][C2];

    printf("La matriz 1 es:\n");

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C1; j++) {
            m1[i][j] = rand() % 100; 
            printf("%d\t", m1[i][j]);
        }

    }

    printf("\nLa matriz 2 es:\n");

    for (int i = 0; i < R2; i++) {
        for (int j = 0; j < C2; j++) {
            m2[i][j] = rand() % 100; 
            printf("%d\t", m2[i][j]);
        }

    }


    clock_t begin = clock();

    #pragma omp parallel for 
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            result[i][j] = 0;

            for (int k = 0; k < R2; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }

            printf("%d\t", result[i][j]);
        }

        printf("\n");
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    double time_in_milliseconds = time_spent * 1000;
    printf("Tiempo de ejecución: %f milisegundos\n", time_in_milliseconds);
}

int main()
{
    int R1, C1, R2, C2;

    printf("Ingrese el número de filas de la matriz 1: ");
    scanf("%d", &R1);

    printf("Ingrese el número de columnas de la matriz 1: ");
    scanf("%d", &C1);

    printf("Ingrese el número de filas de la matriz 2: ");
    scanf("%d", &R2);

    printf("Ingrese el número de columnas de la matriz 2: ");
    scanf("%d", &C2);

    int m1[R1][C1];
    int m2[R2][C2];

    srand(time(NULL)); 
    multiplyMatrix(R1, C1, R2, C2, m1, m2);

    return 0;
}
