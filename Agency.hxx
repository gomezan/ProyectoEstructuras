/**
* Name: Agency.hxx
* Data structures: First delivery
* Authors: Carlos Andres Erazo Garzon
*          Nicolas Gil
*          Andres Gomez
* Date:
* Description: 
* */

#include "Agency.h"


Agency::Agency(string agencyName, string agencyPass)
{
    this->agencyName = agencyName;
    this->agencyPass = agencyPass;
}

Agency::Agency()
{
}

string Agency::getAgencyName(){
    return this->agencyName;
}

void Agency::setAgencyName(string agencyName){
    this->agencyName = agencyName;
}

string Agency::getAgencyPass(){
    return this->agencyPass;
}

void Agency::setAgencyPass(string agencyPass){
    this->agencyPass = agencyPass;
}

void Agency::print(){
    cout << "Agency name: " << this->agencyName
         << "\nAgency password: " << this->agencyPass
         << endl;
}