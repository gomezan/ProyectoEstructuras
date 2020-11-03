/**
 * Estructuras de datos
 * Nombre del archivo: Agencia.hxx
 * Autores: Carlos Andres Erazo Garzon
 *          Nicolas Gil
 *          Andres Gomez
 * Fecha: 26/10/2020
 * Descripcion: Funciones de la clase Agencia
 * */

#include "clases.h"


Agencia::Agencia(string agencyName, string agencyPass)
{
    this->agencyName = agencyName;
    this->agencyPass = agencyPass;
}

Agencia::Agencia()
{
}

string Agencia::getAgencyName(){
    return this->agencyName;
}

void Agencia::setAgencyName(string agencyName){
    this->agencyName = agencyName;
}

string Agencia::getAgencyPass(){
    return this->agencyPass;
}

void Agencia::setAgencyPass(string agencyPass){
    this->agencyPass = agencyPass;
}

void Agencia::print(){
    cout << "Nombre: " << this->agencyName
         << "\nContrasenia: " << this->agencyPass
         << endl;
}