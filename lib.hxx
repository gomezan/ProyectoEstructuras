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

void ayuda(){
   string opc;

   // COMPONENTE I

   cout << "\nComandos disponibles:\n"<<endl;
   cout << "\t *Login<id_agencia> \n\t\t"
        << "Este comando pregunta al usuario por una contraseña \n\t\t"
        << "para el identificador de la agencia dado en el comando, \n\t\t"
        << "y activa la sesión si la contraseña es igual a la guardada \n\t\t"
        << "en el registro correspondiente para la agencia dada, en caso \n\t\t"
        << "contrario muestra un mensaje de error." << endl;
   cout << "\t *logout \n\t\t"
        << "Este comando termina la sesión activa de la agencia y \n\t\t"
        << "vuelve a la consola o terminal del sistema." << endl;
   cout << "\t *listar_buses \n\t\t"
        << "Imprime, con una visualización agradable, los registros de \n\t\t"
        << "los buses" << endl;
   cout << "\t *listar_rutas \n\t\t"
        << " Imprime, con una visualización agradable, los registros de \n\t\t"
        << "las rutas" << endl;
   cout << "\t *listar_viajes \n\t\t"
        << "Imprime, con una visualización agradable, los registros de \n\t\t"
        << "los viajes" << endl;
   cout << "\n\nIntroduzca cualquier letra para continuar ...";

    //COMPONENTE II

    //COMPONENTE III

   cin >> opc;

}

// COMPONENTE I

int login(string comando){

  Agency aux;
  char * buffer = (char*)malloc(DATA*sizeof(char));
  char * user = (char*)malloc(DATA*sizeof(char));
  char * contrasena = (char*)malloc(DATA*sizeof(char));
  strcpy(buffer,comando.c_str());
  string opc;

  user = strtok(buffer,"<");
  user = strtok(NULL,">");
  cout<< "Ingrese la contraseña: " <<endl;
  cin >> contrasena;

  FILE *archivo = fopen("contrasegnas.dat","r");

  if(archivo != NULL){


    char * linea = (char*)malloc(CHUNK*sizeof(char));
    char * nombre = (char*)malloc(DATA*sizeof(char));
    char * contra = (char*)malloc(DATA*sizeof(char));
    while(fgets(linea,CHUNK,archivo)){

      nombre = strtok(linea,";");
      contra = strtok (NULL,"\n");
      if(strcmp(nombre,user) == 0){
        if(strcmp(contra,contrasena) == 0){
           cout << endl<< "Bienvenido al sistema" << endl;
           cout<< "Para continuar ingrese \'s\' ..."<<endl;
            do{
               cin >> opc;
            }while(opc != "s");
           return 1;
        }
      }
    }
    cout << "Error de autenticación, no es posible ingresar al sistema, inténtelo otra vez" << endl;
    cout<< "Para continuar ingrese \'s\' ..."<<endl;
   do{
      cin >> opc;
   }while(opc != "s");
 }
  return 0;
}

void listar_buses(){
   int cuenta = 0;
   string opc;
   Bus aux;
   borrarPantalla();
   cout<<"\t\t\t\t\tLISTA DE BUSES\n"<<endl;

   FILE *archivo = fopen("buses.dat", "r");


   if(archivo != NULL){
      char *linea = (char *)malloc(CHUNK);

      while (fgets(linea, CHUNK, archivo)){

         cuenta ++;

         char * valor = strtok(linea, ";");
         aux.setcodeBus(valor);
         valor = strtok(NULL, ";");
         if(!strcmp(valor, "Corriente")){
            aux.setType('c');
         }else{
            aux.setType('s');
         }
         valor = strtok(NULL, ";");
         aux.setChairs(atoi(valor));
         cout << cuenta << ". ";
         aux.print();

         if(cuenta % 20 == 0){
            do{
               cout << "\nSe han impreso 20 registros" << endl;
               cout << "Para continuar ingrese \'s\', para salir \'n\' ..."<<endl;
               cin >> opc;
            }while(opc != "s" && opc != "n");
            if(opc == "n"){
               break;
            }
            borrarPantalla();
            cout<<"\t\t\t\t\tLISTA DE BUSES\n"<<endl;
         }
      }

   }else{
      perror("No se pudo abrir el archivo");
   }
   cout << "\nSe ha mostrado la lista con exito"<<endl;
   cout << "Para continuar ingrese \'s\' ..."<<endl;
   do{
      cin >> opc;
   }while(opc != "s");

}


