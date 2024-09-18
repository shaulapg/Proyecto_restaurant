/**Proyecto: Restaurant
 * Nombre: Shaula Suhail Paz Garay
 * Matricula: A01712013
 * Fecha: 18 de septiembre de 2024
 */

#include "sorts.h"
#include "alimentos.h"
#include "menu.h"

std::string nom, ext;
bool continua = true;
int opcion, op, ven;
float prec;

Sorts<int> sorts;
Sorts<float> fsorts;

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

main(){
    
    Menu menu;

    Alimentos * limonada = new Bebidas("Limonada", 10, 25.00, "Bebidas", "Fria");
    Alimentos * malteada = new Bebidas("Malteada", 15, 49.99, "Bebidas", "Fria");
    Alimentos * jamaica = new Bebidas("Jamaica", 8, 20.00, "Bebidas", "Fria");
    Alimentos * horchata = new Bebidas("Horchata", 7, 19.99, "Bebidas", "Fria");
    Alimentos * agua = new Bebidas("Agua", 5, 10.00, "Bebidas", "Al Tiempo");
    
    menu.agrega_alimento(limonada);
    menu.agrega_alimento(malteada);
    menu.agrega_alimento(jamaica);
    menu.agrega_alimento(horchata);
    menu.agrega_alimento(agua);



    Alimentos * sopa = new Comidas("Sopa", 4, 40.00, "Comidas", "Pollo, Puerco, Azteca");
    Alimentos * milanesa = new Comidas("Milanesa", 3, 35.00, "Comidas","Pollo, Pescado");
    Alimentos * torta = new Comidas("Torta", 1, 28.00, "Comidas","Jamon, Pambazo, Guajolota");
    Alimentos * tacos = new Comidas("Tacos", 24, 8.00, "Comidas","Barbacoa, Pastor, Tripa");
    Alimentos * hamburguesa = new Comidas("Hamburguesa", 6, 30.00, "Comidas","N/A");
    
    menu.agrega_alimento(sopa);
    menu.agrega_alimento(milanesa);
    menu.agrega_alimento(torta);
    menu.agrega_alimento(tacos);
    menu.agrega_alimento(hamburguesa);


    Alimentos * helado = new Postres("Helado", 0, 22.00, "Postres", "Chocolate, Fresa, Vainilla");
    Alimentos * pay = new Postres("Pay", 4, 21.00, "Postres","Limon, Frutos Rojos, Zarzamora");
    Alimentos * pastel = new Postres("Rebanada de pastel", 11, 22.00, "Postres","Chocolate, Tres Leches, Cajeta");
    Alimentos * churros = new Postres("Churros", 12, 26.00, "Postres","Natural");
    Alimentos * bunuelos = new Postres("Bunuelos", 7, 15.00, "Postres","Natural");

    menu.agrega_alimento(helado);
    menu.agrega_alimento(pay);
    menu.agrega_alimento(pastel);
    menu.agrega_alimento(churros);
    menu.agrega_alimento(bunuelos);


    std::vector <int> v = sorts.bubbleSort(menu.ventas);
    std::vector <float> p = fsorts.bubbleSort(menu.precios);


    while (continua == true){
        std::cout << std::endl;
        std::cout << "Menu principal" << std::endl;
        std::cout << "1. Mostrar Menu" << std::endl;
        std::cout << "2. Agregar Alimento" << std::endl;
        std::cout << "3. Mostrar por ventas" << std::endl;
        std::cout << "4. Mostrar por precio" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cout << std::endl;

        switch(opcion){
            case 1:
                menu.imprime_();
            break;
            case 2:
                op = ordenapor();

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
                    menu.agrega_alimento(aux);
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
                    menu.agrega_alimento(aux);
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
                    menu.agrega_alimento(aux);
                } else
                    std::cout << "Opcion invalida";
            break;
            case 3:
                op = ordenapor();

                if(op == 1){
                    for(int i = 0; i < v.size(); i++)
                        for(int j = 0; j < contador; j++)
                            if(v[i - 1] != v[i] && v[i] == menu.alim[j]->get_vendidas())
                                menu.alim[j]->imprime();
                } else if(op == 2){
                    for(int i = 0; i < v.size(); i++)
                        for(int j = 0; j < contador; j++)
                            if(v[i - 1] != v[i] && v[i] == menu.alim[j]->get_vendidas() && menu.alim[j]->get_tipo() == "Bebidas")
                                menu.alim[j]->imprime();
                } else if(op == 3){
                    for(int i = 0; i < v.size(); i++)
                        for(int j = 0; j < contador; j++)
                            if(v[i - 1] != v[i] && v[i] == menu.alim[j]->get_vendidas() && menu.alim[j]->get_tipo() == "Comidas")
                                menu.alim[j]->imprime();
                } else if(op == 4){
                    for(int i = 0; i < v.size(); i++)
                        for(int j = 0; j < contador; j++)
                            if(v[i - 1] != v[i] && v[i] == menu.alim[j]->get_vendidas() && menu.alim[j]->get_tipo() == "Postres")
                                menu.alim[j]->imprime();
                } else
                    std::cout << "Opcion no valida";
            break;
            case 4:
                op = ordenapor();

                if(op == 1){
                    for(int i = 0; i < p.size(); i++)
                        for(int j = 0; j < contador; j++)
                            if(p[i - 1] != p[i] && p[i] == menu.alim[j]->get_precio())
                                menu.alim[j]->imprime();
                } else if(op == 2){
                    for(int i = 0; i < p.size(); i++)
                        for(int j = 0; j < contador; j++)
                            if(p[i - 1] != p[i] && p[i] == menu.alim[j]->get_precio() && menu.alim[j]->get_tipo() == "Bebidas")
                                menu.alim[j]->imprime();
                } else if(op == 3){
                    for(int i = 0; i < p.size(); i++)
                        for(int j = 0; j < contador; j++)
                            if(p[i - 1] != p[i] && p[i] == menu.alim[j]->get_precio() && menu.alim[j]->get_tipo() == "Comidas")
                                menu.alim[j]->imprime();
                } else if(op == 4){
                    for(int i = 0; i < p.size(); i++)
                        for(int j = 0; j < contador; j++)
                            if(p[i - 1] != p[i] && p[i] == menu.alim[j]->get_precio() && menu.alim[j]->get_tipo() == "Postres")
                                menu.alim[j]->imprime();
                } else
                    std::cout << "Opcion no valida";
            break;
            case 5:
                continua = false;
            break;
            default:
                std::cout << "Opcion no valida";
        }
    }
}