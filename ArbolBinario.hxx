/**
 * Estructuras de datos
 * Nombre del archivo: Bus.hxx
 * Autores: Carlos Andres Erazo Garzon
 *          Nicolas Gil
 *          Andres Gomez
 * Fecha: 20/11/2020
 * Descripcion: Funciones de la estructura arbolBinario
 * */

#include "clases.h"

//
// Realiza la traduccion de una cadena de caracteres a codigo huffman
//
string arbolBinario ::traductorACaracter(string linea)
{

     map<string, char>::iterator itr;
     int tam = linea.size() / 7;
     string res = "";
     string aux, chunk;

     aux = linea;
     for (int i = 0; i < tam; i++)
     {
          chunk = aux.substr(0, 7);
          itr = interpreteHC.find(chunk);
          res = res + itr->second;
          //cout <<res<<endl;
          aux = aux.substr(7);
     }

     return res;
}

//
// Realiza la traduccion de una cadena de caracteres a codigo huffman
//
string arbolBinario ::traductorAHuffman(string linea)
{

     map<char, string>::iterator itr;
     string res = "";

     for (int i = 0; i < linea.size(); i++)
     {
          itr = interpreteCH.find(linea[i]);
          //cout <<itr->second<<endl;
          res = res + itr->second;
     }

     return res;
}

//
//actualiza los mapas que almacenan la logica de la codificación de Huffman
//

void arbolBinario ::actualizarDiccionarios(nodo *node, string codigo)
{
     if (node != NULL)
     {
          if ((node->izquierdo == NULL) && (node->derecho == NULL))
          { //soy una hoja
               codigo = completarZeros(codigo);
               //cout<<"soy "<<node->datos<<" mi codigo es "<<codigo<<endl;
               interpreteCH.insert(pair<char, string>(node->datos, codigo));
               interpreteHC.insert(pair<string, char>(codigo, node->datos));
          }
          else
          {
               if (node->izquierdo != NULL)
               {
                    actualizarDiccionarios(node->izquierdo, codigo + "0");
               }
               if (node->derecho != NULL)
               {
                    actualizarDiccionarios(node->derecho, codigo + "1");
               }
          }
     }
}

//
//Garantiza que la contraseña tiene un tamaño de 6
//
string arbolBinario ::completarZeros(string codigo)
{
     int tam = 7 - codigo.size();
     string auxiliar = codigo;
     for (int i = 0; i < tam; i++)
          auxiliar = auxiliar + "0";
     return auxiliar;
}

/*
Para pintar arbol o estructuras de nodos.
*/

void pintarArbol(nodo *raiz)
{
     if (raiz == NULL)
     {
          return;
     }
     cout << "data: " << raiz->datos << " f: " << raiz->frecuencia << endl;

     if (raiz->izquierdo != NULL)
     {
          //cout<<"izq: " <<raiz ->izquierdo->datos<<" f: " <<raiz->izquierdo->frecuencia<<endl;
          pintarArbol(raiz->izquierdo);
     }

     if (raiz->derecho != NULL)
     {
          //cout<<"der: " <<raiz ->derecho->datos<<" f: " <<raiz->derecho->frecuencia<<endl;
          pintarArbol(raiz->derecho);
     }
}

//ELIMINA TODOS LOS NODOS DESCENDIENTES DE UN NODO
void borrar(nodo *raiz)
{

     if ((raiz->izquierdo) != NULL)
     {
          borrar(raiz->izquierdo);
          delete raiz->izquierdo;
          raiz->izquierdo = NULL;
     }

     if ((raiz->derecho) != NULL)
     {
          borrar(raiz->derecho);
          delete raiz->derecho;
          raiz->derecho = NULL;
     }

     //cout<< "BORRAR:" <<raiz ->datos<< endl;
     return;
}

/*
/Crea el arbol para realizar la codificaciòn de Huffman.
/
*/

