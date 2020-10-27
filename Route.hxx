/* 
* Name: Route.hxx
* Data structures: First delivery
* Authors: Carlos Andres Erazo Garzon
*          Nicolas Gil
*          Andres Gomez
* Date:
* Description: 
*/

#include "Route.h"

Route::Route()
{
}

Route::Route(string codeRoute, int day, string cityOrg, string cityDst, int depTime, double kmCity)
{
    this -> codeRoute = codeRoute;
    this -> day = day;
    this -> cityOrg = cityOrg;
    this -> cityDst = cityDst;
    this -> depTime = depTime;
    this -> kmCity = kmCity;
}

string Route::getCodeRoute() {
    return this->codeRoute;
}

void Route::setCodeRoute(string codeRoute) {
    this->codeRoute = codeRoute;
}

string Route::getDay() {
    return this->day;
}

void Route::setDay(string day) {
    this->day = day;
}

string Route::getCityOrg() {
    return this->cityOrg;
}

void Route::setCityOrg(string cityOrg) {
    this->cityOrg = cityOrg;
}

string Route::getCityDst() {
    return this->cityDst;
}

void Route::setCityDst(string cityDst) {
    this->cityDst = cityDst;
}

int Route::getDepTime() {
    return this->depTime;
}

void Route::setDepTime(int depTime) {
    this->depTime = depTime;
}

double Route::getKmCity() {
    return this->kmCity;
}

void Route::setKmCity(double kmCity) {
    this->kmCity = kmCity;
}

void Route::print(){
    cout << "Codigo: " << this->codeRoute << " Dia: " << this->day 
         << " Ciudad origen: " << this->cityOrg << " Ciudad destino: " << this->cityDst 
         << " Hora de salida: " << this ->depTime << " Km: " << this ->kmCity 
         << endl;
}