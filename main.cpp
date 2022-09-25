#include <iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
const char *archivoCancion="archivoCancion.dat";
const char *archivoInterprete="archivoInterprete.dat";


using namespace std;
#include "funcionesGlobales.h"
#include "ClassFecha.h"
#include "ClassCancion.h"
#include "ClassInterprete.h"
#include "funcionesClassCancion.h"
#include "funcionesClassInterprete.h"

int main(){
    int opc;

    while(true){
    system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1) MENU CANCIONES"<<endl;
    cout<<"2) MENU INTERPRETES"<<endl;
    cout<<"3) REPORTES"<<endl;
    cout<<"4) CONFIGURACION"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"0) FIN DEL PROGRAMA"<<endl<<endl;

    cout<<"SELECCIONE UNA DE LAS OPCIONES:";cin>>opc;
    system("cls");
    switch(opc){
    case 0:
    return 0;
    break;
    case 1:
    menuCancion();
    break;
    case 2:
    menuInterpretes();
    break;
    case 3:
    cout<<archivoCancion<<endl;
    system("pause");
    break;
     case 4:
    cout<<"entro"<<endl;
    system("pause");
    break;
    default:cout<<"LA OPCION INGRESADA ES INCORRECTA"<<endl;
    system("pause");
    }

    }
    return 0;
}
