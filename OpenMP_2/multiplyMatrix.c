//Objetivo: Este código toma las dimensiones de dos matrices como entrada 
//y genera dos matrices aleatorias. Luego, realiza la multiplicación 
//de matrices y muestra la matriz resultante junto con el tiempo de ejecución.


//Modificado: 22 September 2023

//Autor: Gysselis Vásquez

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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
	struct timeval t0, t1;
	gettimeofday(&t0, 0);

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            result[i][j] = 0;

            for (int k = 0; k < R2; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }

    }

    	gettimeofday(&t1, 0);

    	printf("\nLa matriz resultante es:\n");
	for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
	double elapsed2 = (t1.tv_sec-t0.tv_sec) * 1.0f + (t1.tv_usec - t0.tv_usec) / 1000000.0f;
	printf("TIEMPO secuencial: %f\n", elapsed2);
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

    multiplyMatrix(R1, C1, R2, C2, m1, m2);

    return 0;
}
