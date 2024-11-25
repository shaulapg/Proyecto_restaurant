/**Proyecto: Restaurant
 * Nombre: Shaula Suhail Paz Garay
 * Matricula: A01712013
 * Fecha: 18 de septiembre de 2024
 */

#ifndef ALIMENTOS_H
#define ALIMENTOS_H

//Librerias
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
class Ali{
    //Atributos protegidos
    protected:
    std::string nombre, tipo, extra;
    int vendidas, compradas;
    float precio;

    //Atributos Públicos
    public:
    //Construtor default
    Ali(): nombre(""), vendidas(0), precio(0), tipo(""), extra(""){};
    //Constructor con parametros definidos
    Ali(std::string nom, int vend, float prec, std::string tip, std::string extr):nombre(nom), vendidas(vend), precio(prec), tipo(tip), extra(extr){};

    std::string get_nombre();
    int get_vendidas();
    float get_precio();
    std::string get_tipo();
    std::string get_extra();

    /**Leer archivo CSV
     * 
     * @param archivo a leer, numero de lineas registradas
     * @return nombre
     */
    static Ali* leerCSV(const std::string& archivo, int& size) {
    std::ifstream file(archivo);
    std::string linea, vendStr, precStr;
    //Comprobar que se puede abrir
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo.\n";
        size = 0;
        return nullptr;
    }
    //Contar las líneas del archivo
    size = 0;
    while (std::getline(file, linea)) {
        size++;
    }
    //Reiniciar en archivo
    file.clear();
    file.seekg(0);
    //Arreglo con el número de los objetos leídos
    Ali* alimento = new Ali[size];

    //Leer objetos
    int i = 0;
    while (std::getline(file, linea)) {
        std::stringstream ss(linea);
        Ali p;
        //Leer características del alimento
        std::getline(ss, p.nombre, ',');
        std::getline(ss, vendStr, ',');
        std::getline(ss, precStr, ',');
        std::getline(ss, p.tipo, ',');
        std::getline(ss, p.extra, ',');
        p.vendidas = std::stoi(vendStr);
        p.precio = std::stoi(precStr);
        //Agregar al arreglo
        alimento[i] = p;
        i++;
    }
    //Fin - Cerrar archivo
    file.close();
    return alimento;
}

/**Formato para CSV
 * 
 * @param
 * @return string de nombre, vendidas, precio, tipo, extra
 */
std::string toCSV() const {
        return nombre + "," + std::to_string(vendidas) + "," + std::to_string(precio) + "," + tipo + "," + extra;
}

/**Escribir en CSV
 * 
 * @param archivo, objeto de alimentos
 * @return
 */
void writeToCSV(const std::string& csv, Ali* alimen) {
    std::ofstream file(csv, std::ios::app);
    if (file.is_open()) {
        file << alimen->toCSV() << std::endl;
        file.close();
    } else
        std::cerr << "Error al abrir el archivo" << std::endl;
}
};

/**getter de nombre
 * 
 * @param
 * @return nombre
 */
std::string Ali::get_nombre(){
    return nombre;
}

/**getter cantidad de ventas
 * 
 * @param
 * @return ventas
 */
int Ali::get_vendidas(){
    return vendidas;
}

/**getter de precio
 * 
 * @param
 * @return precio
 */
float Ali::get_precio(){
    return precio;
}

/**getter de tipo de alimento
 * 
 * @param
 * @return tipo de alimento
 */
std::string Ali::get_tipo(){
    return tipo;
}

std::string Ali::get_extra(){
    return extra;
}

//Clase Alimentos
class Alimentos{
    //Atributos protegidos
    protected:
    std::string nombre, tipo, extra;
    int vendidas, compradas;
    float precio;

    //Atributos Públicos
    public:
    //Construtor default
    Alimentos(): nombre(""), vendidas(0), precio(0), tipo(""){};
    //Constructor con parametros definidos
    Alimentos(std::string nom, int vend, float prec, std::string tip):nombre(nom), vendidas(vend), precio(prec), tipo(tip){};

