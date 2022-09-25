#ifndef FUNCIONESCLASSCANCION_H_INCLUDED
#define FUNCIONESCLASSCANCION_H_INCLUDED
///prototypes
void agregarCancion( );
void listarCancionPorId();
void listarTodasLasCanciones();
int buscarPorID(int );
void resetearArchivo();
int modificarFecha();

int menuCancion(){
int opc;
 while(true){
    system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1) AGREGAR CANCION"<<endl;
    cout<<"2) LISTAR CANCION POR ID"<<endl;
    cout<<"3) LISTAR TODAS LAS CANCIONES"<<endl;
    cout<<"4) MODIFICAR FECHA DE ESTRENO"<<endl;
    cout<<"5) ELIMINAR CANCION"<<endl;
    cout<<"6) ELIMINAR ARCHIVO"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;

    cout<<"SELECCIONE UNA DE LAS OPCIONES:";cin>>opc;
    system("cls");
    switch(opc){
    case 0:
    return 0;
    break;
    case 1:
    agregarCancion();
    system("pause");
    break;
    case 2:
    listarCancionPorId();
    system("pause");
    break;
    case 3:
    listarTodasLasCanciones();
    system("pause");
    break;
    case 4:
    modificarFecha();
    system("pause");
    break;
    case 5:
    cout<<"entro"<<endl;
    system("pause");
    break;
    case 6:
    resetearArchivo();
    system("pause");
    break;
    default:cout<<"LA OPCION INGRESADA ES INCORRECTA"<<endl;
    system("pause");
    }

    }
}
void agregarCancion(){
    Cancion obj;
    int id= obj.leerDeDisco(0);
    if(id<1){
    id=1;
    }else{
    int pos=0;
    while(obj.leerDeDisco(pos)){
     pos++;}
    id=pos+1;
    }
    cout<<"id de la cancion:"<<id<<endl;
    obj.cargar(id);
    obj.grabarEnDisco();

}
void listarTodasLasCanciones(){
    Cancion obj;
    int pos=0;
    while((obj.leerDeDisco(pos++))==1){
         obj.mostrar();
         cout<<endl;
    }
}
void listarCancionPorId(){
    Cancion obj;
    int n;
    cout<<"INGRESA ID:";cin>>n;
    int id= buscarPorID(n)+1;
    cout<<"id "<<id<<endl;
    if(id==-1){
        cout<<"Esa cancion no se encuentra en el archivo"<<endl;
    }else if(id>0){
     int pos=0;
     while((obj.leerDeDisco(pos))==1){
            if(obj.getIdCancion()==id){
               obj.mostrar();
            }
         pos++;
      }
    }
}
int buscarPorID(int id){

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
void resetearArchivo(){
    Cancion obj;
    obj.resetearArchivo();
}
int modificarFecha(){
     int n;
    cout<<"ingresar id de la cancion a modificar:";cin>>n;
    int pos= buscarPorID(n);
    if(pos==-1){
        cout<<"no se encontro ese registro"<<endl;
        system("pause");
        return -1;
    }
    Cancion  obj;
    obj.leerDeDisco(pos);
    obj.setFecha();
    FILE *p;
    p=fopen(archivoCancion, "rb+");
    if(p==NULL)return false;
    fseek(p, sizeof obj*pos, 0);
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}


#endif // FUNCIONESCLASSCANCION_H_INCLUDED
