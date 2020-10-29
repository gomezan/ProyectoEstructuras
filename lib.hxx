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

void ayuda()
{

    cout << "|| PROGRAMA DE TRANSPORTE || \n"
         << endl;
    printf("||%5s %s %5s||\n", "", "AYUDA", "");
    cout << endl;

    // COMPONENTE I

    cout << "\nComandos disponibles:\n"
         << endl;
    cout << "\t Login <id_agencia> \n\t\t"
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

    cout << "\t disponibilidad <ciudad origen> <ciudad destino> \n\t\t"
         << "Este comando genera un reporte de todos los viajes que \n\t\t"
         << "cubren la ruta entre las ciudades origen y destino que \n\t\t"
         << "tienen disponibilidad de sillas, mostrando la fecha y hora \n\t\t"
         << "de salida y las sillas disponibles." << endl;
    cout << "\t reseva <ciudad origen> <ciudad destino> <fecha> <hora> "
            "<pasajero>\n\t\t"
         << "Este comando crea una reserva para un viaje para la ruta\n\t\t"
         << "entre las ciudades origen y destino para la fecha y hora\n\t\t"
         << "indicada y asignada al pasajero que se da como argumento \n\t\t"
         << "del comando." << endl;
    cout << "\t reporte_ventas [fecha inicial] [fecha final] \n\t\t"
         << "Genera un reporte con una visualización agradable de las\n\t\t"
         << "reservas hechas entre el rango de fechas dado como argumentos,\n\t\t"
         << "si no hay argumentos el reporte lo genera para el día de hoy.\n\t\t"
         << "Al final informa el total de dinero que la agencia facturó por \n\t\t"
         << "reservas vendidas, pero teniendo en cuenta si hubo cambios o cancelaciones" << endl;
    cout << "\t cancelar <id viaje> <silla> \n\t\t"
         << " Actualiza el registro de la reserva para el viaje con Id dado y\n\t\t"
         << "numero de silla dados como argumentos, además de actualizar el\n\t\t"
         << "viaje como “VI000”, actualiza el valor del tiquete al 15% del\n\t\t"
         << "contenido en el registro." << endl;
    cout << "\t cambiar <número reserva> <id viaje nuevo> <pasajero> \n\t\t"
         << " Actualiza el registro de la reserva actual identificada con el\n\t\t"
         << "número dado como argumento con el nuevo id de viaje para el pasajero\n\t\t"
         << "indicado, valida si hay sillas disponibles y asigna una al usuario y\n\t\t"
         << "le informa." << endl;

    // COMPONENTE III

    pausarPantalla();
}

// COMPONENTE I

