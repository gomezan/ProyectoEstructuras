/**
 * Estructuras de datos
 * Nombre del archivo: componenteI.hxx
 * Autores: Carlos Andres Erazo Garzon
 *          Nicolas Gil
 *          Andres Gomez
 * Fecha: 26/10/2020
 * Descripcion: Implementación de las funciones correspondientes para la
 *              primera entrega.
 * */

#include "principal.h"

int login(string comando)
{
    borrarPantalla();

    //Declaración de variables
    Agencia aux;
    ifstream archContra("contrasegnas.dat");
    string pass;
    string lineaContra;
    vector<string> datos;
    string user;
    vector<string> resultados;

    //Inicialización de variables
    datos = split(comando, " ");

    //Titulo del comando
    cout << "|| PROGRAMA DE TRANSPORTE || \n"
         << endl;
    printf("||%5s %s %5s||\n", "", "LOGIN", "");
    cout << endl;

    //Validación
    if (datos.size() != 2)
    {
        cout << "Parametros incorrectos" << endl;
        cout << "$ login <id_agencia>"
             << endl;
        pausarPantalla();
        return 0;
    }

    user = datos.at(1);

    //Obtención de datos necesarios
    cout << "Usuario ingresado: " << user << endl;
    cout << "Ingrese la contraseña: \n$ ";
    cin >> pass;

    //Guardar
    aux.setAgencyName(user);
    aux.setAgencyPass(pass);

    //Recorrido del archivo
    resultados = abrirArchivo("contrasegnas.dat");

    for(int i = 0; i<resultados.size(); i++){
        vector<string> valorContra = split(resultados.at(i), ";");
        if(user == valorContra.at(0) && pass == valorContra.at(1)){
            cout << "Bienvenido al sistema." << endl;
            pausarPantalla();
            return 1;
        }
    }
    cout << "Error de autenticación, no es posible ingresar al sistema, \n"
         << "inténtelo otra vez" << endl;
    pausarPantalla();
    return 0;
}

void listar_buses()
{
    borrarPantalla();

    //Titulo del comando
    cout << "|| PROGRAMA DE TRANSPORTE || \n"
         << endl;
    printf("||%5s %s %5s||\n", "", "LISTAR BUSES", "");
    cout << endl;

    //Imprimir
    imprimir("buses.dat", "BUSES");

    //Esperar respuesta del usuario
    pausarPantalla();
}

void listar_rutas()
{
    borrarPantalla();

    //Titulo del comando
    cout << "|| PROGRAMA DE TRANSPORTE || \n"
         << endl;
    printf("||%5s %s %5s||\n", "", "LISTAR RUTAS", "");
    cout << endl;

    //Imprimir
    imprimir("rutas.dat","RUTAS");

    //Esperar respuesta del usuario
    pausarPantalla();
}


void listar_viajes()
{
    borrarPantalla();

    //Titulo del comando
    cout << "|| PROGRAMA DE TRANSPORTE || \n"
         << endl;
    printf("||%5s %s %5s||\n", "", "LISTAR VIAJES", "");
    cout << endl;

    //imprimir
    imprimir("viajes.dat", "VIAJES");

    //Esperar respuesta del usuario
    pausarPantalla();
}

void imprimir(string ruta, string tipo)
{
    //Declaracion de variables
    vector<string> datos;
    string opc;

    //Asignar datos del archivo
    datos = abrirArchivo(ruta);

    //Recorrer para imprimir segun corresponda
    for (int i = 0; i < datos.size(); i++)
    {
        cout << i+1 << ". ";
        if (tipo == "BUSES")
        {
            vector<string> valorBuses;
            valorBuses = split(datos.at(i), ";");

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
            auxBus.print();
        }
        if (tipo == "RESERVAS")
        {
            vector<string> valorResevas = split(datos.at(i), ";");

            Reserva auxReservas(
                valorResevas.at(0), valorResevas.at(1),
                valorResevas.at(2), valorResevas.at(3),
                valorResevas.at(4), atoi(valorResevas.at(5).c_str()),
                valorResevas.at(6), valorResevas.at(7),
                valorResevas.at(8), atof(valorResevas.at(9).c_str()));
            auxReservas.print();
        }
        if (tipo == "RUTAS")
        {
            vector<string> valorRutas = split(datos.at(i), ";");
            Ruta auxRutas(
                valorRutas.at(0), valorRutas.at(1),
                valorRutas.at(2), valorRutas.at(3),
                atoi(valorRutas.at(4).c_str()), atof(valorRutas.at(5).c_str()));
            auxRutas.print();
        }
        if (tipo == "VIAJES")
        {
            vector<string> valorViajes = split(datos.at(i), ";");
            Viaje auxViajes(
                valorViajes.at(0), valorViajes.at(1),
                valorViajes.at(2), valorViajes.at(3),
                valorViajes.at(4), valorViajes.at(5),
                atof(valorViajes.at(6).c_str()));
            auxViajes.print();
        }
        if (i+1 % 20 == 0)
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
            printf("||%5s %s %s %5s||\n", "", "LISTAR", tipo.c_str(), "");
            cout << endl;
        }
    }
    cout << "\nSe ha mostrado la lista con exito" << endl;
}