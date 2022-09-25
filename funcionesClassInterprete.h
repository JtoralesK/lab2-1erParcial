#ifndef FUNCIONESCLASSINTERPRETE_H_INCLUDED
#define FUNCIONESCLASSINTERPRETE_H_INCLUDED
void agregarInterprete();
void listarTodasLosInterpretes();

int  menuInterpretes(){
int opc;
 while(true){
    system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1) AGREGAR INTERPRETE"<<endl;
    cout<<"2) LISTAR INTERPRETE POR ID"<<endl;
    cout<<"3) LISTAR TODOS LOS INTERPRETES"<<endl;
    cout<<"4) MODIFICAR GENERO MUSICAL PRINCIPAL"<<endl;
    cout<<"5) ELIMINAR INTERPRETE"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;

    cout<<"SELECCIONE UNA DE LAS OPCIONES:";cin>>opc;
    system("cls");
    switch(opc){
    case 0:
    return 0;
    break;
    case 1:
    agregarInterprete();
    system("pause");
    break;
    case 2:
    cout<<"entro"<<endl;
    system("pause");
    break;
    case 3:
    listarTodasLosInterpretes();
    system("pause");
    break;
    case 4:
    cout<<"entro"<<endl;
    system("pause");
    break;
    case 5:
    cout<<"entro"<<endl;
    system("pause");
    break;
    default:cout<<"LA OPCION INGRESADA ES INCORRECTA"<<endl;
    system("pause");
    }

    }
}
void agregarInterprete(){
    Interprete obj;
    int id= obj.leerDeDisco(0);
    if(id<1){
    id=1;
    }else{
    int pos=0;
    while(obj.leerDeDisco(pos)){
     pos++;}
    id=pos+1;
    }
    obj.cargar(id);
    obj.grabarEnDisco();

}
void listarTodasLosInterpretes(){

    Interprete obj;
    int pos=0;
    while((obj.leerDeDisco(pos++))==1){
         obj.mostrar();
         cout<<endl;
    }

}
int buscarPorIDe(int id){

    Cancion obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
        if(obj.getIdCancion()==id){
           return pos;
        }
        pos++;
    }
     return -1;
}
void resetearArchivoo(){
    Cancion obj;
    obj.resetearArchivo();
}
#endif // FUNCIONESCLASSINTERPRETE_H_INCLUDED
