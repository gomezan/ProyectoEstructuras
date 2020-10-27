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

Travel::Travel(string codeRoute, string codeBus, string codeTravel, string date, string driverName, double chairCost)
{
    this->codeRoute = codeRoute;
    this->codeBus = codeBus;
    this->codeTravel = codeTravel;
    this->date = date;
    this->driverName = driverName;
    this->chairCost = chairCost;
}

Travel::Travel()
{
}

string Travel::getCodeRoute(){
    return this->codeRoute;
}
void Travel::setCodeRoute(string codeRoute){
    this->codeRoute = codeRoute;
}
string Travel::getCodeBus(){
    return this->codeBus;
}
void Travel::setCodeBus(string codeBus){
    this->codeBus = codeBus;
}
string Travel::getCodeTravel(){
    return this->codeTravel;
}
void Travel::setCodeTravel(string codeTravel){
    this->codeTravel = codeTravel;
}
string Travel::getDate(){
    return this->date;
}
void Travel::setDate(string date){
    this->date = date;
}
string Travel::getDriverName(){
    return this->driverName;
}
void Travel::setDriverName(string driverName){
    this->driverName = driverName;
}
double Travel::getChairCost(){
    return this->chairCost;
}
void Travel::setChairCost(double chairCost){
    this->chairCost = chairCost;
}
void Travel::print(){
    cout << "Codigo de ruta: " << this->codeRoute << " Codigo de bus: " << this->codeBus
         << "Codigo de viaje: " << this->codeTravel << " Fecha: " << this->date
         << " Conductor: " << this->driverName << " Costo de la silla: " << this->chairCost
         << endl;
}