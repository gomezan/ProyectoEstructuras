/**
 * Estructuras de datos
 * Nombre del archivo: reserva.hxx
 * Autores: Carlos Andres Erazo Garzon
 *          Nicolas Gil
 *          Andres Gomez
 * Fecha: 26/10/2020
 * Descripcion: Funciones de la clase Reserva
 * */

#include "clases.h"

Reserva::Reserva(string agency, string codeBooking, string codeRoute, string codeBus,
                 string codeTravel, int chairNumber, string passenger, string date,
                 string time, double chairCost)
{

    this->agency = agency;
    this->codeBooking = codeBooking;
    this->codeRoute = codeRoute;
    this->codeBus = codeBus;
    this->codeTravel = codeTravel;
    this->chairNumber = chairNumber;
    this->passenger = passenger;
    this->date = date;
    this->time = time;
    this->chairCost = chairCost;
}

Reserva::Reserva()
{
}

string Reserva::getAgency()
{
    return this->agency;
}

void Reserva::setAgency(string agency)
{
    this->agency = agency;
}

string Reserva::getCodeBooking()
{
    return this->codeBooking;
}

void Reserva::setCodeBooking(string codeBooking)
{
    this->codeBooking = codeBooking;
}

string Reserva::getCodeRoute()
{
    return this->codeRoute;
}

void Reserva::setCodeRoute(string codeRoute)
{
    this->codeRoute = codeRoute;
}

string Reserva::getCodeBus()
{
    return this->codeBus;
}

void Reserva::setCodeBus(string codeBus)
{
    this->codeBus = codeBus;
}

string Reserva::getCodeTravel()
{
    return this->codeTravel;
}

void Reserva::setCodeTravel(string codeTravel)
{
    this->codeTravel = codeTravel;
}

int Reserva::getChairNumber()
{
    return this->chairNumber;
}

void Reserva::setChairNumber(int chairNumber)
{
    this->chairNumber = chairNumber;
}

string Reserva::getPassenger()
{
    return this->passenger;
}

void Reserva::setPassenger(string passenger)
{
    this->passenger = passenger;
}

string Reserva::getDate()
{
    return this->date;
}

void Reserva::setDate(string date)
{
    this->date = date;
}

string Reserva::getTime()
{
    return this->time;
}

void Reserva::setTime(string time)
{
    this->time = time;
}

double Reserva::getChairCost()
{
    return this->chairCost;
}

void Reserva::setChairCost(double chairCost)
{
    this->chairCost = chairCost;
}

void Reserva::print()
{
    cout << "Agency: " << this->agency << " Code booking: " << this->codeBooking
         << " Code route: " << this->codeRoute << " Code Bus: " << this->codeBus
         << " Code travel: " << this->codeTravel << " Chair number: " << this->chairNumber
         << " Passenger: " << this->passenger << " Date: " << this->date
         << " Time: " << this->time << " Chair cost: " << this->chairCost
         << endl;
}