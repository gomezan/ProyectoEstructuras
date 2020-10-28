/**
 * Name: Agency.hxx
 * Data structures: First delivery
 * Authors: Carlos Andres Erazo Garzon
 *          Nicolas Gil
 *          Andres Gomez
 * Date:
 * Description:
 * */

#include "lib.h"
#define CHUNK 200
#define DATA 10

void ayuda() {

  // COMPONENTE I

  cout << "\nComandos disponibles:\n" << endl;
  cout << "\t Login<id_agencia> \n\t\t"
       << "Este comando pregunta al usuario por una contraseña \n\t\t"
       << "para el identificador de la agencia dado en el comando, \n\t\t"
       << "y activa la sesión si la contraseña es igual a la guardada \n\t\t"
       << "en el registro correspondiente para la agencia dada, en caso \n\t\t"
       << "contrario muestra un mensaje de error." << endl;
  cout << "\t logout \n\t\t"
       << "Este comando termina la sesión activa de la agencia y \n\t\t"
       << "vuelve a la consola o terminal del sistema." << endl;
  cout << "\t listar_buses \n\t\t"
       << "Imprime, con una visualización agradable, los registros de \n\t\t"
       << "los buses" << endl;
  cout << "\t listar_rutas \n\t\t"
       << " Imprime, con una visualización agradable, los registros de \n\t\t"
       << "las rutas" << endl;
  cout << "\t listar_viajes \n\t\t"
       << "Imprime, con una visualización agradable, los registros de \n\t\t"
       << "los viajes" << endl;

  // COMPONENTE II

  // COMPONENTE III

  pausarPantalla();
}

// COMPONENTE I

int login(string comando) {

  Agency aux;
  char *buffer = (char *)malloc(DATA * sizeof(char));
  char *user = (char *)malloc(DATA * sizeof(char));
  char *contrasena = (char *)malloc(DATA * sizeof(char));
  strcpy(buffer, comando.c_str());

  user = strtok(buffer, " ");
  user = strtok(NULL, "");

  cout << "|| PROGRAMA DE TRANSPORTE || \n" << endl;
  printf("||%5s %s %5s||\n", "", "LOGIN", "");
  cout << endl;

  cout << "Usuario ingresado: " << user << endl;

  cout << "Ingrese la contraseña: \n$ ";
  cin >> contrasena;

  FILE *archivo = fopen("contrasegnas.dat", "r");

  if (archivo != NULL) {

    char *linea = (char *)malloc(CHUNK * sizeof(char));
    char *nombre = (char *)malloc(DATA * sizeof(char));
    char *contra = (char *)malloc(DATA * sizeof(char));
    while (fgets(linea, CHUNK, archivo)) {

      nombre = strtok(linea, ";");
      contra = strtok(NULL, "\n");
      if (strcmp(nombre, user) == 0) {
        if (strcmp(contra, contrasena) == 0) {
          cout << endl << "Bienvenido al sistema" << endl;
          pausarPantalla();
          return 1;
        }
      }
    }
    cout << "Error de autenticación, no es posible ingresar al sistema, "
            "inténtelo otra vez"
         << endl;
    pausarPantalla();
    fclose(archivo);
  } else {
    perror("No se pudo abrir el archivo");
  }
  return 0;
}

