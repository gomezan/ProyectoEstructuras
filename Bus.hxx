/**
 * Estructuras de datos
 * Nombre del archivo: Bus.hxx
 * Autores: Carlos Andres Erazo Garzon
 *          Nicolas Gil
 *          Andres Gomez
 * Fecha: 26/10/2020
 * Descripcion: Funciones de la clase Bus
 * */

#include "clases.h"

Bus::Bus(string codeBus, char type, int chairs)
{
    this->codeBus = codeBus;
    this->type = type;
    this->chairs = chairs;
}

Bus::Bus()
{
}

string Bus::getcodeBus()
{
    return this->codeBus;
}

void Bus::setcodeBus(string codeBus)
{
    this->codeBus = codeBus;
}

char Bus::getType()
{
    return this->type;
}

void Bus::setType(char type)
{
    this->type = type;
}

int Bus::getChairs()
{
    return this->chairs;
}

void Bus::setChairs(int chairs)
{
    this->chairs = chairs;
}

void Bus::print()
{
    cout << "\t" << this->codeBus;
    if (this->type == 'c')
    {
        cout << "\n Tipo: "
             << "Corriente";
    }
    else
    {
        cout << "\n Tipo: "
             << "Especial";
    }

    cout << "\n Numero de sillas: " << this->chairs 
        << endl << endl;
}