void arbolBinario ::crearArbolHuff(tablahuf base)
{

     vector<nodo *> faltantes;
     pair<int, int> menores;
     nodo *res;
     int tam = 0;

     for (int i = 0; i < base.indice.size(); i++)
     { //filtro

          if (base.indice[i].frecuencia != 0)
          {
               faltantes.push_back(new nodo(base.indice[i].caracter, base.indice[i].frecuencia));
          }
     }

     tam = faltantes.size();

     for (int j = 1; j < tam; j++)
     {

          /* VERB
    cout<<"ROUND************ "<<j<<endl;
    cout<<"al principio"<<endl;
     for( int i=0;i<faltantes.size();i++){  //verb
     cout<<i<<" : ";
     cout<<faltantes[i]->datos<<" , ";
     cout<<faltantes[i]->frecuencia<<endl;
     cout<<"contenido"<<endl;
     pintarArbol(faltantes[i]);
     }*/
          //cout<<endl;

          menores = encontrarMenores(faltantes);
          //cout<<menores.first<<"  "<<menores.second<<" "<<endl;

          res = joinArboles(faltantes[menores.first], faltantes[menores.second]);
          //cout<<"pintar nuevo arbol"<<endl;
          //pintarArbol(res);

          //cout<<endl;

          //Se borra un nodo y se sobrescribe el proximo
          if (menores.first < menores.second)
          {
               //borrar(faltantes[menores.second]);
               faltantes.erase(faltantes.begin() + menores.second);
               //borrar(faltantes[menores.first]);
               faltantes[menores.first] = res;
          }
          else
          {
               //borrar(faltantes[menores.first]);
               faltantes.erase(faltantes.begin() + menores.first);
               //borrar(faltantes[menores.second]);
               faltantes[menores.second] = res;
          }
     }

     raiz = res;
     actualizarDiccionarios(raiz, "");
}

/*
Une los nodos dados
*/

nodo *arbolBinario ::joinArboles(nodo *a, nodo *b)
{
     /*
   cout<<"me llega a "<<endl;
  pintarArbol(a);
  cout<<"me llega b "<<endl;
  pintarArbol(b);
*/
     nodo *res = new nodo('!', a->frecuencia + b->frecuencia);
     res->izquierdo = a;
     res->derecho = b;

     return res;
}

/*
/Obtiene las posiciones de los dos arboles con menor frecuencia.
/
*/

pair<int, int> arbolBinario ::encontrarMenores(vector<nodo *> faltantes)
{
     pair<int, int> menores;

     if (faltantes[0]->frecuencia <= faltantes[1]->frecuencia)
     {
          menores.first = 0;
          menores.second = 1;
     }
     else
     {
          menores.first = 1;
          menores.second = 0;
     }

     for (int i = 2; i < faltantes.size(); i++)
     {
          if (faltantes[i]->frecuencia < faltantes[menores.first]->frecuencia)
          {
               //cout<<"hay cambio 1 "<<menores.first<<"  "<<i<<" ";
               menores.second = menores.first;
               menores.first = i;
          }

          else if (faltantes[i]->frecuencia < faltantes[menores.second]->frecuencia)
          {
               //cout<<"hay cambio 2 "<<menores.second<<"  "<<i<<" ";
               menores.second = i;
          }
     }

     return menores;
}

void arbolBinario ::preOrden(nodo *node)
{
     if (raiz != NULL)
     {
          cout << node->datos << " ";
          if (node->izquierdo != NULL)
               preOrden(node->izquierdo);
          if (node->derecho != NULL)
               preOrden(node->derecho);
     }
}

void arbolBinario ::enOrden(nodo *node)
{
     if (node != NULL)
     {
          if (node->izquierdo != NULL)
               enOrden(node->izquierdo);
          cout << node->datos << " ";
          if (node->derecho != NULL)
               enOrden(node->derecho);
     }
}

void arbolBinario ::postOrden(nodo *node)
{
     if (node != NULL)
     {
          if (node->izquierdo != NULL)
               postOrden(node->izquierdo);
          if (node->derecho != NULL)
               postOrden(node->derecho);
          cout << node->datos << " ";
     }
}