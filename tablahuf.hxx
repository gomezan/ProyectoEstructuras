/**
 * Estructuras de datos
 * Nombre del archivo: Bus.hxx
 * Autores: Carlos Andres Erazo Garzon
 *          Nicolas Gil
 *          Andres Gomez
 * Fecha: 20/11/2020
 * Descripcion: Funciones de la estructura tablahuf
 * */

#include "clases.h"

//imprime el vector del indice
void tablahuf:: imprimirIndice()
{
  for(int i=0; i<indice.size();i++){
   cout<<i<<" carac: "<<indice[i].caracter<<" frecuencia "<<indice[i].frecuencia<<endl;
  }
   cout << endl;

}

//cuenta actualiza la frecuencia de apariciòn de un caracter

void tablahuf:: actualizarTabla(string frase)
{
  int ascii;

  for(int i=0; i<frase.size();i++){
  ascii=(int) (frase[i]);
   //cout<<ascii<<endl;
   if(124==ascii)
   {
    indice[26].frecuencia++;
   }
   else if(97<=ascii){
    indice[ascii-97].frecuencia++;
   }
   else if (65<=ascii){
    indice[ascii-38].frecuencia++;
   }
   else if (48<=ascii){
    indice[ascii+5].frecuencia++;
   }
   else{
    indice[64].frecuencia++;
   }

  }
   cout << endl;

}