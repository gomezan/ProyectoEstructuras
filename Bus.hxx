/* 
* Name: Bus.hxx
* Data structures: First delivery
* Authors: Carlos Andres Erazo Garzon
*          Nicolas Gil
*          Andres Gomez
* Date:
* Description: 
*/


#include "Bus.h"

Bus::Bus(string codeBus, char type, int chairs)
{
    this->codeBus = codeBus;
    this->type = type;
    this->chairs = chairs;
}

Bus::Bus()
{
}

string Bus::getcodeBus(){
    return this->codeBus;
}

void Bus::setcodeBus(string codeBus){
    this->codeBus = codeBus;
}

char Bus::getType(){
    return this->type;
}

void Bus::setType(char type){
    this->type = type;
}

int Bus::getChairs(){
    return this->chairs;
}

void Bus::setChairs(int chairs){
    this->chairs = chairs;
}

void Bus::print(){
    cout << "Codigo: " << this->codeBus;
    if(this->type == 'c'){
        cout << " Tipo: " << "Corriente";
    }else{
        cout << " Tipo: " << "Especial";
    }
    
    cout << " Numero de sillas: " << this->chairs << endl;
}