int login(string comando)
{
    Agency aux;
    char *buffer = (char *)malloc(DATA * sizeof(char));
    char *user = (char *)malloc(DATA * sizeof(char));
    char *contrasena = (char *)malloc(DATA * sizeof(char));
    strcpy(buffer, comando.c_str());

    user = strtok(buffer, " ");
    user = strtok(NULL, "");

    cout << "|| PROGRAMA DE TRANSPORTE || \n"
         << endl;
    printf("||%5s %s %5s||\n", "", "LOGIN", "");
    cout << endl;

    cout << "Usuario ingresado: " << user << endl;

    cout << "Ingrese la contraseña: \n$ ";
    cin >> contrasena;

    FILE *archivo = fopen("contrasegnas.dat", "r");

    if (archivo != NULL)
    {

        char *linea = (char *)malloc(CHUNK * sizeof(char));
        char *nombre = (char *)malloc(DATA * sizeof(char));
        char *contra = (char *)malloc(DATA * sizeof(char));
        while (fgets(linea, CHUNK, archivo))
        {

            nombre = strtok(linea, ";");
            contra = strtok(NULL, "\n");
            if (strcmp(nombre, user) == 0)
            {
                if (strcmp(contra, contrasena) == 0)
                {
                    cout << endl
                         << "Bienvenido al sistema" << endl;
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
    }
    else
    {
        perror("No se pudo abrir el archivo");
    }
    return 0;
}

void listar_buses()
{
    int cuenta = 0;
    string opc;
    Bus aux;
    borrarPantalla();
    cout << "|| PROGRAMA DE TRANSPORTE || \n"
         << endl;
    printf("||%5s %s %5s||\n", "", "LISTAR BUSES", "");
    cout << endl;

    FILE *archivo = fopen("buses.dat", "r");

    if (archivo != NULL)
    {
        char *linea = (char *)malloc(CHUNK);

        while (fgets(linea, CHUNK, archivo))
        {

            cuenta++;

            char *valor = strtok(linea, ";");
            aux.setcodeBus(valor);
            valor = strtok(NULL, ";");
            if (!strcmp(valor, "Corriente"))
            {
                aux.setType('c');
            }
            else
            {
                aux.setType('s');
            }
            valor = strtok(NULL, ";");
            aux.setChairs(atoi(valor));
            cout << cuenta << ". ";
            aux.print();

            if (cuenta % 20 == 0)
            {
                do
                {
                    cout << "\nSe han impreso 20 registros" << endl;
                    cout << "Para continuar ingrese \'s\', para salir \'n\' ..." << endl;
                    cin >> opc;
                } while (opc != "s" && opc != "n");
                if (opc == "n")
                {
                    break;
                }
                borrarPantalla();
                cout << "|| PROGRAMA DE TRANSPORTE || \n"
                     << endl;
                printf("||%5s %s %5s||\n", "", "LISTAR BUSES", "");
                cout << endl;
            }
        }
        fclose(archivo);
    }
    else
    {
        perror("No se pudo abrir el archivo");
    }
    cout << "\nSe ha mostrado la lista con exito" << endl;
    pausarPantalla();
}

void listar_rutas()
{
    int cuenta = 0;
    string opc;
    Route aux;
    borrarPantalla();

    cout << "|| PROGRAMA DE TRANSPORTE || \n"
         << endl;
    printf("||%5s %s %5s||\n", "", "LISTAR RUTAS", "");
    cout << endl;

    FILE *archivo = fopen("rutas.dat", "r");

    if (archivo != NULL)
    {

        char *linea = (char *)malloc(CHUNK);

        while (fgets(linea, CHUNK, archivo))
        {

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

            if (cuenta % 20 == 0)
            {
                do
                {
                    cout << "\nSe han impreso 20 registros" << endl;
                    cout << "Para continuar ingrese \'s\', para salir \'n\' ..." << endl;
                    cin >> opc;
                } while (opc != "s" && opc != "n");
                if (opc == "n")
                {
                    break;
                }
                borrarPantalla();
                cout << "|| PROGRAMA DE TRANSPORTE || \n"
                     << endl;
                printf("||%5s %s %5s||\n", "", "LISTAR RUTAS", "");
                cout << endl;
            }
        }
        fclose(archivo);
    }
    else
    {
        perror("No se pudo abrir el archivo");
    }
    cout << "\nSe ha mostrado la lista con exito" << endl;
    pausarPantalla();
}
void listar_viajes()
{
    int cuenta = 0;
    string opc;
    Travel aux;
    borrarPantalla();
    cout << "|| PROGRAMA DE TRANSPORTE || \n"
         << endl;
    printf("||%5s %s %5s||\n", "", "LISTAR VIAJES", "");
    cout << endl;

    FILE *archivo = fopen("viajes.dat", "r");

    if (archivo != NULL)
    {

        char *linea = (char *)malloc(CHUNK);

        while (fgets(linea, CHUNK, archivo))
        {

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

            if (cuenta % 20 == 0)
            {
                do
                {
                    cout << "\nSe han impreso 20 registros" << endl;
                    cout << "Para continuar ingrese \'s\', para salir \'n\' ..." << endl;
                    cin >> opc;
                } while (opc != "s" && opc != "n");
                if (opc == "n")
                {
                    break;
                }
                borrarPantalla();
                cout << "|| PROGRAMA DE TRANSPORTE || \n"
                     << endl;
                printf("||%5s %s %5s||\n", "", "LISTAR VIAJES", "");
                cout << endl;
            }
        }
        fclose(archivo);
    }
    else
    {
        perror("No se pudo abrir el archivo");
    }
    cout << "\nSe ha mostrado la lista con exito" << endl;
    pausarPantalla();
}

// COMPONENTE II

vector<string> disponibilidad(string comando)
{
    borrarPantalla();
    string opc;
    do
    {
        cout << "Desea imprimir todos los resultados: (s/n)" << endl;
        cin >> opc;
    } while (opc != "s" && opc != "n");

    if (opc == "s")
    {
        borrarPantalla();
        cout << "|| PROGRAMA DE TRANSPORTE || \n"
             << endl;
        printf("||%5s %s %5s||\n", "", "DISPONIBILIDAD", "");
        cout << endl;
    }

    vector<string> datos = split(comando, " ");
    vector<string> retorna;

    if (datos.size() != 3)
    {
        cout << "Parametros incorrectos" << endl;
        cout << "$ disponibilidad <ciudad_origen> <ciudad_destino>\n"
             << endl;
        pausarPantalla();
        return retorna;
    }

    string origen = datos.at(1), destino = datos.at(2);
    if (opc == "s")
    {
        cout << "Parametros de busqueda: " << origen << " - " << destino << endl;
    }

    string lineaViaje;
    int cont = 0;

    ifstream archViajes("viajes.dat");
    if (archViajes.is_open())
    {
        while (getline(archViajes, lineaViaje))
        {
            //cout << lineaViaje << endl;
            vector<string> valorViajes = split(lineaViaje, ";");
            Travel auxViajes(valorViajes.at(0), valorViajes.at(1), valorViajes.at(2), valorViajes.at(3), valorViajes.at(4), valorViajes.at(5), atof(valorViajes.at(6).c_str()));

            string lineaRutas;

            ifstream archRutas("rutas.dat");
            if (archRutas.is_open())
            {
                while (getline(archRutas, lineaRutas))
                {
                    //cout << lineaRutas << endl;
                    vector<string> valorRutas = split(lineaRutas, ";");
                    Route auxRutas(valorRutas.at(0), valorRutas.at(1), valorRutas.at(2), valorRutas.at(3), atoi(valorRutas.at(4).c_str()), atof(valorRutas.at(5).c_str()));

                    if (auxViajes.getCodeRoute() == auxRutas.getCodeRoute() && origen == auxRutas.getCityOrg() && destino == auxRutas.getCityDst())
                    {
                        string lineaReservas;
                        vector<int> sillasOcupadas;

                        ifstream archReservas("reservas.dat");
                        if (archReservas.is_open())
                        {
                            while (getline(archReservas, lineaReservas))
                            {
                                vector<string> valorResevas = split(lineaReservas, ";");
                                //cout << lineaReservas << endl;
                                Booking auxReservas(
                                    valorResevas.at(0), valorResevas.at(1), valorResevas.at(2), valorResevas.at(3),
                                    valorResevas.at(4), atoi(valorResevas.at(5).c_str()), valorResevas.at(6),
                                    valorResevas.at(7), valorResevas.at(8), atof(valorResevas.at(9).c_str()));

                                if (auxViajes.getCodeTravel() == auxReservas.getCodeTravel() && auxViajes.getCodeRoute() == auxReservas.getCodeRoute() && auxReservas.getCodeTravel() != "VI000")
                                {
                                    int silla = auxReservas.getChairNumber();
                                    sillasOcupadas.push_back(silla);
                                }
                            }
                            archReservas.close();
                        }
                        else
                        {
                            cout << "No se pudo encontrar reservas.dat" << endl;
                        }
                        string lineaBuses;
                        int sillasTotales = 0;
                        ifstream archBuses("buses.dat");
                        if (archBuses.is_open())
                        {
                            while (getline(archBuses, lineaBuses))
                            {
                                vector<string> valorBuses = split(lineaBuses, ";");
                                char temp;
                                if (valorBuses.at(1) == "Corriente")
                                {
                                    temp = 'c';
                                }
                                else
                                {
                                    temp = 's';
                                }

                                Bus auxBus(valorBuses.at(0), temp,
                                           stoi(valorBuses.at(2)));
                                if (auxBus.getcodeBus() == auxViajes.getCodeBus())
                                {
                                    sillasTotales = auxBus.getChairs();
                                }
                            }
                            archBuses.close();
                        }
                        else
                        {
                            cout << "No se pudo encontrar buses.dat" << endl;
                        }
                        if (sillasTotales == 0)
                        {
                            cout << "No se a encontrado bus para el viaje: " << auxViajes.getCodeTravel() << endl;
                        }
                        bool sillas[sillasTotales];
                        // Inicializado en true
                        for (int i = 0; i < sillasTotales; i++)
                        {
                            sillas[i] = true;
                        }
                        // False para sillas ocupadas
                        for (int i = 0; i < sillasOcupadas.size(); i++)
                        {
                            sillas[sillasOcupadas.at(i)] = false;
                        }
                        //Cuenta sillas disponibles
                        int sillasDisp = 0;
                        for (int i = 0; i < sillasTotales; i++)
                        {
                            if (sillas[i])
                            {
                                sillasDisp++;
                            }
                        }
                        if (opc == "s")
                        {
                            cont++;
                            cout << "Resultado " << cont;
                            cout << "\n\tViaje: " << auxViajes.getCodeTravel();
                            string fecha = auxViajes.getDate();
                            cout << "\n\tFecha: " << fecha[0] << fecha[1] << fecha[2] << fecha[3] << "/"
                                 << fecha[4] << fecha[5] << "/" << fecha[6] << fecha[7];
                            string hora = auxViajes.getTime();
                            cout << " Hora: " << hora[0] << hora[1] << ":" << hora[2] << hora[3];
                            cout << "\n\tSillas disponibles: " << sillasDisp << "/" << sillasTotales << endl;
                        }
                        else
                        {
                            retorna.push_back(auxRutas.getCodeRoute() + ";" + auxViajes.getCodeTravel() + ";" + to_string(sillasDisp));
                        }
                    }
                }
                archRutas.close();
            }
            else
            {
                cout << "No se pudo encontrar rutas.dat" << endl;
            }
        }
        archViajes.close();
    }
    else
    {
        cout << "No se pudo encontrar viajes.dat" << endl;
    }
    pausarPantalla();
    return retorna;
}
void reserva(string comando, string agen) {

  char *linea = (char *)malloc(CHUNK);
  vector<string> com = split(comando, " ");
  string buffer = com.at(0)+" "+com.at(1)+" "+com.at(2);
  char *bus = (char *)malloc(DATA * sizeof(char));
  char *viaje = (char *)malloc(DATA * sizeof(char));
  char *fecha = (char *)malloc(DATA * sizeof(char));
  char *conductor = (char *)malloc(DATA * sizeof(char));
  char *costo = (char *)malloc(DATA * sizeof(char));
  

  vector <string> disponibles = disponibilidad(buffer);

  FILE *reservas = fopen("reservas.dat","a");

  if(disponibles.size() == 0){
    cout<<"La ruta no existe o no"<<endl;
  }

  for(int i =0;i<disponibles.size();i++){


    char * aux = new char[disponibles[i].length()+1];
    strcpy(aux,disponibles[i].c_str());

    char * rut = strtok(aux, ";");
    char * viaj = strtok(NULL,";");
    int silla = atoi(strtok(NULL,";"));

    if(silla != 0){

      FILE *ruts = fopen("viajes.dat","r");

      while(fgets(linea,CHUNK,ruts)){

       char * ruta = strtok(linea, ";");
       if(strcmp(ruta,rut)){
          bus = strtok(NULL,";");
          viaje = strtok(NULL,";");
          if(strcmp(viaje, viaj)){
            
          }
       }

      }
      fclose(ruts);
    }
  }
}

void reporte_ventas(string comando)
{
    string fechaInicio, fechaFin;
    vector<string> datos = split(comando, " ");

    borrarPantalla();
    cout << "|| PROGRAMA DE TRANSPORTE || \n"
         << endl;
    printf("||%5s %s %5s||\n", "", "REPORTE VENTAS", "");
    cout << endl;

    if (datos.size() != 3)
    {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y%m%d", &tstruct);

        fechaInicio = buf;
        fechaFin = buf;
    }
    else
    {
        fechaInicio = datos.at(1);
        fechaFin = datos.at(2);
    }
    cout << "Criterio de busqueda: " << fechaInicio << " hasta " << fechaFin << endl;

    string anioI, mesI, diaI, anioF, mesF, diaF;

    for (int i = 0; i < fechaInicio.size(); i++)
    {
        if (i < 4)
        {
            anioI += fechaInicio[i];
            anioF += fechaFin[i];
        }
        else if (i < 6)
        {
            mesI += fechaInicio[i];
            mesF += fechaFin[i];
        }
        else
        {
            diaI += fechaInicio[i];
            diaF += fechaFin[i];
        }
    }

    string lineaReservas;
    vector<Booking> reservas;

    ifstream archReservas("reservas.dat");
    if (archReservas.is_open())
    {
        while (getline(archReservas, lineaReservas))
        {
            vector<string> valorReservas = split(lineaReservas, ";");
            Booking auxReserva(valorReservas.at(0), valorReservas.at(1), valorReservas.at(2), valorReservas.at(3),
                               valorReservas.at(4), atoi(valorReservas.at(5).c_str()), valorReservas.at(6),
                               valorReservas.at(7), valorReservas.at(8), atof(valorReservas.at(9).c_str()));

            string fecha = auxReserva.getDate();

            string anio, mes, dia;

            for (int i = 0; i < fecha.size(); i++)
            {
                if (i < 4)
                {
                    anio += fecha[i];
                }
                else if (i < 6)
                {
                    mes += fecha[i];
                }
                else
                {
                    dia += fecha[i];
                }
            }

            if (anio >= anioI && anio <= anioF &&
                mes >= mesI && mes <= mesF &&
                dia >= diaI && dia <= diaF)
            {
                reservas.push_back(auxReserva);
            }
        }
        archReservas.close();
    }

    if (reservas.size() == 0)
    {
        cout << "No se encontraron resultados para los parametros dados." << endl;
        pausarPantalla();
        return;
    }
    else
    {
        printf("||%5s %s %5s||\n", "", "REPORTE", "");
    }
    double totalReservas = 0;
    double totalCambios = 0;
    double totalCancela = 0;
    bool cent[reservas.size()];
    bool cent1[reservas.size()];

    for (int i = 0; i < reservas.size(); i++)
    {
        cent[i] = true;
        cent1[i] = true;
    }

    for (int i = 0; i < reservas.size(); i++)
    {
        totalReservas += reservas.at(i).getChairCost();
        cent1[i] = false;
        for (int j = 0; j < reservas.size(); j++)
        {
            if (reservas.at(i).getCodeBooking() == reservas.at(j).getCodeBooking() && cent[j] && reservas.at(j).getCodeTravel() == "VI000" && cent1)
            {
                totalCambios += (reservas.at(i).getChairCost() - reservas.at(j).getChairCost());
                cent[j] = false;
            }
        }
        if (reservas.at(i).getCodeTravel() == "VI000" && cent[i])
        {
            totalCancela -= reservas.at(i).getChairCost();
            cent[i] = false;
        }
    }

    cout << "Reservas vendidas: " << totalReservas << endl;
    cout << "Cambios realizados: " << totalCambios << endl;
    cout << "Cancelaciones: " << totalCancela << endl;
    cout << "Total: " << totalReservas + totalCambios + totalCancela << endl;
    pausarPantalla();
}

void cancelar(string comando)
{
    borrarPantalla();
    vector<string> datos = split(comando, " ");

    cout << "|| PROGRAMA DE TRANSPORTE || \n"
         << endl;
    printf("||%5s %s %5s||\n", "", "CANCELAR", "");
    cout << endl;

    if (datos.size() != 3)
    {
        cout << "Parametros incorrectos" << endl;
        cout << "$ cancelar <id viaje> <silla>\n"
             << endl;
        pausarPantalla();
        return;
    }

    string idViaje = datos.at(1), silla = datos.at(2);

    ifstream fs("reservas.dat");
    ofstream fstemp("reservastemp.dat");
    if (!fs || !fstemp)
    {
        cout << "Error al abrir el archivo!" << endl;
        return;
    }
    string lineaReseva;
    while (getline(fs, lineaReseva))
    {
        vector<string> valorReservas = split(lineaReseva, ";");

        if (valorReservas.at(4) == idViaje && valorReservas.at(5) == silla)
        {
            lineaReseva = valorReservas.at(0) + ";" + valorReservas.at(1) + ";" + valorReservas.at(2) + ";" + valorReservas.at(3) + ";" + "VI000" + ";" + valorReservas.at(5) + ";" + valorReservas.at(6) + ";" + valorReservas.at(7) + ";" + valorReservas.at(8) + ";" + valorReservas.at(9);
        }
        fstemp << lineaReseva << endl;
    }

    fs.close();
    fstemp.close();
    remove("reservas.dat");
    rename("reservastemp.dat", "reservas.dat");

    cout << "El archivo reservas.dat ha sido modificado correctamente" << endl;
    pausarPantalla();
}
void cambiar(string comando)
{
    cout << "En proceso ..." << endl;
    pausarPantalla();
}

// COMPONENTE III

void recomendar(string comando)
{
    cout << "En proceso ..." << endl;
    pausarPantalla();
}
void comprimir(string comando)
{
    cout << "En proceso ..." << endl;
    pausarPantalla();
}
void descomprimir(string comando)
{
    cout << "En proceso ..." << endl;
    pausarPantalla();
}

// UTILIDADES

void borrarPantalla()
{
    system("clear"); // para windows "cls"
}

void pausarPantalla()
{
    cout << "Presione la tecla enter para continuar ..." << endl;
    system("read"); // para windows "PAUSE"
    borrarPantalla();
}

vector<string> split(string s, string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}