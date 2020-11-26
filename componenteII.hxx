/**
 * Estructuras de datos
 * Nombre del archivo: componenteII.hxx
 * Autores: Carlos Andres Erazo Garzon
 *          Nicolas Gil
 *          Andres Gomez
 * Fecha: 26/10/2020
 * Descripcion: Implementación de las funciones correspondientes para la
 *              segunda entrega.
 * */

#include "principal.h"
#define CHUNK 200
#define DATA 10

vector<string> disponibilidad(string comando, string opc)
{
    //Declaración de variables
    int cont;
    vector<string> datos;
    vector<string> retorna;
    string origen;
    string destino;
    vector<Viaje> archViajes;
    vector<Ruta> archRutas;
    vector<Reserva> archReservas;
    vector<Bus> archBuses;

    //Inicialización de variables
    cont = 0;
    datos = split(comando, " ");
    archViajes = abrirArchivoViaje("viajes.dat");
    archRutas = abrirArchivoRuta("rutas.dat");
    archReservas = abrirArchivoReserva("reservas.dat");
    archBuses = abrirArchivoBus("buses.dat");

    borrarPantalla();

    if (datos.size() != 3)
    {
        cout << "Parametros incorrectos" << endl;
        cout << "$ disponibilidad <ciudad_origen> <ciudad_destino>\n"
             << endl;
        pausarPantalla();
        return retorna;
    }

    if (opc == "s")
    {
        borrarPantalla();
        cout << "|| PROGRAMA DE TRANSPORTE || \n"
             << endl;
        printf("||%5s %s %5s||\n", "", "DISPONIBILIDAD", "");
        cout << endl;
    }

    origen = datos.at(1);
    destino = datos.at(2);

    if (opc == "s")
    {
        cout << "Parametros de busqueda: " << origen << " - " << destino << endl;
    }

    for (int i = 0; i < archViajes.size(); i++)
    {
        for (int j = 0; j < archRutas.size(); j++)
        {
            if (archViajes.at(i).getCodeRoute() == archRutas.at(j).getCodeRoute() && origen == archRutas.at(j).getCityOrg() && destino == archRutas.at(j).getCityDst())
            {
                vector<int> sillasOcupadas;

                for (int k = 0; k < archReservas.size(); k++)
                {
                    if (archViajes.at(i).getCodeTravel() == archReservas.at(k).getCodeTravel() && archViajes.at(i).getCodeRoute() == archReservas.at(k).getCodeRoute() && archReservas.at(k).getCodeTravel() != "VI000")
                    {
                        int silla = archReservas.at(k).getChairNumber();
                        sillasOcupadas.push_back(silla);
                    }
                }
                int sillasTotales = 0;

                for (int k = 0; k < archBuses.size(); k++)
                {
                    if (archBuses.at(k).getcodeBus() == archViajes.at(i).getCodeBus())
                    {
                        sillasTotales = archBuses.at(k).getChairs();
                    }
                }
                if (sillasTotales == 0)
                {
                    cout << "No se a encontrado bus para el viaje: " << archViajes.at(i).getCodeTravel() << endl;
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
                    cout << "\n\tViaje: " << archViajes.at(i).getCodeTravel();
                    string fecha = archViajes.at(i).getDate();
                    cout << "\n\tFecha: " << fecha[0] << fecha[1] << fecha[2] << fecha[3] << "/"
                         << fecha[4] << fecha[5] << "/" << fecha[6] << fecha[7];
                    string hora = archViajes.at(i).getTime();
                    cout << " Hora: " << hora[0] << hora[1] << ":" << hora[2] << hora[3];
                    cout << "\n\tSillas disponibles: " << sillasDisp << "/" << sillasTotales << endl
                         << endl;
                }
                else
                {
                    retorna.push_back(archRutas.at(j).getCodeRoute() + ";" + archViajes.at(i).getCodeTravel() + ";" + to_string(sillasDisp) + ";" + to_string(sillasTotales));
                }
            }
        }
    }
    if (opc == "n")
    {
        return retorna;
    }
    pausarPantalla();
    return retorna;
}

