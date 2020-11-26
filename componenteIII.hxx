/**
 * Estructuras de datos
 * Nombre del archivo: componenteIII.hxx
 * Autores: Carlos Andres Erazo Garzon
 *          Nicolas Gil
 *          Andres Gomez
 * Fecha: 26/10/2020
 * Descripcion: Implementación de las funciones correspondientes para la
 *              tercera entrega.
 * */

#include "principal.h"

void recomendar(string comando)
{
    cout << "En proceso ..." << endl;
    pausarPantalla();
}
void comprimir(string comando)
{
    borrarPantalla();
    reporte_ventas(comando, 0);
    pausarPantalla();
}
void descomprimir(string comando)
{
    borrarPantalla();
    cout << "|| PROGRAMA DE TRANSPORTE || \n"
         << endl;
    printf("||%5s %s %5s||\n", "", "DESCOMPRIMIR", "");

    vector<string> datos = split(comando, " ");
    string s, linea;

    tablahuf prueba; //creo la tabla

    if (datos.size() != 3)
    {
        cout << "Parametros incorrectos" << endl;
        cout << "$ reserva  <archivo-entrada.huf> <archivo-salida.txt>\n"
             << endl;
        pausarPantalla();
        return;
    }

    prueba.actualizarTabla("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789| :");

    arbolBinario p;
    p.crearArbolHuff(prueba); //creo el arbol
                              //pintarArbol(p.raiz);    //imprime el arbol
    ifstream f(datos.at(1));
    cout << "Reporte recuperado: \n" << endl;
    if (f.is_open())
    {
        getline(f, s);

        while (!f.eof())
        {
            linea = p.traductorACaracter(s);
            cout << linea << endl;
            guardarLinea(linea, datos.at(2));

            getline(f, s);
        }
    }
    else
    {
        cerr << "Error de apertura del archivo." << endl;
        if (datos.at(1) != huff)
        {
            cout << "La ruta de entrada es diferente al nombre guardado en compresión" << endl;
        }
    }
    cout << "\nGuardando el reporte en la ruta: " << datos.at(2) << endl << endl;
    f.close();
    pausarPantalla();
}