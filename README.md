# Proyecto_restaurant
Un restaurante tiene una base de datos de su menu. En este menu se clasifican los alimentos en Bebidas, Comidas y Postres. Las caracterísitcas de estos son nombre, cantidad vendida, precio y una característica especial para cada uno: para bebida es la temperatura, para comida es ingredientes y para los postres es sabor.

# Funcionalidad
El programa permite al usuario elegir entre ver el menu, agregar un alimento y ver los productos acomodados de forma ascendente, ya sea por precio o por unidades vendidas. En esta ultima opcion se puede elegir entre cuatro opciones: ver todos los productos, ver solo postres, comidas o bebidas.

Este programa cuenta con 8 clases, las cuales son:
- Ali: Clase igual a Alimentos pero con funciones para importar datos del CSV
- Alimentos: calse virtual, clase que hereda a bebidas, comidas y postres
- Comidas, Bebidas y Postres: tipos de objetos disponibles para el menu
- Menu: Clase para acceder a las demás
- Sorts: Clase con merge sort para poder ordenar datos
- BST: Para generar arreglos y buscar información de manera óptima

También cuenta con
 - Base de datos CSV con los alimentos disponibles con capacidad de agregar más permanentemente
 - Main para correr el programa
  
# Consideraciones
El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos
- compilar con: "g++ alimentos.h sorts.h menu.h main.cpp"
- correr en linux: "/a.out"
- correr en windows: "a.exe

# Usos:
Merge sort: Dos sorts, uno para buscar un elemento por precio y otro para buscarlo por ventas (opción 5 y 6 del menú)
BST: Dos Árboles para mostrar elementos, uno por precio y otro por ventas (opción 3 y 4 del menú)

# Complejidad

MERGE SORT
Complejidad Espacial: O(n)
Complejidad Temporal:
 * 		Mejor: Ω(n log(n))
 * 		Promedio: Θ(n log(n))
 * 		Peor: O(n log(n))

BST
Complejidad Espacial O(n)
Complejidad Temporal:
   Promedio:
 * 		Acceso: Θ(log(n))
 * 		Busqueda: Θ(log(n))
 * 		Insercion: Θ(log(n))
   Peor:
 * 		Acceso: O(n)
 * 		Busqueda: O(n)
 * 		Insercion: O(n)

  # Versiones
Version 1: se agregaron clases: menu, alimentos, comidas, bebidas y postres. Se agregó main con opciones para visualizacion del menu, usando ordenamiento tipo Bubble (SICT0302: Toma decisiones). Complejidad en comentarios de merge sort [sorts.h] (SICT0301: Evalúa los componentes). Se eligió "Merge Sort" por ser una opción eficiente y rápida.

Versión 2: se acualizaron los archivos existentes y se agregaron comentarios. Se agregó "BST" para poder buscar un alimento por precio o cantidad de ventas de manera más eficiente (a comparación de una lista normal) (SICT0302: Toma decisiones). Análisis de BST en comentarios (SICT0301: Evalúa los componentes). Se usan funciones de "add" y "find" para manejar el árbol de manera simple pero adecuada al programa. "find" funciona en el contexto del main, pues despliega un mensaje por si mismo y el main se encarga de desplegar otro si el primero no aparece (SICT0303: Implementa acciones científicas).

Versión 3: se agregó la base de datos en un csv y las funciones necesarias para acceder a este. Se agregan comentarios en el README para indicar el grado de complejidad del proyecto.
