/* 
* Name: Booking.h
* Data structures: First delivery
* Authors: Carlos Andres Erazo Garzon
*          Nicolas Gil
*          Andres Gomez
* Date:
* Description: 
*/

#ifndef __LIB__H__
#define __LIB__H__

#include <iostream>
using namespace std;
#include <cstdlib>
#include <fstream>
#include <string.h>
#include "Bus.h"
#include "Agency.h"
#include "Route.h"
#include "Travel.h"

void ayuda();
int login(string comando);
void listar_buses();
void listar_rutas();
void listar_viajes();
void borrarPantalla();

#include "lib.hxx"
#endif