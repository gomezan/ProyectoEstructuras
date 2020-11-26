/**
 * Estructuras de datos
 * Nombre del archivo: principal.hxx
 * Autores: Carlos Andres Erazo Garzon
 *          Nicolas Gil
 *          Andres Gomez
 * Fecha: 26/10/2020
 * Descripcion: Implementación de la libreria principal.
 * */

#include "principal.h"

void ayuda()
{
    //Titulo del comando
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

vector<string> abrirArchivo(string ruta)
{
    vector<string> retorna;
    ifstream arch(ruta);
    string lineaArch;

    if (arch.is_open())
    {
        while (getline(arch, lineaArch))
        {
            retorna.push_back(lineaArch);
        }
        arch.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo " << ruta << endl;
    }
    return retorna;
}

vector<Viaje> abrirArchivoViaje(string ruta)
{
    vector<Viaje> retorna;
    ifstream arch(ruta);
    string lineaArch;

    if (arch.is_open())
    {
        while (getline(arch, lineaArch))
        {
            vector<string> valorViajes = split(lineaArch, ";");
            Viaje auxViajes(valorViajes.at(0), valorViajes.at(1), valorViajes.at(2), valorViajes.at(3), valorViajes.at(4), valorViajes.at(5), atof(valorViajes.at(6).c_str()));
            retorna.push_back(auxViajes);
        }
        arch.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo " << ruta << endl;
    }
    return retorna;
}

vector<Bus> abrirArchivoBus(string ruta)
{
    vector<Bus> retorna;
    ifstream arch(ruta);
    string lineaArch;

    if (arch.is_open())
    {
        while (getline(arch, lineaArch))
        {
            vector<string> valorBuses = split(lineaArch, ";");
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
            retorna.push_back(auxBus);
        }
        arch.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo " << ruta << endl;
    }
    return retorna;
}

vector<Reserva> abrirArchivoReserva(string ruta)
{
    vector<Reserva> retorna;
    ifstream arch(ruta);
    string lineaArch;

    if (arch.is_open())
    {
        while (getline(arch, lineaArch))
        {
            vector<string> valorResevas = split(lineaArch, ";");
            Reserva auxReservas(
                valorResevas.at(0), valorResevas.at(1), valorResevas.at(2), valorResevas.at(3),
                valorResevas.at(4), atoi(valorResevas.at(5).c_str()), valorResevas.at(6),
                valorResevas.at(7), valorResevas.at(8), atof(valorResevas.at(9).c_str()));
            retorna.push_back(auxReservas);
        }
        arch.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo " << ruta << endl;
    }
    return retorna;
}

vector<Ruta> abrirArchivoRuta(string ruta)
{
    vector<Ruta> retorna;
    ifstream arch(ruta);
    string lineaArch;

    if (arch.is_open())
    {
        while (getline(arch, lineaArch))
        {

            vector<string> valorRutas = split(lineaArch, ";");
            Ruta auxRutas(valorRutas.at(0), valorRutas.at(1), valorRutas.at(2), valorRutas.at(3), atoi(valorRutas.at(4).c_str()), atof(valorRutas.at(5).c_str()));
            retorna.push_back(auxRutas);
        }
        arch.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo " << ruta << endl;
    }
    return retorna;
}

bool modifica(string linea, string ruta)
{
    ofstream out_file;

    // Escribir el archivo
    out_file.open(ruta, ios::app);
    out_file << linea << endl;
    out_file.close();

    return true;
}

void guardarLinea(string linea, string ruta)
{
    ofstream f(ruta, ios::app);
    if (f.is_open())
    {
        f << linea << endl;
    }
    else
        cerr << "Error de apertura del archivo." << endl;
    f.close();
}