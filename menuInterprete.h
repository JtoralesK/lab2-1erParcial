#ifndef FUNCIONESCLASSINTERPRETE_H_INCLUDED
#define FUNCIONESCLASSINTERPRETE_H_INCLUDED
///prototypes
bool agregarInterprete( );
bool listarInterpretePorId(int n=0,bool use=false);
void listarTodasLosInterpretes();
int buscarPorIDInterprete(int d);
bool modificarGenero();
int eleminarInterprete();

int  menuInterpretes(){
int opc,n;
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
    listarInterpretePorId();
    system("pause");
    break;
    case 3:
    listarTodasLosInterpretes();
    system("pause");
    break;
    case 4:
    if(modificarGenero()){
        cout<<"ok"<<endl;
    }else cout<<"algo salio mal"<<endl;
    system("pause");
    break;
    case 5:
    n=eleminarInterprete();
    if(n<0){
     if(n==-1)cout<<"no se encontro ese registro"<<endl;
     if(n==-2)cout<<"hubo un error con el archivo"<<endl;
    }
    system("pause");
    break;
    default:cout<<"LA OPCION INGRESADA ES INCORRECTA"<<endl;
    system("pause");
    }

    }
}
bool agregarInterprete(){
    Interprete obj;Genero obj1;
    int pos=0;
    ///contando cuantos registros de genero hay
    while((obj1.leerDeDisco(pos))==1){pos++;}

    if(pos==0){
       cout<<"NO SE PUEDE AGREGAR UNA CANCION SIN UN GENERO."<<endl;
       return false;
       }
        int IDG;
         cout<<"INGRESA ID DEL Genero:";cin>>IDG;
         int n= buscarPorIDGenero(IDG);
         if(n!=-1){
            int id= obj.leerDeDisco(0);
            if(id<1){
            id=1;
            }else{
            int pos=0;
            while(obj.leerDeDisco(pos)){pos++;}
            id=pos+1;
            }
            n++;
            obj.cargar(id,n);
            obj.grabarEnDisco();
            return true;
            }else{
                 cout<<"No existe tal genero con ese id."<<endl;
                return false;
            }
}
void listarTodasLosInterpretes(){
    Interprete obj;
    int pos=0;
    while((obj.leerDeDisco(pos))==1){
         if(obj.getEstado()==1){
            obj.mostrar(false,true);
            listarGeneroPorId(obj.getGeneroMusical(),true);
            cout<<endl;
         }
         pos++;
    }
    if(pos==0)cout<<"no se encuentran interpretes en este archivo"<<endl;
}
bool listarInterpretePorId(int n,bool use){
    Interprete obj;
    if(n==0){
    cout<<"INGRESA ID:";cin>>n;
    }
    int id= buscarPorIDInterprete(n);
    if(id==-1){
        cout<<"Esa cancion no se encuentra en el archivo"<<endl;
        return false;
    }
    id++;
     int pos=0;
     while((obj.leerDeDisco(pos))==1){
            if(obj.getIdInterprete()==id){
               if(obj.getEstado()==1){
                obj.mostrar(false,true);
                listarGeneroPorId(obj.getGeneroMusical(),true);
         }
            }
         pos++;
      }
    return true;
}
int buscarPorIDInterprete(int id){
    Interprete obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==1){
        if(obj.getIdInterprete()==id){
           return pos;
        }
        pos++;
    }
     return -1;
}

bool modificarGenero(){
     int n;
    cout<<"ingresar id del interprete a modificar:";cin>>n;
    int pos= buscarPorIDInterprete(n);
    if(pos==-1)return false;
    Interprete  obj;
    obj.leerDeDisco(pos);
    int gM;
     cout<<"INGRESA TIPO DE GENERO MUSICAL(1-10):";cin>>gM;
     if(!(obj.setGeneroMusical(gM))){
      cout<<"EL TIPO DE GENERO MUSICAL SOLO PUEDE SER ENTRE 1 Y 10"<<endl;
      return false;
     }else{
    obj.setGeneroMusical(gM);
    FILE *p;
    p=fopen(archivoInterprete, "rb+");
    if(p==NULL)return false;
    fseek(p, sizeof obj*pos, 0);
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
     }

}
int eleminarInterprete(){
  int n;
    cout<<"ingresar id del interprete a eleminar:";cin>>n;
    int pos= buscarPorIDInterprete(n);
    if(pos==-1)return -1;
    Interprete  obj;
    obj.leerDeDisco(pos);
    obj.setEstado(false);
    FILE *p;
    p=fopen(archivoInterprete, "rb+");
    if(p==NULL)return -2;
    fseek(p, sizeof obj*pos, 0);
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}


#endif // FUNCIONESCLASSINTERPRETE_H_INCLUDED
