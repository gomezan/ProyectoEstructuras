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
#include <vector>
#include "Booking.h"
#include <stdlib.h>

void ayuda();

//COMPONENTE I

int login(string comando);
void listar_buses();
void listar_rutas();
void listar_viajes();

//COMPONENTE II

void disponibilidad(string comando);
void reserva(string comando);
void reporte_ventas(string comando);
void cancelar(string comando);
void cambiar(string comando);

//COMPONENTE III

void recomendar(string comando);
void comprimir(string comando);
void descomprimir(string comando);

//UTILIDADES

void borrarPantalla();
void pausarPantalla();
vector<string> split(string s, string delimiter);

#include "lib.hxx"
#endif