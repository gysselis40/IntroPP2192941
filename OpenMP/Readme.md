# EVALUACIÓN 1 

## Multiplicación de matrices
- No paralelizado: Para este problema, se tomó el código fuente y se le hicieron unas modificaciones para que recibiera como entrada las dimensiones de las matrices, y a partir de ello, generará dos matrices con valores aleatorios y posteriormente hiciera el cálculo del producto de esas dos matrices.
  
- Paralelizado: Este código es una versión paralelizada del código anterior que utiliza la librería OpenMP para acelerar el cálculo. El bucle exterior se ha paralelizado para que los hilos trabajen en diferentes iteraciones del bucle y aceleren el cálculo.
Para dimensionalidades pequeñas se obtuvieron valores muy pequeños al ejecutarse sobre GUANE:

![texto_alternativo](https://github.com/gysselis40/IntroPP2192941/blob/main/OpenMP/Imagenes/Imagen1.png)