void listar_buses() {
  int cuenta = 0;
  string opc;
  Bus aux;
  borrarPantalla();
  cout << "|| PROGRAMA DE TRANSPORTE || \n" << endl;
  printf("||%5s %s %5s||\n", "", "LISTAR BUSES", "");
  cout << endl;

  FILE *archivo = fopen("buses.dat", "r");

  if (archivo != NULL) {
    char *linea = (char *)malloc(CHUNK);

    while (fgets(linea, CHUNK, archivo)) {

      cuenta++;

      char *valor = strtok(linea, ";");
      aux.setcodeBus(valor);
      valor = strtok(NULL, ";");
      if (!strcmp(valor, "Corriente")) {
        aux.setType('c');
      } else {
        aux.setType('s');
      }
      valor = strtok(NULL, ";");
      aux.setChairs(atoi(valor));
      cout << cuenta << ". ";
      aux.print();

      if (cuenta % 20 == 0) {
        do {
          cout << "\nSe han impreso 20 registros" << endl;
          cout << "Para continuar ingrese \'s\', para salir \'n\' ..." << endl;
          cin >> opc;
        } while (opc != "s" && opc != "n");
        if (opc == "n") {
          break;
        }
        borrarPantalla();
        cout << "|| PROGRAMA DE TRANSPORTE || \n" << endl;
        printf("||%5s %s %5s||\n", "", "LISTAR BUSES", "");
        cout << endl;
      }
    }
    fclose(archivo);
  } else {
    perror("No se pudo abrir el archivo");
  }
  cout << "\nSe ha mostrado la lista con exito" << endl;
  pausarPantalla();
}

void listar_rutas() {
  int cuenta = 0;
  string opc;
  Route aux;
  borrarPantalla();

  cout << "|| PROGRAMA DE TRANSPORTE || \n" << endl;
  printf("||%5s %s %5s||\n", "", "LISTAR RUTAS", "");
  cout << endl;

  FILE *archivo = fopen("rutas.dat", "r");

  if (archivo != NULL) {

    char *linea = (char *)malloc(CHUNK);

    while (fgets(linea, CHUNK, archivo)) {

      cuenta++;

      char *valor = strtok(linea, ";");
      aux.setCodeRoute(valor);
      valor = strtok(NULL, ";");
      aux.setDay(valor);
      valor = strtok(NULL, ";");
      aux.setCityOrg(valor);
      valor = strtok(NULL, ";");
      aux.setCityDst(valor);
      valor = strtok(NULL, ";");
      aux.setDepTime(atoi(valor));
      valor = strtok(NULL, ";");
      aux.setKmCity(atof(valor));
      cout << cuenta << ". ";
      aux.print();

      if (cuenta % 20 == 0) {
        do {
          cout << "\nSe han impreso 20 registros" << endl;
          cout << "Para continuar ingrese \'s\', para salir \'n\' ..." << endl;
          cin >> opc;
        } while (opc != "s" && opc != "n");
        if (opc == "n") {
          break;
        }
        borrarPantalla();
        cout << "|| PROGRAMA DE TRANSPORTE || \n" << endl;
        printf("||%5s %s %5s||\n", "", "LISTAR RUTAS", "");
        cout << endl;
      }
    }
    fclose(archivo);
  } else {
    perror("No se pudo abrir el archivo");
  }
  cout << "\nSe ha mostrado la lista con exito" << endl;
  pausarPantalla();
}
void listar_viajes() {
  int cuenta = 0;
  string opc;
  Travel aux;
  borrarPantalla();
  cout << "|| PROGRAMA DE TRANSPORTE || \n" << endl;
  printf("||%5s %s %5s||\n", "", "LISTAR VIAJES", "");
  cout << endl;

  FILE *archivo = fopen("viajes.dat", "r");

  if (archivo != NULL) {

    char *linea = (char *)malloc(CHUNK);

    while (fgets(linea, CHUNK, archivo)) {

      cuenta++;

      char *valor = strtok(linea, ";");
      aux.setCodeRoute(valor);
      valor = strtok(NULL, ";");
      aux.setCodeBus(valor);
      valor = strtok(NULL, ";");
      aux.setCodeTravel(valor);
      valor = strtok(NULL, ";");
      aux.setDate(valor);
      valor = strtok(NULL, ";");
      aux.setDriverName(valor);
      valor = strtok(NULL, ";");
      aux.setChairCost(atof(valor));

      cout << cuenta << ". ";
      aux.print();

      if (cuenta % 20 == 0) {
        do {
          cout << "\nSe han impreso 20 registros" << endl;
          cout << "Para continuar ingrese \'s\', para salir \'n\' ..." << endl;
          cin >> opc;
        } while (opc != "s" && opc != "n");
        if (opc == "n") {
          break;
        }
        borrarPantalla();
        cout << "|| PROGRAMA DE TRANSPORTE || \n" << endl;
        printf("||%5s %s %5s||\n", "", "LISTAR VIAJES", "");
        cout << endl;
      }
    }
    fclose(archivo);
  } else {
    perror("No se pudo abrir el archivo");
  }
  cout << "\nSe ha mostrado la lista con exito" << endl;
  pausarPantalla();
}

