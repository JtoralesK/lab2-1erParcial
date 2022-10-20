#ifndef CONFIGUARION_H_INCLUDED
#define CONFIGUARION_H_INCLUDED
void resetearCancion(){
    Cancion obj;
    obj.resetearArchivo();
    cout<<"se reseteo"<<endl;
}
void resetearinterprete(){
    Interprete obj;
    obj.resetearArchivo();
    cout<<"se reseteo"<<endl;

}
void resetearGenero(){
    Genero obj;
    obj.resetearArchivo();
    cout<<"se reseteo"<<endl;
}
int config(){

 int opc;
    while(true){
    system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1) RESETEAR ARCHIVO CANCION"<<endl;
    cout<<"2) RESETEAR ARCHIVO INTERPRETE"<<endl;
    cout<<"3) RESETEAR ARCHIVO GENERO"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"0) FIN DEL PROGRAMA"<<endl<<endl;

    cout<<"SELECCIONE UNA DE LAS OPCIONES:";cin>>opc;
    system("cls");
    switch(opc){
    case 0:
    return 0;
    break;
    case 1:
    resetearCancion();
    system("pause");
    break;
    case 2:
    resetearinterprete();
    system("pause");
    break;
    case 3:
    resetearGenero();
    system("pause");
    break;
    default:cout<<"LA OPCION INGRESADA ES INCORRECTA"<<endl;
    system("pause");
    }

    }
}


#endif // CONFIGUARION_H_INCLUDED