void reserva(string comando, string agen)
{
    //Declaración de variables
    vector<string> datos;
    string comando2;
    vector<Reserva> archReservas;
    vector<Viaje> archViajes;
    string sill;
    Reserva guarda;

    //Inicialización de variables
    datos = split(comando, " ");

    //Titulo del comando
    borrarPantalla();
    cout << "|| PROGRAMA DE TRANSPORTE || \n"
         << endl;
    printf("||%5s %s %5s||\n", "", "REPORTE VENTAS", "");
    cout << endl;

    if (datos.size() != 6)
    {
        cout << "Parametros incorrectos" << endl;
        cout << "$ reserva <ciudad_origen> <ciudad_destino> <fecha> <hora> <pasajero>\n"
             << endl;
        pausarPantalla();
        return;
    }

    comando2 = datos.at(0) + " " + datos.at(1) + " " + datos.at(2);
    vector<string> disponibles = disponibilidad(comando2, "n");

    archReservas = abrirArchivoReserva("reservas.dat");
    archViajes = abrirArchivoViaje("viajes.dat");

    if (disponibles.size() == 0)
    {
        cout << "La ruta no existe o no cumple con los parametros." << endl;
        pausarPantalla();
        return;
    }

    for (int i = 0; i < disponibles.size(); i++)
    {
        vector<string> resultados = split(disponibles.at(i), ";");

        if (stoi(resultados.at(2)) != 0)
        {
            for (int j = 0; j < archViajes.size(); j++)
            {
                if (resultados.at(0) == archViajes.at(j).getCodeRoute() && resultados.at(1) == archViajes.at(j).getCodeTravel() && datos.at(3) == archViajes.at(j).getDate() && datos.at(4) == archViajes.at(j).getTime())
                {
                    bool sillas[stoi(resultados.at(3))];

                    for (int k = 0; k < archReservas.size(); k++)
                    {
                        for (int l = 0; l < archViajes.size(); l++)
                        {
                            if (archReservas.at(k).getCodeTravel() == archViajes.at(l).getCodeTravel() &&
                                archReservas.at(k).getCodeRoute() == archViajes.at(l).getCodeRoute())
                            {
                                sillas[archReservas.at(k).getChairNumber()] = false;
                            }
                            else
                            {
                                sillas[archReservas.at(k).getChairNumber()] = true;
                            }
                        }
                    }
                    cout << "Sillas disponibles: " << endl;
                    for (int k = 0; k < stoi(resultados.at(3)); k++)
                    {

                        if (sillas[k])
                        {
                            cout << k << " Disponible\t";
                        }
                        else
                        {
                            cout << k << " Reservda\t";
                        }
                        if ((k + 1) % 4 == 0)
                        {
                            cout << endl;
                        }
                    }

                    while (true)
                    {
                        cout << "\n\nEscoja una silla: ";
                        cin >> sill;

                        if (sillas[stoi(sill)])
                        {
                            break;
                        }
                        else
                        {
                            cout << "ERROR: silla no disponible." << endl;
                        }
                    }
                    guarda = Reserva(
                        agen,
                        "RS" + to_string(stoi(archViajes.at(j).getTime()) + stoi(sill)),
                        archViajes.at(j).getCodeRoute(),
                        archViajes.at(j).getCodeBus(),
                        archViajes.at(j).getCodeTravel(),
                        stoi(sill),
                        datos.at(5),
                        archViajes.at(j).getDate(),
                        archViajes.at(j).getTime(),
                        archViajes.at(j).getChairCost());

                    modifica(
                        guarda.getAgency() + ";" +
                            guarda.getCodeBooking() + ";" +
                            guarda.getCodeRoute() + ";" +
                            guarda.getCodeBus() + ";" +
                            guarda.getCodeTravel() + ";" +
                            to_string(guarda.getChairNumber()) + ";" +
                            guarda.getPassenger() + ";" +
                            guarda.getDate() + ";" +
                            guarda.getTime() + ";" +
                            to_string(guarda.getChairCost()),
                        "reservas.dat");
                    cout << "Silla asignada con exito." << endl;
                    pausarPantalla();
                }
            }
        }
    }
}

