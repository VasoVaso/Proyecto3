Link al video:


 ****CONSIDERACIONES****


-El programa fallará si se introduce un dato distinto al solicitado, por ejemplo, si se solicita un int y se introduce un char.


 ****DESCRIPCIÓN DE FUNCIONES****


-->> FUNCIONES DE RELLENADO DE VECTORES

-randomModeFill(): crea un vector con números en orden ascendente y luego los mezcla aleatoriamente utilizando un generador de números. 
El resultado es un vector que contiene los números del 1 al tamaño especificado, pero en un orden aleatorio.

-randomWithDuplicatesModeFill(): genera y devuelve un vector de enteros con elementos aleatorios dentro de un rango específico dado los parámetros recibidos.

-orderedModeFill(): crea y devuelve un vector de enteros que contiene números enteros consecutivos desde 1 hasta el número especificado por el parámetro recibido.

-inverselyOrderedModeFill(): crea y devuelve un vector de enteros que contiene números enteros en orden descendente desde el tamaño especificado hasta 1.


-->> FUNCIONES DE ALGORITMOS DE ORDENAMIENTO 

-selectionSort(): utiliza un bucle para iterar a través de cada elemento del vector (i desde 0 hasta n-1). Dentro del bucle externo, hay otro bucle que compara 
el elemento actual (arr[i]) con los elementos restantes del vector (arr[j] desde i hasta n-1). Si encuentra un elemento menor que el elemento actual (arr[j] < arr[i]), 
intercambia los elementos.

-bubbleSort(): se inicializa el bool swapped que se utilizará para verificar si se ha realizado algún intercambio durante una iteración del bucle. Luego, Se utiliza un bucle 
para recorrer la lista desde el primer elemento hasta el penúltimo (i va desde 0 hasta n - 2). Se utiliza otro bucle interno para comparar elementos adyacentes y realizar 
intercambios si es necesario. Si un elemento es mayor que el siguiente, se intercambian. Se actualiza swapped si se realiza algún intercambio en el bucle interno.
Después de cada iteración del bucle externo, se verifica si se ha realizado algún intercambio en la iteración completa. Si no se ha realizado ningún intercambio, el vector 
ya está ordenado y el bucle se rompe.

-insertionSort(): recorre el vector desde el segundo elemento hasta el último. En cada iteración, toma un elemento (key) y lo compara con los elementos a su izquierda. 
Se desplazan los elementos mayores a la derecha para hacer espacio y finalmente se coloca el elemento key en su posición correcta.

-shellSort(): versión mejorada de insertionSort(). Itera a través de una serie de brechas (gap) para comparar y ordenar elementos en distancias mayores entre sí.
Para cada brecha, realiza un pase sobre el vector y realiza comparaciones e intercambios utilizando un algoritmo de inserción modificado.

-mergeSort(): divide el vector en dos mitades hasta que el tamaño de cada subvector es 1 o 0. Luego, llama recursivamente a mergeSort en ambas mitades, entonces, combina 
las mitades ordenadas utilizando la función merge.
-merge(): combina dos subvectores ordenados en un solo vector ordenado. Calcula el tamaño de los dos subvectores: leftArray y rightArray. Llena estos subvectores con los 
elementos correspondientes del vector original. Luego, compara los elementos de los dos subvectores y fusiona en orden en el vector original (arr).
Los bucles finales manejan los casos en que quedan elementos en uno de los subvectores después de que el otro se ha agotado.

-quickSort(): utiliza un stack para simular la recursión dado que de otro modo generaba errores de excepción. Se recibe el arreglo y el índice bajo y alto del rango actual que se 
está ordenando. La función partition se llama para obtener el índice del pivote y luego se empujan los subarreglos resultantes en la pila para ordenarlos posteriormente.
-partition(): realiza la partición de un subarreglo en torno a un pivote. Elige el último elemento (arr[high]) como pivote. Luego, reorganiza los elementos en el subarreglo de 
manera que los elementos menores que el pivote estén a la izquierda y los mayores estén a la derecha. Finalmente, devuelve el índice final del pivote después de la partición.
-swap(): intercambia los valores de dos variables enteras. Toma como parámetros dos referencias a enteros (a y b). Esto se utiliza en la función partition para intercambiar 
elementos en el vector durante el proceso de partición.

-heapSort(): primero, construye un montículo (heap) a partir del vector. Luego, extrae el elemento máximo y lo coloca al final del vector. Se vuelve a ajustar el montículo para 
mantener sus propiedades. Entonces, se repite este proceso hasta que todo el vector esté ordenado.
-heapify(): inicializa largest con el índice actual (i). Calcula los índices izquierdo (left) y derecho (right) del elemento actual. Compara el valor y actualiza largest si es necesario.
Si largest no es igual al índice actual (i), intercambia los valores y llama recursivamente a heapify. La función heapSort llama a heapify para construir el montículo y para ajustarlo 
después de extraer el elemento máximo.


-->> OTRAS FUNCIONES

-getRandom(): genera y devuelve un número entero aleatorio dentro de un rango especificado por los parámetros recibidos.

-initRace(): recibe un arreglo de vectores (cola, objeto o evento) y un vector auxiliar para realizar el ordenamiento con cada algoritmo. 
Se crea un arreglo tipo double para almacenar en cada espacio de este el tiempo de ejecución para cada algoritmo. Luego, se calcula el tiempo más rápido 
ejecutado por los algoritmos y se obtiene su índice dentro del arreglo donde se guardaron los tiempos. Finalmente se imprime el ganador.

