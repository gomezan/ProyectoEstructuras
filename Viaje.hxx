/* 
* Names: travels.hxx
* Data structures: First delivery
* Authors: Carlos Andres Erazo Garzon
*          Nicolas Gil
*          Andres Gomez
* Date:
* Description: 
*/

//#include "Travel.h"

Viaje::Viaje(string codeRoute, string codeBus, string codeTravel, string date, string time, string driverName, double chairCost)
{
    this->codeRoute = codeRoute;
    this->codeBus = codeBus;
    this->codeTravel = codeTravel;
    this->date = date;
    this->time = time;
    this->driverName = driverName;
    this->chairCost = chairCost;
}

Viaje::Viaje()
{
}

string Viaje::getCodeRoute(){
    return this->codeRoute;
}
void Viaje::setCodeRoute(string codeRoute){
    this->codeRoute = codeRoute;
}
string Viaje::getCodeBus(){
    return this->codeBus;
}
void Viaje::setCodeBus(string codeBus){
    this->codeBus = codeBus;
}
string Viaje::getCodeTravel(){
    return this->codeTravel;
}
void Viaje::setCodeTravel(string codeTravel){
    this->codeTravel = codeTravel;
}
string Viaje::getDate(){
    return this->date;
}
void Viaje::setDate(string date){
    this->date = date;
}
string Viaje::getDriverName(){
    return this->driverName;
}
void Viaje::setDriverName(string driverName){
    this->driverName = driverName;
}
double Viaje::getChairCost(){
    return this->chairCost;
}
void Viaje::setChairCost(double chairCost){
    this->chairCost = chairCost;
}

void Viaje::setTime(string time){
    this->time = time;
}
string Viaje::getTime(){
    return this->time;
}

void Viaje::print(){
    cout << "\t" << this->codeTravel
         << "\n Codigo de ruta: " << this->codeRoute << "\n Codigo de bus: " << this->codeBus
         << "\n Fecha: " << this->date
         << " Hora: " << this->time
         << "\n Conductor: " << this->driverName << "\n Costo de la silla: " << this->chairCost
         << endl << endl;
}