// COMPONENTE II

void disponibilidad(string comando) {
  int cuenta = 0;
  string opc;

  vector<string> v = split(comando, " ");

  if (v.size() != 3) {
    cout << "Parametros incorrectos" << endl;
    cout << "$ disponibilidad <ciudad_origen> <ciudad_destino>\n" << endl;
    pausarPantalla();
    return;
  }
  string origen = v.at(1);
  string destino = v.at(2);

  borrarPantalla();
  cout << "|| PROGRAMA DE TRANSPORTE || \n" << endl;
  printf("||%5s %s %5s||\n", "", "DISPONIBILIDAD", "");
  cout << endl;

  FILE *archViajes = fopen("viajes.dat", "r");

  if (archViajes != NULL) {

    char *linea = (char *)malloc(CHUNK);

    while (fgets(linea, CHUNK, archViajes)) {

      vector<string> valorV = split(linea, ";");
      Travel auxT(valorV.at(0), valorV.at(1), valorV.at(2), valorV.at(3),
                  valorV.at(4), valorV.at(5), atof(valorV.at(6).c_str()));

      FILE *archRoute = fopen("rutas.dat", "r");

      if (archRoute != NULL) {
        char *lineaR = (char *)malloc(CHUNK);

        while (fgets(lineaR, CHUNK, archRoute)) {

          vector<string> valorR = split(lineaR, ";");

          Route auxR(valorR.at(0), valorR.at(1), valorR.at(2),
                     valorR.at(3), atoi(valorR.at(4).c_str()),
                     atof(valorR.at(5).c_str()));

          if (auxT.getCodeRoute() == auxR.getCodeRoute() &&
              auxR.getCityOrg() == origen && auxR.getCityDst() == destino) {

            FILE *archBooking = fopen("reservas.dat", "r");

            if (archBooking != NULL) {
              char *lineaB = (char *)malloc(CHUNK);
              vector<int> puestosO;
              int sillasTotales = 0;
              while (fgets(lineaB, CHUNK, archBooking)) {
                vector<string> valorB = split(lineaB, ";");

                Booking auxB(
                    valorB.at(0), valorB.at(1), valorB.at(2), valorB.at(3),
                    valorB.at(4), atoi(valorB.at(5).c_str()), valorB.at(6),
                    valorB.at(7), valorB.at(8), atof(valorB.at(9).c_str()));

                if (auxB.getCodeRoute() == auxR.getCodeRoute() &&
                    auxB.getCodeTravel() == auxT.getCodeTravel()) {

                  puestosO.push_back(auxB.getChairNumber());

                  FILE *archBus = fopen("buses.dat", "r");
                  if (archBus != NULL) {
                    char *lineaBus = (char *)malloc(CHUNK);
                    while (fgets(lineaBus, CHUNK, archBus)) {
                      vector<string> valorBuses = split(lineaBus, ";");
                      char temp;
                      if (valorBuses.at(1) == "Corriente") {
                        temp = 'c';
                      } else {
                        temp = 's';
                      }

                      Bus auxBus(valorBuses.at(0), temp,
                                 stoi(valorBuses.at(2)));
                      sillasTotales = auxBus.getChairs();
                    }
                  }
                  fclose(archBus);
                  bool sillasDisp[sillasTotales] = {true};
                  for (int i = 0; i < puestosO.size(); i++) {
                    sillasDisp[puestosO.at(i)] = false;
                  }

                  cout << "Para el viaje: " << auxT.getCodeTravel() << endl;
                  cout << "Fecha: " << auxT.getDate() << " y hora: " << auxT.getTime() <<endl;
                  cout << "De: " << origen << " a: " << destino << endl;
                  cout << "En la ruta: " << auxR.getCodeRoute() << endl;
                  cout << "Tiene disponibles los siguientes asientos" << endl;
                  int cont = 0;
                  for (int i = 0; i < sillasTotales; i++) {
                    if (sillasDisp[i] == false) {
                      cout << i+1 << "\t";
                      cont++;
                    }else{
                        cout << "-" <<"\t";
                    }
                    if ((i+1) % 2 == 0) {
                      cout << endl;
                    }
                  }
                  cout << "\nHay un total de: " << cont << " sillas disponibles"
                       << endl;
                }
              }

              fclose(archBooking);
            }
          }
        }

        fclose(archRoute);
      }
    }
    fclose(archViajes);
  } else {
    perror("No se pudo abrir el archivo");
  }
  cout << "\nSe han mostrado los resultados con exito" << endl;
  pausarPantalla();
}
void reserva(string comando) {
  cout << "En proceso ..." << endl;
  pausarPantalla();
}