void listar_rutas(){
   int cuenta = 0;
   string opc;
   Route aux;
   borrarPantalla();
   cout<<"\t\t\t\t\tLISTA DE RUTAS\n"<<endl;

   FILE *archivo = fopen("rutas.dat", "r");

   if(archivo != NULL){

      char *linea = (char *)malloc(CHUNK);

      while (fgets(linea, CHUNK, archivo)){

         cuenta ++;

         char * valor = strtok(linea, ";");
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

         if(cuenta % 20 == 0){
            do{
               cout << "\nSe han impreso 20 registros" << endl;
               cout << "Para continuar ingrese \'s\', para salir \'n\' ..."<<endl;
               cin >> opc;
            }while(opc != "s" && opc != "n");
            if(opc == "n"){
               break;
            }
            borrarPantalla();
            cout<<"\t\t\t\t\tLISTA DE RUTAS\n"<<endl;
         }
      }
   }else{
      perror("No se pudo abrir el archivo");
   }
   cout << "\nSe ha mostrado la lista con exito"<<endl;
   cout << "Para continuar ingrese \'s\' ..."<<endl;
   do{
      cin >> opc;
   }while(opc != "s");

}
void listar_viajes(){
   int cuenta = 0;
   string opc;
   Travel aux;
   borrarPantalla();
   cout<<"\t\t\t\t\tLISTA DE VIAJES\n"<<endl;

   FILE *archivo = fopen("viajes.dat", "r");

   if(archivo != NULL){

      char *linea = (char *)malloc(CHUNK);

      while (fgets(linea, CHUNK, archivo)){

         cuenta ++;

         char * valor = strtok(linea, ";");
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

         if(cuenta % 20 == 0){
            do{
               cout << "\nSe han impreso 20 registros" << endl;
               cout << "Para continuar ingrese \'s\', para salir \'n\' ..."<<endl;
               cin >> opc;
            }while(opc != "s" && opc != "n");
            if(opc == "n"){
               break;
            }
            borrarPantalla();
   cout<<"\t\t\t\t\tLISTA DE VIAJES\n"<<endl;
         }
      }
   }else{
      perror("No se pudo abrir el archivo");
   }
   cout << "\nSe ha mostrado la lista con exito"<<endl;
   cout << "Para continuar ingrese \'s\' ..."<<endl;
   do{
      cin >> opc;
   }while(opc != "s");

}


// COMPONENTE II

void disponibilidad(string comando) {
  cout << "En proceso ..." << endl;
  pausarPantalla();
}
void reserva(string comando) {
  cout << "En proceso ..." << endl;
  pausarPantalla();
}

void reporte_ventas(string comando)
{
    string s1,s2,s3;
    size_t inicio, fin;
    cout<<"en progreso"<<comando<<endl;

  inicio =comando.find_first_of('[');
  s1=comando.substr(inicio+1);
  inicio = s1.find_first_of(']');
  s2=s1.substr(0,inicio+2);
  s1=s1.substr(0,inicio+1);

  cout<<"s1: "<<s1<<endl;
  cout<<"s2: "<<s1<<endl;

}

void listar_b(){
   int cuenta = 0;
   string opc;
   Bus aux;
   borrarPantalla();
   cout<<"\t\t\t\t\tLISTA DE BUSES\n"<<endl;

   FILE *archivo = fopen("buses.dat", "r");


   if(archivo != NULL){
      char *linea = (char *)malloc(CHUNK);

      while (fgets(linea, CHUNK, archivo)){

         cuenta ++;

         char * valor = strtok(linea, ";");
         aux.setcodeBus(valor);
         valor = strtok(NULL, ";");
         if(!strcmp(valor, "Corriente")){
            aux.setType('c');
         }else{
            aux.setType('s');
         }
         valor = strtok(NULL, ";");
         aux.setChairs(atoi(valor));
         cout << cuenta << ". ";
         aux.print();

         if(cuenta % 20 == 0){
            do{
               cout << "\nSe han impreso 20 registros" << endl;
               cout << "Para continuar ingrese \'s\', para salir \'n\' ..."<<endl;
               cin >> opc;
            }while(opc != "s" && opc != "n");
            if(opc == "n"){
               break;
            }
            borrarPantalla();
            cout<<"\t\t\t\t\tLISTA DE BUSES\n"<<endl;
         }
      }

   }else{
      perror("No se pudo abrir el archivo");
   }
   cout << "\nSe ha mostrado la lista con exito"<<endl;
   cout << "Para continuar ingrese \'s\' ..."<<endl;
   do{
      cin >> opc;
   }while(opc != "s");

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

void recomendar(string comando){
    cout << "En proceso ..."<<endl;
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

void borrarPantalla(){
   system("clear");
}

void pausarPantalla(){
    cout << "Presione la tecla enter para continuar ..." <<endl;
    system("read");
}