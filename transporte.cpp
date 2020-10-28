/*
<<<<<<< HEAD
 * Nombre: transporte.cpp (main)
 * Estructuras de datos: primera entrega
 * Autores: Carlos Andres Erazo Garzon
 *          Nicolas Gil
 *          Andres Gomez
 * Fecha:
 * Descripcion: El escenario es una empresa de transporte que cuenta con varias
 * agencias que cumplen con el papel de venta de ticketes, para la primera
 * entrega del proyecto el programa atiende con realizar la lectura de los
 * documentos necesarios, verificacion de disponibilidad de tiquetes, cotizacion
 * y venta de tiquetes, asi como tambien reportes entre otros.
 */
=======
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
>>>>>>> origin/andres

#include "lib.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include <readline/history.h>
#include <readline/readline.h>

int log = 0;

vector<string> vocabulory{
    // COMPONENTE I
    "login<", "logout", "listar_buses", "listar_rutas", "listar_viajes",
    // COMPONENTE II
    "disponibilidad", "reserva", "reporte_ventas", "cancelar", "cambiar",
    // COMPONENTE III
    "recomendar", "comprimir", "descomprimir"};

char *command_generator(const char *text, int state) {
  static vector<string> matches;
  static size_t match_index = 0;

  if (state == 0) {
    matches.clear();
    match_index = 0;

    string textstr(text);
    for (auto word : vocabulory) {
      if (word.size() >= textstr.size() &&
          word.compare(0, textstr.size(), textstr) == 0) {
        matches.push_back(word);
      }
    }
  }

  if (match_index >= matches.size()) {
    return nullptr;
  } else {
    return strdup(matches[match_index++].c_str());
  }
}

char **command_completion(const char *text, int start, int end) {
  rl_attempted_completion_over = 1;
  return rl_completion_matches(text, command_generator);
}

int main(int argc, char **argv) {
  if (argc > 1 && string(argv[1]) == "-d") {
    rl_bind_key('\t', rl_insert);
  }
  rl_attempted_completion_function = command_completion;

  char *buf;
  string cmd;

  while ((buf = readline("$ ")) != nullptr) {
    cmd = string(buf);
    if (cmd.size() > 0) {
      add_history(buf);
    }
<<<<<<< HEAD
    free(buf);
    stringstream scmd(cmd);
    scmd >> cmd;

    vector<string>::iterator itr =
        find(vocabulory.begin(), vocabulory.end(), cmd);
    if (itr != vocabulory.end()) {
      cout << cmd << ": " << distance(vocabulory.begin(), itr) << endl;

      // COMPONENTE I

      if (cmd.find("login") != std::string::npos) {
        log = login(cmd);
      }
      if (cmd.find("logout") != std::string::npos) {
        cout << "Gracias por usar el programa de transporte." << endl;
        return 0;
      }
      if (cmd.find("listar_buses") != std::string::npos) {
        listar_buses();
      }
      if (cmd.find("listar_rutas") != std::string::npos) {
        listar_rutas();
      }
      if (cmd.find("listar_viajes") != std::string::npos) {
        listar_viajes();
      }
=======
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
>>>>>>> origin/andres

      // COMPONENTE II

      if (cmd.find("disponibilidad") != std::string::npos) {
        listar_viajes();
      }
      if (cmd.find("reserva") != std::string::npos) {
        listar_viajes();
      }
      if (cmd.find("reporte_ventas") != std::string::npos) {
        listar_viajes();
      }
      if (cmd.find("cancelar") != std::string::npos) {
        listar_viajes();
      }
      if (cmd.find("cambiar") != std::string::npos) {
        listar_viajes();
      }

      // MANDAR FUNCION
    } else {
      cout << "Comando no registrado." << std::endl;
    }
<<<<<<< HEAD
  }

  cout << endl;
  return 0;
}
=======

}
>>>>>>> origin/andres
