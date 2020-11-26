/**
 * Estructuras de datos
 * Nombre del archivo: clases.h
 * Autores: Carlos Andres Erazo Garzon
 *          Nicolas Gil
 *          Andres Gomez
 * Fecha: 26/10/2020
 * Descripcion: Libreria que lleva el manejo de las clases necesarias.
 * */

#ifndef __CLASES__H__
#define __CLASES__H__

#include <iostream>
#include <utility>
#include <map>
#include <vector> 
using namespace std;

/**
 * *************
 * CLASE AGENCIA
 * *************
 * */

class Agencia
{
private:
    string agencyName;
    string agencyPass;

public:
    //Constructores
    Agencia(string agencyName, string agencyPass);
    Agencia();

    //Getters & Setters
    string getAgencyName();
    void setAgencyName(string agencyName);
    string getAgencyPass();
    void setAgencyPass(string agencyPass);

    // Imprimir contenido de la clase
    void print();
};

/**
 * *********
 * CLASE BUS
 * *********
 * */

class Bus
{
private:
    string codeBus;
    char type; // c-> current s -> special
    int chairs;

public:
    //Constructores
    Bus(string codeBus, char type, int chairs);
    Bus();

    //Getters & Setters
    string getcodeBus();
    void setcodeBus(string codeBus);
    char getType();
    void setType(char type);
    int getChairs();
    void setChairs(int chairs);

    // Imprimir contenido de la clase
    void print();
};

/**
 * *************
 * CLASE RESERVA
 * *************
 * */

class Reserva
{
private:
    string agency;
    string codeBooking;
    string codeRoute;
    string codeBus;
    string codeTravel; // Si es cancelado se cambia por "VI000"
    int chairNumber;
    string passenger;
    string date;
    string time;
    double chairCost; // Si es cancelado cambia al 15%
public:
    //Constructores
    Reserva(string agency, string codeBooking, string codeRoute, string codeBus,
            string codeTravel, int chairNumber, string passenger, string date,
            string time, double chairCost);
    Reserva();

    //Getters & Setters
    string getAgency();
    void setAgency(string agency);
    string getCodeBooking();
    void setCodeBooking(string codeBooking);
    string getCodeRoute();
    void setCodeRoute(string codeRoute);
    string getCodeBus();
    void setCodeBus(string codeBus);
    string getCodeTravel();
    void setCodeTravel(string codeTravel);
    int getChairNumber();
    void setChairNumber(int chairNumber);
    string getPassenger();
    void setPassenger(string passenger);
    string getDate();
    void setDate(string date);
    string getTime();
    void setTime(string time);
    double getChairCost();
    void setChairCost(double chairCost);

    // Imprimir contenido de la clase
    void print();
};

/**
 * **********
 * CLASE RUTA
 * **********
 * */

class Ruta
{
private:
    string codeRoute;
    string day;
    string cityOrg;
    string cityDst;
    int depTime;
    double kmCity;

public:
    //Constructores
    Ruta(string codeRoute, string day, string cityOrg, string cityDst, int depTime, double kmCity);
    Ruta();

    //Getters & Setters
    string getCodeRoute();
    void setCodeRoute(string codeRoute);
    string getDay();
    void setDay(string day);
    string getCityOrg();
    void setCityOrg(string cityOrg);
    string getCityDst();
    void setCityDst(string cityDst);
    int getDepTime();
    void setDepTime(int depTime);
    double getKmCity();
    void setKmCity(double kmCity);

    // Imprimir contenido de la clase
    void print();
};

/**
 * ***********
 * CLASE VIAJE
 * ***********
 * */

class Viaje
{
private:
    string codeRoute;
    string codeBus;
    string codeTravel;
    string date;
    string time;
    string driverName;
    double chairCost;

public:
    //Constructores
    Viaje(string codeRoute, string codeBus, string codeTravel, string date,
          string time, string driverName, double chairCost);
    Viaje();

    //Getters & Setters
    string getCodeRoute();
    void setCodeRoute(string codeRoute);
    string getCodeBus();
    void setCodeBus(string codeBus);
    string getCodeTravel();
    void setCodeTravel(string codeTravel);
    string getDate();
    void setDate(string date);
    string getDriverName();
    void setDriverName(string driverName);
    double getChairCost();
    void setChairCost(double chairCost);
    void setTime(string time);
    string getTime();

    // Imprimir contenido de la clase
    void print();
};

/**
 * ***************
 * ESTRUCTURA NODO
 * ***************
 * */

