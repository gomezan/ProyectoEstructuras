/*
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

/*
    g++ -o prueba transporte.cpp -lreadline
*/

#include "principal.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include <readline/history.h>
#include <readline/readline.h>

vector<string> vocabulory{
    "ayuda",
    // COMPONENTE I
    "login", "logout", "listar_buses", "listar_rutas", "listar_viajes",
    // COMPONENTE II
    "disponibilidad", "reserva", "reporte_ventas", "cancelar", "cambiar",
    // COMPONENTE III
    "recomendar", "comprimir", "descomprimir"};

char *command_generator(const char *text, int state)
{
    static vector<string> matches;
    static size_t match_index = 0;

    if (state == 0)
    {
        matches.clear();
        match_index = 0;

        string textstr(text);
        for (auto word : vocabulory)
        {
            if (word.size() >= textstr.size() &&
                word.compare(0, textstr.size(), textstr) == 0)
            {
                matches.push_back(word);
            }
        }
    }

    if (match_index >= matches.size())
    {
        return nullptr;
    }
    else
    {
        return strdup(matches[match_index++].c_str());
    }
}

char **command_completion(const char *text, int start, int end)
{
    rl_attempted_completion_over = 1;
    return rl_completion_matches(text, command_generator);
}

int main(int argc, char **argv)
{
    string agencia;
    if (argc > 1 && string(argv[1]) == "-d")
    {
        rl_bind_key('\t', rl_insert);
    }
    int log = 0;
    borrarPantalla();
    rl_attempted_completion_function = command_completion;

    char *buf;
    string cmd;

    while ((buf = readline("|| PROGRAMA DE TRANSPORTE || \n\nIntroduzca un comando:\n$ ")) != nullptr)
    {
        borrarPantalla();

        cmd = string(buf);

        string comando = cmd;

        if (cmd.size() > 0)
        {
            add_history(buf);
        }
        free(buf);
        stringstream scmd(cmd);
        scmd >> cmd;

        vector<string>::iterator itr =
            find(vocabulory.begin(), vocabulory.end(), cmd);
        if (itr != vocabulory.end())
        {

            // COMPONENTE I

            if (cmd.find("login") != std::string::npos)
            {
                vector<string> datos = split(comando, " ");
                agencia = datos.at(1);
                log = login(comando);
            }
            else if (cmd.find("ayuda") != std::string::npos)
            {
                ayuda();
            }
            else if (log == 0)
            {
                cout << "Primero debe registrarse." << endl;
                pausarPantalla();
            }
            else
            {
                if (cmd.find("logout") != std::string::npos)
                {
                    cout << "Gracias por usar el || PROGRAMA DE TRANSPORTE ||." << endl;
                    return 0;
                }
                if (cmd.find("listar_buses") != std::string::npos)
                {
                    listar_buses();
                }
                if (cmd.find("listar_rutas") != std::string::npos)
                {
                    listar_rutas();
                }
                if (cmd.find("listar_viajes") != std::string::npos)
                {
                    listar_viajes();
                }

                // COMPONENTE II

                if (cmd.find("disponibilidad") != std::string::npos)
                {
                    vector<string> datos = disponibilidad(comando, "s");
                    for (int i = 0; i < datos.size(); i++)
                    {
                        cout << datos.at(i) << endl;
                    }
                }
                if (cmd.find("reserva") != std::string::npos)
                {
                    reserva(comando, agencia);
                }
                if (cmd.find("reporte_ventas") != std::string::npos)
                {
                    reporte_ventas(comando, 1);
                }
                if (cmd.find("cancelar") != std::string::npos)
                {
                    cancelar(comando);
                }
                if (cmd.find("cambiar") != std::string::npos)
                {
                    cambiar(comando, agencia);
                }

                // COMPONENTE III

                if (cmd.find("recomendar") != std::string::npos)
                {
                    recomendar(comando);
                }

                if (cmd == "comprimir")
                {
                    comprimir(comando);
                }

                if (cmd.find("descomprimir") != std::string::npos)
                {
                    descomprimir(comando);
                }
            }
        }
        else
        {
            cout << "|| PROGRAMA DE TRANSPORTE || \n"
                 << endl;
            cout << "ERROR: comando no registrado." << std::endl;
            pausarPantalla();
        }
    }

    cout << endl;
    return 0;
}
