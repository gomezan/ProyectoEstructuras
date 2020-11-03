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

#include "Agencia.hxx"
#include "Bus.hxx"
#include "Reserva.hxx"
#include "Ruta.hxx"
#include "Viaje.hxx"
#endif