void reporte_ventas(string comando) {
  string s1, s2, s3;
  size_t inicio, fin;
  cout << "en progreso" << comando << endl;

  inicio = comando.find_first_of('[');
  s1 = comando.substr(inicio + 1);
  inicio = s1.find_first_of(']');
  s2 = s1.substr(0, inicio + 2);
  s1 = s1.substr(0, inicio + 1);

  cout << "s1: " << s1 << endl;
  cout << "s2: " << s1 << endl;
}

void listar_b() {
  int cuenta = 0;
  string opc;
  Bus aux;
  borrarPantalla();
  cout << "\t\t\t\t\tLISTA DE BUSES\n" << endl;

  FILE *archivo = fopen("buses.dat", "r");

  if (archivo != NULL) {
    char *linea = (char *)malloc(CHUNK);

    while (fgets(linea, CHUNK, archivo)) {

      cuenta++;

      char *valor = strtok(linea, ";");
      aux.setcodeBus(valor);
      valor = strtok(NULL, ";");
      if (!strcmp(valor, "Corriente")) {
        aux.setType('c');
      } else {
        aux.setType('s');
      }
      valor = strtok(NULL, ";");
      aux.setChairs(atoi(valor));
      cout << cuenta << ". ";
      aux.print();

      if (cuenta % 20 == 0) {
        do {
          cout << "\nSe han impreso 20 registros" << endl;
          cout << "Para continuar ingrese \'s\', para salir \'n\' ..." << endl;
          cin >> opc;
        } while (opc != "s" && opc != "n");
        if (opc == "n") {
          break;
        }
        borrarPantalla();
        cout << "\t\t\t\t\tLISTA DE BUSES\n" << endl;
      }
    }

  } else {
    perror("No se pudo abrir el archivo");
  }
  pausarPantalla();
}

void cancelar(string comando) {
  cout << "En proceso ..." << endl;
  pausarPantalla();
}
void cambiar(string comando) {
  cout << "En proceso ..." << endl;
  pausarPantalla();
}

// COMPONENTE III

void recomendar(string comando) {
  cout << "En proceso ..." << endl;
  pausarPantalla();
}
void comprimir(string comando) {
  cout << "En proceso ..." << endl;
  pausarPantalla();
}
void descomprimir(string comando) {
  cout << "En proceso ..." << endl;
  pausarPantalla();
}

// UTILIDADES

void borrarPantalla() { system("clear"); }

void pausarPantalla() {
  cout << "Presione la tecla enter para continuar ..." << endl;
  system("read");
  borrarPantalla();
}

vector<string> split(string s, string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(s.substr(pos_start));
  return res;
}