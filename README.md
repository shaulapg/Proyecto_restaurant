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

  # Versiones
  Version 1: se agregaron clases: menu, alimentos, comidas, bebidas y postres. Se agregó main con opciones para visualizacion del menu, usando ordenamiento tipo Bubble (SICT0302: Toma decisiones). Complejidad en comentarios de bubbleSort [sorts.h] (SICT0301: Evalúa los componentes)
