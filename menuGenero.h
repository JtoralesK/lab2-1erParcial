#ifndef MENUGENERO_H_INCLUDED
#define MENUGENERO_H_INCLUDED
///prototypes
void agregarGenero();
void listarTodasLosGeneros();
void listarGeneroPorId(int n=0,bool use=false);
int buscarPorIDGenero(int id);
bool modificarTipoDeInst();

int  menuGenero(){
int opc;
 while(true){
    system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1) AGREGAR GENERO"<<endl;
    cout<<"2) LISTAR GENERO POR ID"<<endl;
    cout<<"3) LISTAR TODOS LOS GENEROS"<<endl;
    cout<<"4) MODIFICAR TIPO DE INSTRUMENTACION"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;

    cout<<"SELECCIONE UNA DE LAS OPCIONES:";cin>>opc;
    system("cls");
    switch(opc){
    case 0:
    return 0;
    break;
    case 1:
    agregarGenero();
    system("pause");
    break;
    case 2:
    listarGeneroPorId();
    system("pause");
    break;
    case 3:
    listarTodasLosGeneros();
    system("pause");
    break;
    case 4:
    modificarTipoDeInst();
    system("pause");
    break;
    default:cout<<"LA OPCION INGRESADA ES INCORRECTA"<<endl;
    system("pause");
    }

    }
}

void agregarGenero(){
    Genero obj;
    int id= obj.leerDeDisco(0);
    if(id<1){
    id=1;
    }else{
    int pos=0;
    while(obj.leerDeDisco(pos)){pos++;}
    id=pos+1;
    }
    obj.cargar(id);
    obj.grabarEnDisco();
    cout<<"Registro grabado con exito"<<endl;
}
void listarTodasLosGeneros(){
    Genero obj;
    int pos=0;
    while((obj.leerDeDisco(pos++))==1){
         obj.mostrar();cout<<endl;
    }
}
void listarGeneroPorId(int n,bool use){
    Genero obj;
    if(n==0){cout<<"INGRESA ID:";cin>>n;}
    int id= buscarPorIDGenero(n);
    if(id==-1){
        cout<<"Ese genero no se encuentra en el archivo"<<endl;
    }else{
     id++;
     int pos=0;
     while((obj.leerDeDisco(pos))==1){
            if(obj.getIdGenero()==id){
               obj.mostrar(use);
            }
         pos++;
      }
    }

}
int buscarPorIDGenero(int id){
    Genero obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
        if(obj.getIdGenero()==id){
           return pos;
        }
        pos++;
    }
     return -1;
}

bool modificarTipoDeInst(){
     int n;
    cout<<"ingresar id del genero a modificar:";cin>>n;
    int pos= buscarPorIDGenero(n);
    if(pos==-1){
        cout<<"Ese id no existe"<<endl;
        return false;}
    Genero  obj;
    obj.leerDeDisco(pos);
    int gM;
     cout<<"INGRESA TIPO INSTRUMENTACION(1-5):";cin>>gM;
     if(!(obj.setInstrumento(gM))){
      cout<<"EL TIPO TIPO INSTRUMENTACION ES DE 1 A 5"<<endl;
      return false;
     }
    obj.setInstrumento(gM);
    FILE *p;
    p=fopen(archivoGenero, "rb+");
    if(p==NULL)return -2;
    fseek(p, sizeof obj*pos, 0);
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}



#endif // MENUGENERO_H_INCLUDED
