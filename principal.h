/**
 * Estructuras de datos
 * Nombre del archivo: principal.h
 * Autores: Carlos Andres Erazo Garzon
 *          Nicolas Gil
 *          Andres Gomez
 * Fecha: 26/10/2020
 * Descripcion: Libreria que lleva el manejo de las funciones del programa.
 * */


#ifndef __LIB__H__
#define __LIB__H__

#include <iostream>
using namespace std;
#include "clases.h"
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <vector>

void ayuda();
void borrarPantalla();
void pausarPantalla();
vector<string> split(string s, string delimiter);
vector<string> abrirArchivo(string ruta);
vector<Viaje> abrirArchivoViaje(string ruta);
vector<Bus> abrirArchivoBus(string ruta);
vector<Reserva> abrirArchivoReserva(string ruta);
vector<Ruta> abrirArchivoRuta(string ruta);


// COMPONENTE I

int login(string comando);
void listar_buses();
void listar_rutas();
void listar_viajes();

void imprimir(string ruta, string tipo);

// COMPONENTE II

vector<string> disponibilidad(string comando);
void reserva(string comando, string agencia);
void reporte_ventas(string comando);
void cancelar(string comando);
void cambiar(string comando, string agen);

// COMPONENTE III

void recomendar(string comando);
void comprimir(string comando);
void descomprimir(string comando);

#include "principal.hxx"
#include "componenteI.hxx"
#include "componenteII.hxx"
#include "componenteIII.hxx"
#endif