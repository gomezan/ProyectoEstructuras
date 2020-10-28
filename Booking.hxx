/*
* Name: Booking.hxx
* Data structures: First delivery
* Authors: Carlos Andres Erazo Garzon
*          Nicolas Gil
*          Andres Gomez
* Date:
* Description:
*/

#include "Booking.h"



Booking::Booking(string agency, string codeBooking, string codeRoute, string codeBus,
                 string codeTravel, int chairNumber, string passenger, string date,
                 string time, double chairCost)
{
}

Booking::Booking()
{

string Booking::getAgency(){
    return this->agency;
}

void Booking::setAgency(string agency){
    this->agency = agency;
}

string Booking::getCodeBooking(){
    return this->codeBooking;
}

void Booking::setCodeBooking(string codeBooking){
    this->codeBooking = codeBooking;
}

string Booking::getCodeRoute(){
    return this->codeRoute;
}

void Booking::setCodeRoute(string codeRoute){
    this->codeRoute = codeRoute;
}

string Booking::getCodeBus(){
    return this->codeBus;
}

void Booking::setCodeBus(string codeBus){
    this->codeBus = codeBus;
}

string Booking::getCodeTravel(){
    return this->codeTravel;
}

void Booking::setCodeTravel(string codeTravel){
    this->codeTravel = codeTravel;
}

int Booking::getChairNumber(){
    return this->chairNumber;
}

void Booking::setChairNumber(int chairNumber){
    this->chairNumber = chairNumber;
}

string Booking::getPassenger(){
    return this->passenger;
}

void Booking::setPassenger(string passenger){
    this->passenger = passenger;
}

string Booking::getDate(){
    return this->date;
}

void Booking::setDate(string date){
    this->date = date;
}

string Booking::getTime(){
    return this->time;
}

void Booking::setTime(string time){
    this->time = time;
}

double Booking::getChairCost(){
    return this->chairCost;
}

void Booking::setChairCost(double chairCost){
    this->chairCost = chairCost;
}

void Booking::print(){
    cout << "Agency: " << this->agency << " Code booking: " << this->codeBooking
         << " Code route: " << this->codeRoute << " Code Bus: " << this->codeBus
         << " Code travel: " << this->codeTravel << " Chair number: " << this->chairNumber
         << " Passenger: " << this->passenger << " Date: " << this->date
         << " Time: " << this->time << " Chair cost: " << this->chairCost
         << endl;
}
