# Proyecto_restaurant
Un restaurante tiene una base de datos de su menu. En este menu se clasifican los alimentos en Bebidas, Comidas y Postres. Las caracterísitcas de estos son nombre, cantidad vendida, precio y una característica especial para cada uno: para bebida es la temperatura, para comida es ingredientes y para los postres es sabor.

# Funcionalidad
El programa permite al usuario elegir entre ver el menu, agregar un alimento y ver los productos acomodados de forma ascendente, ya sea por precio o por unidades vendidas. En esta ultima opcion se puede elegir entre cuatro opciones: ver todos los productos, ver solo postres, comidas o bebidas.

Este programa cuenta con 5 clases, las cuales son:
- Alimentos: calse virtual, clase que hereda a bebidas, comidas y postres
- Comidas, Bebidas y Postres: tipos de objetos disponibles para el menu
- Menu: Clase para acceder a las demás
- 
# Consideraciones
El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos
- compilar con: "g++ alimentos.h sorts.h menu.h main.cpp"
- correr en linux: "/a.out"
- correr en windows: "a.exe
NO SE PUEDE REPETIR UN DATO, ES DECIR, SI YA HAY UN ARTICULO CON PRECIO DE $20, NO SE PUEDE AGREGAR OTRO CON PRECIO DE $20

  # Versiones
Version 1: se agregaron clases: menu, alimentos, comidas, bebidas y postres. Se agregó main con opciones para visualizacion del menu, usando ordenamiento tipo Bubble (SICT0302: Toma decisiones). Complejidad en comentarios de merge sort [sorts.h] (SICT0301: Evalúa los componentes). Se eligió "Merge Sort" por ser una opción eficiente y rápida.

Versión 2: se acualizaron los archivos existentes y se agregaron comentarios. Se agregó "BST" para poder buscar un alimento por precio o cantidad de ventas de manera más eficiente (a comparación de una lista normal) (SICT0302: Toma decisiones). Análisis de BST en comentarios (SICT0301: Evalúa los componentes). Se usan funciones de "add" y "find" para manejar el árbol de manera simple pero adecuada al programa. "find" funciona en el contexto del main, pues despliega un mensaje por si mismo y el main se encarga de desplegar otro si el primero no aparece (SICT0303: Implementa acciones científicas).
