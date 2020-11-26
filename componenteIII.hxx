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
    string s, linea, ruta;

    tablahuf prueba; //creo la tabla

    prueba.actualizarTabla("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789| :");

    arbolBinario p;
    p.crearArbolHuff(prueba); //creo el arbol
                              //pintarArbol(p.raiz);    //imprime el arbol

    if (datos.size() == 1)
    {
        ruta = huff;
    }
    else
    {
        ruta = datos.at(1);
    }

    ifstream f(ruta);

    cout << "Reporte recuperado: \n"
         << endl;
    if (f.is_open())
    {
        getline(f, s);

        while (!f.eof())
        {
            linea = p.traductorACaracter(s);

            if (datos.size() == 3)
            {
                guardarLinea(linea, datos.at(2));
            }
            else
            {
                cout << linea << endl;
            }

            getline(f, s);
        }
    }
    else
    {
        cerr << "Error de apertura del archivo." << endl;
        if (datos.size() > 2)
            if (datos.at(1) != huff)
            {
                cout << "La ruta de entrada es diferente al nombre guardado en compresión" << endl;
            }
    }
    if (datos.size() == 3)
        if (datos.size() == 3)
        {
            cout << "\nGuardando el reporte en la ruta: " << datos.at(2) << endl
                 << endl;
        }
    cout << endl;
    f.close();
    pausarPantalla();
}