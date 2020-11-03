/**
 * Estructuras de datos
 * Nombre del archivo: Ruta.hxx
 * Autores: Carlos Andres Erazo Garzon
 *          Nicolas Gil
 *          Andres Gomez
 * Fecha: 26/10/2020
 * Descripcion: Funciones de la clase Ruta
 * */

#include "clases.h"

Ruta::Ruta()
{
}

Ruta::Ruta(string codeRoute, string day, string cityOrg, string cityDst, int depTime, double kmCity)
{
    this -> codeRoute = codeRoute;
    this -> day = day;
    this -> cityOrg = cityOrg;
    this -> cityDst = cityDst;
    this -> depTime = depTime;
    this -> kmCity = kmCity;
}

string Ruta::getCodeRoute() {
    return this->codeRoute;
}

void Ruta::setCodeRoute(string codeRoute) {
    this->codeRoute = codeRoute;
}

string Ruta::getDay() {
    return this->day;
}

void Ruta::setDay(string day) {
    this->day = day;
}

string Ruta::getCityOrg() {
    return this->cityOrg;
}

void Ruta::setCityOrg(string cityOrg) {
    this->cityOrg = cityOrg;
}

string Ruta::getCityDst() {
    return this->cityDst;
}

void Ruta::setCityDst(string cityDst) {
    this->cityDst = cityDst;
}

int Ruta::getDepTime() {
    return this->depTime;
}

void Ruta::setDepTime(int depTime) {
    this->depTime = depTime;
}

double Ruta::getKmCity() {
    return this->kmCity;
}

void Ruta::setKmCity(double kmCity) {
    this->kmCity = kmCity;
}

void Ruta::print(){
    cout << "\t " << this->codeRoute << "\n Dia: " << this->day << endl
         << " Ciudad origen: " << this->cityOrg << "\n Ciudad destino: " << this->cityDst << endl
         << " Hora de salida: " << this ->depTime << " Km: " << this ->kmCity 
         << endl << endl;
}