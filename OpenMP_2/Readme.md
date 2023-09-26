# EVALUACIÓN 1 

## Multiplicación de matrices
**No paralelizado:** Para este problema, se tomó el código fuente y se le hicieron unas modificaciones para que recibiera como entrada las dimensiones de las matrices, y a partir de ello, generará dos matrices con valores aleatorios y posteriormente hiciera el cálculo del producto de esas dos matrices.
  
**Paralelizado:** Este código es una versión paralelizada del código anterior que utiliza la librería OpenMP para acelerar el cálculo. El bucle exterior se ha paralelizado para que los hilos trabajen en diferentes iteraciones del bucle y aceleren el cálculo.
Para dimensionalidades pequeñas se obtuvieron valores muy pequeños al ejecutarse sobre GUANE:

Para compilarlo los diferentes archivos, debe tener en cuenta estos comandos: 

Secuencial: 
1) gcc -std=c99 -Wall multiplyMatrix.c -o multiplyMatrix
2) ./multiplyMatrix


Paralelo: 
1) gcc -std=c99 -Wall -fopenmp omp_multiplyMatrix.c -o omp_multiplyMatrix
2) ./omp_multiplyMatrix


## Resultados
- Para valores pequeños: 
![texto_alternativo](https://github.com/gysselis40/IntroPP2192941/blob/main/OpenMP_2/Im%C3%A1genes/valores%20peque%C3%B1os.png)

Para valores más grandes se obtuvo lo siguiente: 

![texto_alternativo](https://github.com/gysselis40/IntroPP2192941/blob/main/OpenMP/Imagenes/Imagen2.png)

Secuencial: 

![texto_alternativo](https://github.com/gysselis40/IntroPP2192941/blob/main/OpenMP/Imagenes/Imagen3.png)

Paralelo: 

![texto_alternativo](https://github.com/gysselis40/IntroPP2192941/blob/main/OpenMP/Imagenes/Imagen4.png)

Cuando las matrices son de una dimensionalidad muy grande, los resultados tienen una diferencia significativa, de alguna forma, el código paralelizado resulta en un menor rendimiento, la razón puede ser debido a la sobrecarga de hilos, sobre todo con la impresión de las diferentes matrices. 
Por otro lado, en unas pruebas que se hicieron en el equipo local, los resultados fueron muchos mejores cuando se trataba de altas dimensionalidades. De hecho, se hizo la prueba de quitar las salidas de las matrices y de esa forma se obtuvo un mejor rendimiento en el código paralelizado.





