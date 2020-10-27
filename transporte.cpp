/*
* Nombre: transporte.cpp (main)
* Estructuras de datos: primera entrega
* Autores: Carlos Andres Erazo Garzon
*          Nicolas Gil
*          Andres Gomez
* Fecha:
* Descripcion: El escenario es una empresa de transporte que cuenta con varias agencias
* que cumplen con el papel de venta de ticketes, para la primera entrega del proyecto
* el programa atiende con realizar la lectura de los documentos necesarios, verificacion
* de disponibilidad de tiquetes, cotizacion y venta de tiquetes, asi como tambien reportes
* entre otros.
*/

#include <iostream>
#include "lib.h"
using namespace std;

int log = 0;



int main (int argc, char *argv[]){

    if(argc != 2){ // verify

    }
    string comando;

    do{
        //borrarPantalla();
        cout << "\n\nPROGRAMA DE TRANSPORTE\n\n";
        cout << "Introduzca un comando: " << endl;
        cout << "$ ";
        cin >> comando;

        if(comando == "ayuda"){
            ayuda();
        }else if(comando.find("login") != string::npos){
            log = login(comando);
        }else{
            cout << "Para las demas operaciones primero debe registrarse" << endl;
        }

    }while(log == 0);

    while(true){
        //borrarPantalla();
        cout << "PROGRAMA DE TRANSPORTE\n\n";
        cout << "Ingrese un commando: "<<endl;
        cout << "$ ";
        cin >> comando;

        if(comando == "ayuda"){
            ayuda();
        }
        else if(comando.find("login") != string::npos){
            cout<<"Ya se encuentra registrado"<<endl;
        }
        else if(comando.find("logout") != string::npos){
            return 0;
        }
        else if(comando.find("listar_buses") != string::npos){
            listar_buses();
        }
        else if(comando.find("listar_rutas") != string::npos){
            listar_rutas();
        }
        else if(comando.find("listar_viajes") != string::npos){
            listar_viajes();
        }
        else if(comando.find("reporte_ventas") != string::npos){
            reporte_ventas(comando);
        }
        else{
            cout<<"Comando no valido verifique e intente nuevamente"<<endl;
            cout<<endl;
        }

    }

}
