#ifndef FUNCIONESCLASSCANCION_H_INCLUDED
#define FUNCIONESCLASSCANCION_H_INCLUDED
///prototypes
void agregarCancion();
void listarCancionPorId();
void listarTodasLasCanciones();
int buscarPorIDCancion(int d );
bool modificarFecha();
bool eleminarCancion();

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
        if(modificarFecha()==true){
        cout<<"Mosificacion hecha"<<endl;
        }else  cout<<"Algo salio mal"<<endl;
    system("pause");
    break;
    case 5:
        if(eleminarCancion()==true){
        cout<<"Eliminacion hecha"<<endl;
        }else  cout<<"Algo salio mal"<<endl;
        system("pause");
    break;
    default:cout<<"LA OPCION INGRESADA ES INCORRECTA"<<endl;
    system("pause");
    }

    }
}
void agregarCancion(){
     Interprete obj;
     Genero obj1;
    int pos=0;
    while((obj.leerDeDisco(pos))==1){
        pos++;
    }
     int pos1=0;
    while((obj1.leerDeDisco(pos1))==1){
        pos1++;
    }
    if(pos==0 || pos1==0){
        if(pos==0) cout<<"NO SE PUEDE AGREGAR UNA CANCION SIN UN INTERPRETE."<<endl;
        if(pos1==0)cout<<"NO SE PUEDE AGREGAR UNA CANCION SIN UN GENERO."<<endl;
    }else{
    Cancion obj2;
    int id= obj2.leerDeDisco(0);
    ///LEE EL ULTIMO REGISTRO E INDICA EL ID
    if(id<1){
    id=1;
    }else{
    int pos=0;
    while(obj2.leerDeDisco(pos)){
     pos++;}
    id=pos+1;
    }
    ///SE INGRESA EL ID DEL INTERPRETE. SI NO LO UBICA NO CREA EL REGISTRO CANCION.
    int idIn,IDG;
    cout<<"INGRESA ID DEL INTERPRETE:";cin>>idIn;
    int n= buscarPorIDInterprete(idIn);
    if(n!=-1){
         cout<<"INGRESA ID DEL Genero:";cin>>IDG;
        int n2= buscarPorIDGenero(IDG);
         if(n2!=-1){
             obj2.cargar(id,idIn,IDG);
             obj2.grabarEnDisco();
         }else cout<<"No existe tal genero con ese id."<<endl;
    }else{
    cout<<"No existe tal interprete con ese id."<<endl;}
    }

}
void listarTodasLasCanciones(){
    Cancion obj;
    int pos=0;
    while((obj.leerDeDisco(pos))==1){
         if(obj.getEstado()==1){
         obj.mostrar(true,true);
         listarInterpretePorId(obj.getIdInterprete(),true);
         listarGeneroPorId(obj.getGenero(),true);
         cout<<endl;
         }
         pos++;
    }
    if(pos==0) cout<<"No hay canciones en este archivo"<<endl;
}
void listarCancionPorId(){
    Cancion obj;
    int n;
    cout<<"INGRESA ID:";cin>>n;
    int id= buscarPorIDCancion(n);
    if(id==-1){
        cout<<"Esa cancion no se encuentra en el archivo"<<endl;
    }else if(id>=0){
     int pos=0;
     id++;
     while((obj.leerDeDisco(pos))==1){
            if(id==obj.getIdCancion()){
               if(obj.getEstado()==1){
               obj.mostrar(true,true);
               listarInterpretePorId(obj.getIdInterprete(),true);
               listarGeneroPorId(obj.getGenero(),true);
                }
            }
         pos++;
      }
    }
}
int buscarPorIDCancion(int id){
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

bool modificarFecha(){
     int n;
    cout<<"ingresar id de la cancion a modificar:";cin>>n;
    int pos= buscarPorIDCancion(n);
    if(pos==-1)return false;
    Cancion  obj;
    obj.leerDeDisco(pos);
    obj.setFecha();
    FILE *p;
    p=fopen(archivoCancion, "rb+");
    if(p==NULL)return false;
    fseek(p, sizeof obj*pos, 0);
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}
bool eleminarCancion(){
  int n;
    cout<<"ingresar id de la cancion a eleminar:";cin>>n;
    int pos= buscarPorIDCancion(n);
    if(pos==-1)return false;
     Cancion  obj;
    obj.leerDeDisco(pos);
    obj.setEstado(false);
    FILE *p;
    p=fopen(archivoCancion, "rb+");
    if(p==NULL)return false;
    fseek(p, sizeof obj*pos, 0);
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}


#endif // FUNCIONESCLASSCANCION_H_INCLUDED