struct nodo
{
    char datos;
    int frecuencia;
    nodo *izquierdo;
    nodo *derecho;
    // C o n s t r u c t o r
    nodo(char d, int freq)
    {
        datos = d;
        frecuencia = freq;
        izquierdo = NULL;
        derecho = NULL;
    }

    int numeroHijos();
};

/**
 * ****************
 * ESTRUCTURA TUPLA
 * ****************
 * */

struct tupla
{
    char caracter;
    int frecuencia;
    // C o n s t r u c t o r
    tupla(char d)
    {
        caracter = d;
        frecuencia = 0;
    }
};

/**
 * *******************
 * ESTRUCTURA TABLAHUF
 * *******************
 * */
struct tablahuf
{
    vector<tupla> indice;

    // vector o n s t r u c t o r
    tablahuf()
    {
        indice.push_back(tupla('a'));
        indice.push_back(tupla('b'));
        indice.push_back(tupla('c'));
        indice.push_back(tupla('d'));
        indice.push_back(tupla('e'));
        indice.push_back(tupla('f'));
        indice.push_back(tupla('g'));
        indice.push_back(tupla('h'));
        indice.push_back(tupla('i'));
        indice.push_back(tupla('j'));
        indice.push_back(tupla('k'));
        indice.push_back(tupla('l'));
        indice.push_back(tupla('m'));
        indice.push_back(tupla('n'));
        indice.push_back(tupla('o'));
        indice.push_back(tupla('p'));
        indice.push_back(tupla('q'));
        indice.push_back(tupla('r'));
        indice.push_back(tupla('s'));
        indice.push_back(tupla('t'));
        indice.push_back(tupla('u'));
        indice.push_back(tupla('v'));
        indice.push_back(tupla('w'));
        indice.push_back(tupla('x'));
        indice.push_back(tupla('y'));
        indice.push_back(tupla('z'));
        indice.push_back(tupla('|'));
        indice.push_back(tupla('A')); //27
        indice.push_back(tupla('B'));
        indice.push_back(tupla('C'));
        indice.push_back(tupla('D'));
        indice.push_back(tupla('E'));
        indice.push_back(tupla('F'));
        indice.push_back(tupla('G'));
        indice.push_back(tupla('H'));
        indice.push_back(tupla('I'));
        indice.push_back(tupla('J'));
        indice.push_back(tupla('K'));
        indice.push_back(tupla('L'));
        indice.push_back(tupla('M'));
        indice.push_back(tupla('N'));
        indice.push_back(tupla('O'));
        indice.push_back(tupla('P'));
        indice.push_back(tupla('Q'));
        indice.push_back(tupla('R'));
        indice.push_back(tupla('S'));
        indice.push_back(tupla('T'));
        indice.push_back(tupla('U'));
        indice.push_back(tupla('V'));
        indice.push_back(tupla('W'));
        indice.push_back(tupla('X'));
        indice.push_back(tupla('Y'));
        indice.push_back(tupla('Z'));
        indice.push_back(tupla('0')); //53
        indice.push_back(tupla('1'));
        indice.push_back(tupla('2'));
        indice.push_back(tupla('3'));
        indice.push_back(tupla('4'));
        indice.push_back(tupla('5'));
        indice.push_back(tupla('6'));
        indice.push_back(tupla('7'));
        indice.push_back(tupla('8'));
        indice.push_back(tupla('9'));
        indice.push_back(tupla(':')); //63
        indice.push_back(tupla(' ')); //64
    }

    void imprimirIndice();
    void actualizarTabla(string frase);
};

struct arbolBinario
{
     nodo *raiz;
     map<char, string> interpreteCH; //caracter-> huffman
     map<string, char> interpreteHC; //huffman -> caracter

     // C o n s t r u c t o r
     arbolBinario()
     {
          raiz = NULL;
     }
     arbolBinario(nodo *node)
     {
          raiz = node;
     }

     void preOrden(nodo *);
     void enOrden(nodo *);
     void postOrden(nodo *);
     void crearArbolHuff(tablahuf base);
     nodo *joinArboles(nodo *a, nodo *b);
     pair<int, int> encontrarMenores(vector<nodo *> faltantes);
     void actualizarDiccionarios(nodo *node, string codigo);
     string completarZeros(string codigo);
     string traductorAHuffman(string linea);
     string traductorACaracter(string linea);
};

#include "Agencia.hxx"
#include "Bus.hxx"
#include "Reserva.hxx"
#include "Ruta.hxx"
#include "Viaje.hxx"
#include "ArbolBinario.hxx"
#include "tablahuf.hxx"
#include "Nodo.hxx"
#endif