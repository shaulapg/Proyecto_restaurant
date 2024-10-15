/**Proyecto: Restaurant
 * Nombre: Shaula Suhail Paz Garay
 * Matricula: A01712013
 * Fecha: 18 de septiembre de 2024
 */

//Archivos para manejar los alimentos
#include "sorts.h"
#include "alimentos.h"
#include "menu.h"
#include "bst.h"

//Variables
std::string nom, ext, nam;
bool continua = true, enc;
int opcion, op, ven;
float prec, busc;

//Sorts para enteros y floats
Sorts<int> sorts;
Sorts<float> fsorts;

/**Menu para elegir el orden
 * 
 * @param
 * @return seleccion del usuario
 */
int ordenapor(){
    int op;
    std::cout << "Seccion" << std::endl;
    std::cout << "1. Todas" << std::endl;
    std::cout << "2. Bebidas" << std::endl;
    std::cout << "3. Comidas" << std::endl;
    std::cout << "4. Postres" << std::endl;
    std::cout << "Seleccione una opcion: ";
    std::cin >> op;
    std::cout << std::endl;

    return op;
}

//Inicio del main
int main(){
    
    //Objeto menu para manejo del restaurant
    Menu menu;
    //BST para ventas y precios
    BST<int> vbst;
    BST<float> pbst;

    //Creador de apuntadores para bebidas
    Alimentos * limonada = new Bebidas("Limonada", 10, 25.00, "Bebidas", "Fria");
    Alimentos * malteada = new Bebidas("Malteada", 15, 50.00, "Bebidas", "Fria");
    Alimentos * jamaica = new Bebidas("Jamaica", 8, 26.00, "Bebidas", "Fria");
    Alimentos * horchata = new Bebidas("Horchata", 7, 27.00, "Bebidas", "Fria");
    Alimentos * agua = new Bebidas("Agua", 5, 10.00, "Bebidas", "Al Tiempo");
    
    //Agregar apuntadores a la lista
    menu.agrega_alimento(limonada);
    menu.agrega_alimento(malteada);
    menu.agrega_alimento(jamaica);
    menu.agrega_alimento(horchata);
    menu.agrega_alimento(agua);

    //Agregar bebidas a la lista de vendidos (BST)
    vbst.add("Limonada", limonada->get_vendidas());
    vbst.add("Malteada", malteada->get_vendidas());
    vbst.add("Jamaica", jamaica->get_vendidas());
    vbst.add("Horchata", horchata->get_vendidas());
    vbst.add("Agua", agua->get_vendidas());

    //Agregar bebidas a la lista de precios (BST)
    pbst.add("Limonada", limonada->get_precio());
    pbst.add("Malteada", malteada->get_precio());
    pbst.add("Jamaica", jamaica->get_precio());
    pbst.add("Horchara", horchata->get_precio());
    pbst.add("Agua", agua->get_precio());



    //Creador de apuntadores para comidas
    Alimentos * sopa = new Comidas("Sopa", 2, 40.00, "Comidas", "Pollo, Puerco, Azteca");
    Alimentos * milanesa = new Comidas("Milanesa", 3, 35.00, "Comidas","Pollo, Pescado");
    Alimentos * torta = new Comidas("Torta", 1, 28.00, "Comidas","Jamon, Pambazo, Guajolota");
    Alimentos * tacos = new Comidas("Tacos", 24, 8.00, "Comidas","Barbacoa, Pastor, Tripa");
    Alimentos * hamburguesa = new Comidas("Hamburguesa", 6, 30.00, "Comidas","N/A");
    
    //Agregar apuntadores a la lista
    menu.agrega_alimento(sopa);
    menu.agrega_alimento(milanesa);
    menu.agrega_alimento(torta);
    menu.agrega_alimento(tacos);
    menu.agrega_alimento(hamburguesa);

    //Agregar comidas a la lista de vendidos (BST)
    vbst.add("Sopa", sopa->get_vendidas());
    vbst.add("Milanesa", milanesa->get_vendidas());
    vbst.add("Torta", torta->get_vendidas());
    vbst.add("Tacos", tacos->get_vendidas());
    vbst.add("Hamburguesa", hamburguesa->get_vendidas());

    //Agregar comidas a la lista de precios (BST)
    pbst.add("Sopa", sopa->get_precio());
    pbst.add("Milanesa", milanesa->get_precio());
    pbst.add("Torta", torta->get_precio());
    pbst.add("Tacos", tacos->get_precio());
    pbst.add("Hamburguesa", hamburguesa->get_precio());



    //Creador de apuntadores para postres
    Alimentos * helado = new Postres("Helado", 0, 22.00, "Postres", "Chocolate, Fresa, Vainilla");
    Alimentos * pay = new Postres("Pay", 4, 21.00, "Postres","Limon, Frutos Rojos, Zarzamora");
    Alimentos * pastel = new Postres("Rebanada de pastel", 11, 20.00, "Postres","Chocolate, Tres Leches, Cajeta");
    Alimentos * churros = new Postres("Churros", 12, 29.00, "Postres","Natural");
    Alimentos * bunuelos = new Postres("Bunuelos", 5, 15.00, "Postres","Natural");

    //Agregar apuntadores a la lista
    menu.agrega_alimento(helado);
    menu.agrega_alimento(pay);
    menu.agrega_alimento(pastel);
    menu.agrega_alimento(churros);
    menu.agrega_alimento(bunuelos);

    //Agregar postres a la lista de vendidos (BST)
    vbst.add("Helado", helado->get_vendidas());
    vbst.add("Pay", pay->get_vendidas());
    vbst.add("Pastel", pastel->get_vendidas());
    vbst.add("Churros", churros->get_vendidas());
    vbst.add("Bunuelos", bunuelos->get_vendidas());

    //Agregar postres a la lista de precios (BST)
    pbst.add("Helado", helado->get_precio());
    pbst.add("Pay", pay->get_precio());
    pbst.add("Pastel", pastel->get_precio());
    pbst.add("Churros", churros->get_precio());
    pbst.add("Bunuelos", bunuelos->get_precio());


    //Vector ordenado de ventas
    std::vector <int> v = sorts.mergeSort(menu.ventas);
    //Vector ordenado de precios
    std::vector <float> p = fsorts.mergeSort(menu.precios);


    //While para continuar hasta que el usuario decida salir
    while (continua == true){
        std::cout << std::endl;
        //Menu principal
        std::cout << "Menu principal" << std::endl;
        std::cout << "1. Mostrar Menu" << std::endl;
        std::cout << "2. Agregar Alimento" << std::endl;
        std::cout << "3. Mostrar por ventas" << std::endl;
        std::cout << "4. Mostrar por precio" << std::endl;
        std::cout << "5. Buscar precio" << std::endl;
        std::cout << "6. Buscar ventas" << std::endl;
        std::cout << "7. Salir" << std::endl;
        //Seleccion de opcion del menu principal
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cout << std::endl;

        //Switch para llevar al usuario a la opcion seleccionada
        switch(opcion){
            case 1:
                //Mostrar menu (alimentos disponibles)
                menu.imprime_();
            break;
            case 2:
                //Menu para elegir que agregar
                op = ordenapor();

                //Tomar datos para agregar Bebida
                if (op == 1){
                    std::cout << "Nombre del alimento: ";
                    std::cin >> nom;
                    std::cout << "Vendidos hasta el momento: ";
                    std::cin >> ven;
                    std::cout << "Precio: ";
                    std::cin >> prec;
                    std::cout << "Temperatura: ";
                    std::cin >> ext;
                    Alimentos * aux  = new Bebidas(nom, ven, prec, "Bebidas", ext);
                    //Agregar el bebida al menu, lista de venta y lista de compras
                    menu.agrega_alimento(aux);
                    vbst.add(nom, ven);
                    pbst.add(nom, prec);
                //Tomar datos para agregar Comida
                } else if (op == 2){
                    std::cout << "Nombre del alimento: ";
                    std::cin >> nom;
                    std::cout << "Vendidos hasta el momento: ";
                    std::cin >> ven;
                    std::cout << "Precio: ";
                    std::cin >> prec;
                    std::cout << "Tipos: ";
                    std::cin >> ext;
                    Alimentos * aux  = new Comidas(nom, ven, prec, "Comidas", ext);
                    //Agregar el comida al menu, lista de venta y lista de compras
                    menu.agrega_alimento(aux);
                    vbst.add(nom, ven);
                    pbst.add(nom, prec);
                //Tomar datos para agregar Postre
                } else if (op == 3){
                    std::cout << "Nombre del alimento: ";
                    std::cin >> nom;
                    std::cout << "Vendidos hasta el momento: ";
                    std::cin >> ven;
                    std::cout << "Precio: ";
                    std::cin >> prec;
                    std::cout << "Sabores: ";
                    std::cin >> ext;
                    Alimentos * aux  = new Postres(nom, ven, prec, "Postres", ext);
                    //Agregar el postre al menu, lista de venta y lista de compras
                    menu.agrega_alimento(aux);
                    vbst.add(nom, ven);
                    pbst.add(nom, prec);
                //Default para opcion invalida
                } else
                    std::cout << "Opcion invalida";
            break;
            case 3:
                //Elegir como mostrar las ventas
                op = ordenapor();

                //Opcion para ver todos los alimentos
                if(op == 1){
                    //Bucles para recorrer todo el vector
                    for(int i = 0; i < v.size(); i++)
                        for(int j = 0; j < contador; j++)
                            //Condicional para ver el objeto
                            if(v[i - 1] != v[i] && v[i] == menu.alim[j]->get_vendidas())
                                menu.alim[j]->imprime();
                //Opcion para ver las bebidas
                } else if(op == 2){
                    //Bucles para recorrer todo el vector
                    for(int i = 0; i < v.size(); i++)
                        for(int j = 0; j < contador; j++)
                            //Condicional para ver el objeto si este es una bebida
                            if(v[i - 1] != v[i] && v[i] == menu.alim[j]->get_vendidas() && menu.alim[j]->get_tipo() == "Bebidas")
                                menu.alim[j]->imprime();
                //Opcion para ver las comidas
                } else if(op == 3){
                    //Bucles para recorrer todo el vector
                    for(int i = 0; i < v.size(); i++)
                        for(int j = 0; j < contador; j++)
                        //Condicional para ver el objeto si este es una comida
                            if(v[i - 1] != v[i] && v[i] == menu.alim[j]->get_vendidas() && menu.alim[j]->get_tipo() == "Comidas")
                                menu.alim[j]->imprime();
                //Opcion para ver los postres
                } else if(op == 4){
                    //Bucles para recorrer todo el vector
                    for(int i = 0; i < v.size(); i++)
                        for(int j = 0; j < contador; j++)
                            //Condicional para ver el objeto si este es un postre
                            if(v[i - 1] != v[i] && v[i] == menu.alim[j]->get_vendidas() && menu.alim[j]->get_tipo() == "Postres")
                                menu.alim[j]->imprime();
                //Default para opcion invalida
                } else
                    std::cout << "Opcion no valida";
            break;
            case 4:
                //Elegir como mostrar los precios
                op = ordenapor();

                //Opcion para ver todos los alimentos
                if(op == 1){
                    //Bucles para recorrer todo el vector
                    for(int i = 0; i < p.size(); i++)
                        for(int j = 0; j < contador; j++)
                            //Condicional para ver el objeto
                            if(p[i - 1] != p[i] && p[i] == menu.alim[j]->get_precio())
                                menu.alim[j]->imprime();
                //Opcion para ver las bebidas
                } else if(op == 2){
                    //Bucles para recorrer todo el vector
                    for(int i = 0; i < p.size(); i++)
                        for(int j = 0; j < contador; j++)
                            //Condicional para ver el objeto si este es una bebida
                            if(p[i - 1] != p[i] && p[i] == menu.alim[j]->get_precio() && menu.alim[j]->get_tipo() == "Bebidas")
                                menu.alim[j]->imprime();
                //Opcion para ver las comidas
                } else if(op == 3){
                    //Bucles para recorrer todo el vector
                    for(int i = 0; i < p.size(); i++)
                        for(int j = 0; j < contador; j++)
                            //Condicional para ver el objeto si este es una comida
                            if(p[i - 1] != p[i] && p[i] == menu.alim[j]->get_precio() && menu.alim[j]->get_tipo() == "Comidas")
                                menu.alim[j]->imprime();
                //Opcion para ver los postres
                } else if(op == 4){
                    //Bucles para recorrer todo el vector
                    for(int i = 0; i < p.size(); i++)
                        for(int j = 0; j < contador; j++)
                            //Condicional para ver el objeto si este es un postre
                            if(p[i - 1] != p[i] && p[i] == menu.alim[j]->get_precio() && menu.alim[j]->get_tipo() == "Postres")
                                menu.alim[j]->imprime();
                //Default para opcion invalida
                } else
                    std::cout << "Opcion no valida";
            break;
            //Opcion para buscar un alimento por su precio
            case 5:
                //Ingresar el precio para buscar el alimento
                std::cout << "Inserte el precio a buscar: ";
                std::cin >> busc;
                //Comprobar si el articulo existe
                if (!pbst.find(busc))
                    std::cout << "El articulo no existe" << std::endl;
            break;
            //Opcion para buscar un alimento por sus ventas
            case 6:
                //Ingresar las ventas para buscar el alimento
                std::cout << "Inserte las ventas a buscar: ";
                std::cin >> busc;
                //Comprobar si el articulo existe
                if (!vbst.find(busc))
                    std::cout << "El articulo no existe" << std::endl;
            break;
            //Opcion para salir
            case 7:
                continua = false;
            break;
            //Caso default para opcion invalida
            default:
                std::cout << "Opcion no valida";
        }
    }
    
    return 0;
}