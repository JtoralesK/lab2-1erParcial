#include <iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
const char *archivoCancion="archivoCancion.dat";
const char *archivoInterprete="archivoInterprete.dat";
const char *archivoGenero="archivoGenero.dat";


using namespace std;
#include "funcionesGlobales.h"
#include "ClassFecha.h"
#include "ClassCancion.h"
#include "ClassInterprete.h"
#include "ClassGenero.h"
#include "menuGenero.h"
#include "menuInterprete.h"
#include "menuCancion.h"
#include "reportes.h"
#include "configuracion.h"
int main(){
    int opc;
    while(true){
    system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1) MENU GENEROS"<<endl;
    cout<<"2) MENU INTERPRETES"<<endl;
    cout<<"3) MENU CANCIONES"<<endl;
    cout<<"4) REPORTES"<<endl;
    cout<<"5) CONFIGURACION"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"0) FIN DEL PROGRAMA"<<endl<<endl;

    cout<<"SELECCIONE UNA DE LAS OPCIONES:";cin>>opc;
    system("cls");
    switch(opc){
    case 0:
    return 0;
    break;
    case 1:
    menuGenero();
    break;
    case 2:
    menuInterpretes();
    break;
    case 3:
    menuCancion();
    break;
     case 4:
    reportes();
    break;
    case 5:
    config();
    break;
    default:cout<<"LA OPCION INGRESADA ES INCORRECTA"<<endl;
    system("pause");
    }

    }
    return 0;
}
