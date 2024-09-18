/**Proyecto: Restaurant
 * Nombre: Shaula Suhail Paz Garay
 * Matricula: A01712013
 * Fecha: 18 de septiembre de 2024
 */

#ifndef ALIMENTOS_H
#define ALIMENTOS_H

#include <string>
#include <iostream>

class Alimentos{
    protected:
    std::string nombre, tipo;
    int vendidas, compradas;
    float precio;

    public:
    Alimentos(): nombre(""), vendidas(0), precio(0), tipo(""){};
    Alimentos(std::string nom, int vend, float prec, std::string tip):nombre(nom), vendidas(vend), precio(prec), tipo(tip){};

    std::string get_nombre();
    int get_vendidas();
    float get_precio();
    std::string get_tipo();

    void aumenta_vendidas(int);
    virtual void imprime() = 0;
};

std::string Alimentos::get_nombre(){
    return nombre;
}

int Alimentos::get_vendidas(){
    return vendidas;
}

float Alimentos::get_precio(){
    return precio;
}

std::string Alimentos::get_tipo(){
    return tipo;
}

void Alimentos::aumenta_vendidas(int vend){
    vendidas = vend;
}



class Bebidas : public Alimentos{
    protected:
    std::string temperatura;

    public:
    Bebidas(): Alimentos(), temperatura(""){};
    Bebidas(std::string nom, int vend, float prec, std::string tip, std::string temp): Alimentos(nom, vend, prec, tip), temperatura(temp){}; 

    std::string get_temperatura(){
        return temperatura;
    }
    void imprime();
};

void Bebidas::imprime(){
    std::cout << "|Nombre: " << nombre << std::endl;
    std::cout << "|Vendidos: " << vendidas << std::endl;
    std::cout << "|Precio: " << precio << std::endl;
    std::cout << "|Temperatura: " << temperatura << std::endl;
    std::cout << std::endl;
}



class Postres : public Alimentos{
    protected:
    std::string sabor;

    public:
    Postres(): Alimentos(), sabor(""){};
    Postres(std::string nom, int vend, float prec, std::string tip, std::string sab): Alimentos(nom, vend, prec, tip), sabor(sab){}; 

    std::string get_sabor(){
        return sabor;
    }
    void imprime();
};

void Postres::imprime(){
    std::cout << "|Nombre: " << nombre << std::endl;
    std::cout << "|Vendidos: " << vendidas << std::endl;
    std::cout << "|Precio: " << precio << std::endl;
    std::cout << "|Sabor: " << sabor << std::endl;
    std::cout << std::endl;
}



class Comidas : public Alimentos{
    protected:
    std::string ingredientes;

    public:
    Comidas(): Alimentos(), ingredientes(""){};
    Comidas(std::string nom, int vend, float prec, std::string tip, std::string ing): Alimentos(nom, vend, prec, tip), ingredientes(ing){}; 

    std::string get_ingredientes(){
        return ingredientes;
    }
    void imprime();
};

void Comidas::imprime(){
    std::cout << "|Nombre: " << nombre << std::endl;
    std::cout << "|Vendidos: " << vendidas << std::endl;
    std::cout << "|Precio: " << precio << std::endl;
    std::cout << "|Ingredientes: " << ingredientes << std::endl;
    std::cout << std::endl;
}

#endif