void reporte_ventas(string comando, int call)
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
    cout << "Criterio de busqueda: " << fechaInicio << " hasta " << fechaFin << endl
         << endl;

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
    vector<Reserva> reservas;

    ifstream archReservas("reservas.dat");
    if (archReservas.is_open())
    {
        while (getline(archReservas, lineaReservas))
        {
            vector<string> valorReservas = split(lineaReservas, ";");
            Reserva auxReserva(valorReservas.at(0), valorReservas.at(1), valorReservas.at(2), valorReservas.at(3),
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

    double totalReservas = 0;
    double totalCambios = 0;
    double totalCancela = 0;
    int cantC = 0;
    int cant = 0;

    for (int i = 0; i < reservas.size(); i++)
    {
        totalReservas += reservas.at(i).getChairCost();

        if (reservas.at(i).getPassenger().find("-C") != std::string::npos)
        {
            totalCambios += (reservas.at(i).getChairCost());
            cant++;
        }

        if (reservas.at(i).getCodeTravel() == "VI000")
        {
            totalCancela += reservas.at(i).getChairCost();
            cantC++;
        }
    }

    if (call == 1)
    {
        printf("||%5s %s %5s||\n", "", "REPORTE", "");
        cout << endl;
        cout << "Total vendido: " << totalReservas << endl;
        cout << "Cambios realizados: " << cant << "\n Con total de: " << totalCambios << endl;
        cout << "Cancelaciones realizadas: " << cantC << "\n Con total de: " << totalCancela << endl
             << endl;
        pausarPantalla();
        return;
    }
    else
    {
        remove(huff);
        printf("||%5s %s %5s||\n", "", "COMPRIMIR", "");
        string res;

        tablahuf prueba; //creo la tabla

        prueba.actualizarTabla("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789| :");

        arbolBinario p;
        p.crearArbolHuff(prueba); //creo el arbol
                                  //pintarArbol(p.raiz);    //imprime el arbol

        cout << "Generando compresion de Huffman..." << endl;
        res = p.traductorAHuffman("|  REPORTE  |");
        guardarLinea(res, huff);
        res = p.traductorAHuffman("Total vendido: " + to_string((int)totalReservas));
        guardarLinea(res, huff);
        res = p.traductorAHuffman("Cambios realizados: " + to_string((int)cant));
        guardarLinea(res, huff);
        res = p.traductorAHuffman("Con total de: " + to_string((int)totalCambios));
        guardarLinea(res, huff);
        res = p.traductorAHuffman("Cancelaciones realizadas: " + to_string((int)cantC));
        guardarLinea(res, huff);
        res = p.traductorAHuffman("Con total de: " + to_string((int)totalCancela));
        guardarLinea(res, huff);

        cout << "... Proceso terminado\n" << endl;
    }
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
    string guarda;
    string resultado;
    while (getline(fs, lineaReseva))
    {
        vector<string> valorReservas = split(lineaReseva, ";");

        if (valorReservas.at(4) == idViaje && valorReservas.at(5) == silla)
        {
            Reserva auxReservas(valorReservas.at(0), valorReservas.at(1), valorReservas.at(2), valorReservas.at(3),
                                valorReservas.at(4), atoi(valorReservas.at(5).c_str()), valorReservas.at(6),
                                valorReservas.at(7), valorReservas.at(8), atof(valorReservas.at(9).c_str()));
            guarda = lineaReseva;
            lineaReseva = valorReservas.at(0) + ";" + valorReservas.at(1) + ";" + valorReservas.at(2) + ";" + valorReservas.at(3) + ";" + "VI000" + ";" + valorReservas.at(5) + ";" + valorReservas.at(6) + ";" + valorReservas.at(7) + ";" + valorReservas.at(8) + ";" + to_string(stof(valorReservas.at(9)) * 0.15);
        }
        fstemp << lineaReseva << endl;
    }

    fs.close();
    fstemp.close();
    remove("reservas.dat");
    rename("reservastemp.dat", "reservas.dat");

    cout << "El archivo reservas.dat ha sido modificado correctamente" << endl;

    string lineaRutas;

    ifstream archRutas("rutas.dat");
    if (archRutas.is_open())
    {
        while (getline(archRutas, lineaRutas))
        {
            vector<string> valorRutas = split(lineaRutas, ";");
            Ruta auxRutas(valorRutas.at(0), valorRutas.at(1), valorRutas.at(2), valorRutas.at(3), atoi(valorRutas.at(4).c_str()), atof(valorRutas.at(5).c_str()));

            vector<string> valorReservas = split(guarda, ";");

            if (valorReservas.at(2) == auxRutas.getCodeRoute())
            {
                vector<string> resultados = disponibilidad("disponibilidad " + auxRutas.getCityOrg() + " " + auxRutas.getCityDst(), "n");

                for (int i = 0; i < resultados.size(); i++)
                {
                    vector<string> valorViajesDisp = split(resultados.at(i), ";");
                    if (valorViajesDisp.at(1) == idViaje)
                    {
                        cout << "Ahora la silla esta disponible." << endl;
                        string lineaViaje;

                        ifstream archViajes("viajes.dat");
                        if (archViajes.is_open())
                        {
                            while (getline(archViajes, lineaViaje))
                            {
                                vector<string> valorViajes = split(lineaViaje, ";");
                                Viaje auxViajes(valorViajes.at(0), valorViajes.at(1), valorViajes.at(2), valorViajes.at(3), valorViajes.at(4), valorViajes.at(5), atof(valorViajes.at(6).c_str()));
                                if (idViaje == auxViajes.getCodeTravel())
                                {
                                    resultado = lineaViaje;
                                }
                            }
                        }
                    }
                }
            }
        }
        archRutas.close();
    }
    else
    {
        cout << "No se pudo encontrar viajes.dat" << endl;
    }

    pausarPantalla();
}
void cambiar(string comando, string agen)
{
    borrarPantalla();
    vector<string> datos = split(comando, " ");

    cout << "|| PROGRAMA DE TRANSPORTE || \n"
         << endl;
    printf("||%5s %s %5s||\n", "", "CAMBIAR", "");
    cout << endl;

    if (datos.size() != 4)
    {
        cout << "Parametros incorrectos" << endl;
        cout << "$ cambiar <Número reserva> <id viaje nuevo> <pasajero>\n"
             << endl;
        pausarPantalla();
        return;
    }

    ifstream fs("reservas.dat");
    ofstream fstemp("reservastemp.dat");
    if (!fs || !fstemp)
    {
        cout << "Error al abrir el archivo!" << endl;
        return;
    }

    string lineaReseva;
    string guarda;
    string resultado;

    vector<Viaje> archViajes = abrirArchivoViaje("viajes.dat");
    vector<Ruta> archRutas = abrirArchivoRuta("rutas.dat");

    while (getline(fs, lineaReseva))
    {
        bool cent = true;
        vector<string> valorReservas = split(lineaReseva, ";");

        if (valorReservas.at(1) == datos.at(1))
        {
            cent = false;
            Reserva auxReservas(valorReservas.at(0), valorReservas.at(1), valorReservas.at(2), valorReservas.at(3),
                                valorReservas.at(4), atoi(valorReservas.at(5).c_str()), valorReservas.at(6),
                                valorReservas.at(7), valorReservas.at(8), atof(valorReservas.at(9).c_str()));

            for (int i = 0; i < archViajes.size(); i++)
            {
                if (archViajes.at(i).getCodeTravel() == datos.at(2))
                {
                    cout << "El nuevo viaje existe, asignando silla ..." << endl;

                    for (int j = 0; j < archRutas.size(); j++)
                    {
                        if (archViajes.at(i).getCodeRoute() == archRutas.at(j).getCodeRoute())
                        {
                            reserva("reserva " +
                                        archRutas.at(j).getCityOrg() + " " +
                                        archRutas.at(j).getCityDst() + " " +
                                        archViajes.at(i).getDate() + " " +
                                        archViajes.at(i).getTime() + " " +
                                        datos.at(3) + "-C",
                                    agen);
                            break;
                        }
                    }
                }
            }
        }
        if (cent)
        {
            fstemp << lineaReseva << endl;
        }
    }

    fs.close();
    fstemp.close();
    remove("reservas.dat");
    rename("reservastemp.dat", "reservas.dat");

    cout << "El archivo reservas.dat ha sido modificado correctamente" << endl;
    pausarPantalla();
}