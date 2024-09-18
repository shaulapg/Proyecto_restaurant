/**Proyecto: Restaurant
 * Nombre: Shaula Suhail Paz Garay
 * Matricula: A01712013
 * Fecha: 18 de septiembre de 2024
 */

#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include <vector>

#include "alimentos.h"

int contador = 0;
class Menu{
    public:
    Alimentos * alim[50];
    std::vector <float> precios;
    std::vector <int> ventas;
    std::vector <float> precios_b;
    std::vector <int> ventas_b;
    std::vector <float> precios_c;
    std::vector <int> ventas_c;
    std::vector <float> precios_p;
    std::vector <int> ventas_p;

    Menu(){};

    void agrega_alimento(Alimentos *);
    void imprime_();
};

void Menu::agrega_alimento(Alimentos * objeto){
    if(contador < 50){
        alim[contador] = objeto;
        precios.push_back(objeto->get_precio());
        ventas.push_back(objeto->get_vendidas());

        if(objeto->get_tipo() == "Bebidas"){
            precios_b.push_back(objeto->get_precio());
            ventas_b.push_back(objeto->get_vendidas());
        }else if(objeto->get_tipo() == "Comidas"){
            precios_c.push_back(objeto->get_precio());
            ventas_c.push_back(objeto->get_vendidas());
        } else if(objeto->get_tipo() == "Postres"){
            precios_p.push_back(objeto->get_precio());
            ventas_p.push_back(objeto->get_vendidas());
        }
        contador++;
    }
}

void Menu::imprime_(){
    for (int i = 0; i < contador; i++){
        alim[i] -> imprime();
    }
}

#endif