    //getters y setters
    std::string get_nombre();
    int get_vendidas();
    float get_precio();
    std::string get_tipo();

    virtual void imprime() = 0;
};

/**getter de nombre
 * 
 * @param
 * @return nombre
 */
std::string Alimentos::get_nombre(){
    return nombre;
}

/**getter cantidad de ventas
 * 
 * @param
 * @return ventas
 */
int Alimentos::get_vendidas(){
    return vendidas;
}

/**getter de precio
 * 
 * @param
 * @return precio
 */
float Alimentos::get_precio(){
    return precio;
}

/**getter de tipo de alimento
 * 
 * @param
 * @return tipo de alimento
 */
std::string Alimentos::get_tipo(){
    return tipo;
}



//Clase Bebidas
class Bebidas : public Alimentos{
    //Atributos protegidos
    protected:
    std::string temperatura;

    //Atributos publicos
    public:
    //Constructor default
    Bebidas(): Alimentos(), temperatura(""){};
    //Constructor con parametros
    Bebidas(std::string nom, int vend, float prec, std::string tip, std::string temp): Alimentos(nom, vend, prec, tip), temperatura(temp){}; 

    /**getter de temperatura
     * 
     * @param
     * @return temperatura
     */
    std::string get_temperatura(){
        return temperatura;
    }
    
    //funcion para imprimir
    void imprime();
};

/**funcion para imprimir
 * 
 * @param
 * @return
 */
void Bebidas::imprime(){
    std::cout << "|Nombre: " << nombre << std::endl;
    std::cout << "|Vendidos: " << vendidas << std::endl;
    std::cout << "|Precio: " << precio << std::endl;
    std::cout << "|Temperatura: " << temperatura << std::endl;
    std::cout << std::endl;
}



//Clase Alimentos
class Postres : public Alimentos{
    //Atributos protegidos
    protected:
    std::string sabor;

    //Atributos publicos
    public:
    //Constructor default
    Postres(): Alimentos(), sabor(""){};
    //Constructor con parametros
    Postres(std::string nom, int vend, float prec, std::string tip, std::string sab): Alimentos(nom, vend, prec, tip), sabor(sab){}; 

    /**getter de sabor
     * 
     * @param
     * @return sabor
     */
    std::string get_sabor(){
        return sabor;
    }

    //funcion para imprimir
    void imprime();
};

/**funcion para imprimir
 * 
 * @param
 * @return
 */
void Postres::imprime(){
    std::cout << "|Nombre: " << nombre << std::endl;
    std::cout << "|Vendidos: " << vendidas << std::endl;
    std::cout << "|Precio: " << precio << std::endl;
    std::cout << "|Sabor: " << sabor << std::endl;
    std::cout << std::endl;
}



//Clase Alimentos
class Comidas : public Alimentos{
    //Atributos Protegidos
    protected:
    std::string ingredientes;

    //Atributos publicos
    public:
    //Constructor default
    Comidas(): Alimentos(), ingredientes(""){};
    //Constructor con parametros
    Comidas(std::string nom, int vend, float prec, std::string tip, std::string ing): Alimentos(nom, vend, prec, tip), ingredientes(ing){}; 

    /**getter de ingredientes
     * 
     * @param
     * @return ingredientes
     */
    std::string get_ingredientes(){
        return ingredientes;
    }

    //funcion para imprimir
    void imprime();
};

/**funcion para imprimir
 * 
 * @param
 * @return
 */
void Comidas::imprime(){
    std::cout << "|Nombre: " << nombre << std::endl;
    std::cout << "|Vendidos: " << vendidas << std::endl;
    std::cout << "|Precio: " << precio << std::endl;
    std::cout << "|Ingredientes: " << ingredientes << std::endl;
    std::cout << std::endl;
}

#endif