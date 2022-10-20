#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

///puntos parcial

void punto1(){
//La cantidad de canciones estrenadas antes del año 2010.
    Cancion obj;
    int pos=0;
    int cantCanciones=0;
    while (obj.leerDeDisco(pos)==1){
        if(obj.getFechaDeEstreno().getAnio()<2010){
           cantCanciones++;
        }
        pos++;
    }
    cout<<"La cantidad de canciones estrenadas antes del anio 2010 es de :"<<cantCanciones<<" canciones"<<endl;

}
void punto2(){
//El mes con menor cantidad de estrenos de canciones del año 2021
 Cancion obj;
    int pos=0;
    int mesEstre[12]={0};
    while (obj.leerDeDisco(pos)==1){
        if(obj.getFechaDeEstreno().getAnio()==2021){
          mesEstre[obj.getFechaDeEstreno().getMes()-1]++;
        }
        pos++;
    }
    int menor=pos;
     for(int i=0;i<12;i++){
            if(mesEstre[i]!=0){
                    if(mesEstre[i]<menor)menor=mesEstre[i];
            }
    }
    cout<<"MESES CON MENOR CANTIDAD DE ESTRENOS EN 2021:"<<endl;
    for(int i=0;i<12;i++){
            if(mesEstre[i]==menor){
            cout<<"Mes "<<i+1<<":"<<mesEstre[i]<<" estrenos"<<endl;
            }
    }
}
class ClaseParcial{
private:
    int idCancion;
    char nombreCancion[30];
    Fecha fechaDeEstreno;
public:
    void mostrar(){
    cout<<"id:"<<idCancion<<endl;
    cout<<"nombre de la cancion:"<<nombreCancion<<endl;
    fechaDeEstreno.mostar();
    }
    int leerDeDisco(int p);
    bool grabarEnDisco();
    ///setters
    void setIdCancion(int id){
        idCancion=id;
    }
    void setNombreCancion(const char *n){
        strcpy(nombreCancion,n);
    }
      void setFechaDeEs(Fecha f){
       fechaDeEstreno=f;
    }
};
bool ClaseParcial::grabarEnDisco(){

     FILE *p;
    p=fopen("archivoParcial.dat","ab");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        return false;
    }
    bool escribio=fwrite(this, sizeof (ClaseParcial), 1,p);
    fclose(p);
    return escribio;
}
 int ClaseParcial::leerDeDisco(int pos){

   FILE *p;
    p=fopen("archivoParcial.dat","rb");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        return false;
    }
    fseek(p,pos*sizeof (ClaseParcial),0);
    int leyo=fread(this, sizeof (ClaseParcial), 1,p);
    fclose(p);
    return leyo;
}
int punto3(){
/*Dado un año que se ingresa por teclado, generar un archivo con las canciones que se hayan estrenado ese año.
Los registros deben tener el siguiente formato:
ID de canción, nombre de la canción, fecha de estreno*/
 Cancion obj;ClaseParcial objAux;
    int pos=0;
    while(objAux.leerDeDisco(pos++)==1){
        objAux.mostrar();
    }
    return 0;
    int anio;
    cout<<"ingresar anio:";cin>>anio;
    while (obj.leerDeDisco(pos)==1){
        if(obj.getFechaDeEstreno().getAnio()==anio){
        objAux.setFechaDeEs(obj.getFechaDeEstreno());
        objAux.setIdCancion(obj.getIdCancion());
        objAux.setNombreCancion(obj.getNombre());
         if(objAux.grabarEnDisco()==true){
            cout<<"se grabo correctamente"<<endl;
        }else cout<<"algo salio mal"<<endl;
        }

        pos++;
    }


}



///reportes anteriores
void punto4(){
Interprete obj;
int pos=0;
while((obj.leerDeDisco(pos))==1){
    if(obj.getNacionalidad()==5){
    obj.mostrar();
    cout<<endl;
}
    pos++;
}
}
void punto5(){
    Genero obj;

    int pos=0;
int generos[5];
for(int i=0;i<5;i++){generos[i]=0;}
while((obj.leerDeDisco(pos))==1){
    int n=obj.getInstrumento();
    generos[n-1]= generos[n-1]+1;
    pos++;
}
for(int i=0;i<5;i++){
    cout<<"el tipo de instrumentacion "<<i+1<<" tiene "<<generos[i]<<" generos"<<endl;
}
}

class NuevoInterprete{
private:
    int idInter;
    char nombre[40];
    int cantCanciones;
public:
    void mostrar(){
    cout<<"id:"<<idInter<<endl;
    cout<<"nombre:"<<nombre<<endl;
    cout<<"cantidad de canciones:"<<cantCanciones<<endl;
    }
    int leerDeDisco(int p);
    bool grabarEnDisco();
    ///setters
    void setId(int id){
        idInter=id;
    }
    void setCantCanciones(int c){
        cantCanciones=c;
    }
      void setNombre(const char *n){
        strcpy(nombre,n);
    }
};
bool NuevoInterprete::grabarEnDisco(){

     FILE *p;
    p=fopen("interpretes2021.dat","ab");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        return false;
    }
    bool escribio=fwrite(this, sizeof (NuevoInterprete), 1,p);
    fclose(p);
    return escribio;
}
 int NuevoInterprete::leerDeDisco(int pos){

   FILE *p;
    p=fopen("interpretes2021.dat","rb");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        return false;
    }
    fseek(p,pos*sizeof (NuevoInterprete),0);
    int leyo=fread(this, sizeof (NuevoInterprete), 1,p);
    fclose(p);
    return leyo;
}
void punto6(){
  Interprete obj; NuevoInterprete obj1; Cancion objAux;

  int cantCanciones[8]={0};
  int pos=0;
     while(objAux.leerDeDisco(pos)==1){
        cantCanciones[obj.getIdInterprete()-1]++;
        pos++;
  }
   pos=0;
  while(obj.leerDeDisco(pos)==1){
   if(obj.getFechaDeInicio().getAnio()==2021){
    obj1.setId(obj.getIdInterprete());
    obj1.setNombre(obj.getNombre());
    obj1.setCantCanciones(cantCanciones[obj.getIdInterprete()-1]);
    obj1.mostrar();
    if(obj1.grabarEnDisco()==1)cout<<"ok"<<endl;

   }
    pos++;
  }

}

void punto7(){
    Cancion obj1;
    int cantCanciones[8]={0};
    int pos=0;
     while(obj1.leerDeDisco(pos)==1){
        cantCanciones[obj1.getIdInterprete()-1]++;
        pos++;
    }
    cout<<"Cantidad de canciones registradas por cada genero:"<<endl;
    for(int i=0;i<8;i++){
        cout<<"Interprete "<<i+1<<":"<<cantCanciones[i]<<"canciones"<<endl;
    }
}
void punto8(){
    Cancion obj1;
    int n;
    cout<<"ingresar el numero de genero:";cin>>n;
    if(n>0 && n<11){
    cout<<"canciones:"<<endl;
    int pos=0;
     while(obj1.leerDeDisco(pos)==1){
        if(obj1.getGenero()==n){
         obj1.mostrar();
         cout<<endl;
        }
        pos++;}
    }else cout<< "solo hay 10 generos"<<endl;

}
int reportes(){
  /* NuevoInterprete obj1;
    int pos=0;
     while(obj1.leerDeDisco(pos)==1){
            obj1.mostrar();
           cout<<"<hol2>"<<endl;
        pos++;
    }

system("pause");

return 0;*/
 int opc;
    while(true){
    system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1) PUNTO A PARCIAL"<<endl;
    cout<<"2) PUNTO B PARCIAL"<<endl;
    cout<<"3) PUNTO C PARCIAL"<<endl;
    cout<<"4) LISTAR LOS INTERPRETES DE NACIONALIDAD ARGENTINA"<<endl;
    cout<<"5) CANTIDAD DE GENEROS POR CADA TIPO DE INSTRUMENTACION"<<endl;
    cout<<"6) PUNTO c MODELO"<<endl;
    cout<<"7) MOSTRAR POR CADA INTERPRETE LA CANTIDAD DE CANCIONES QUE TIENE REGISTRADAS"<<endl;
    cout<<"8) INFORMAR LAS CANCIONES DE UN GENERO QUE SE INGRESE POR TECLADO"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"0) FIN DEL PROGRAMA"<<endl<<endl;

    cout<<"SELECCIONE UNA DE LAS OPCIONES:";cin>>opc;
    system("cls");
    switch(opc){
    case 0:
    return 0;
    break;
    case 1:
    punto1();
    system("pause");
    break;
    case 2:
    punto2();
    system("pause");
    break;
    case 3:
    punto3();
    system("pause");
    break;
    case 4:
    punto4();
    system("pause");
    break;
    case 5:
    punto5();
    system("pause");
    break;
    case 6:
    punto6();
    system("pause");
    break;
    case 7:
    punto7();
    system("pause");
    break;
    case 8:
    punto8();
    system("pause");
    break;
    default:cout<<"LA OPCION INGRESADA ES INCORRECTA"<<endl;
    system("pause");
    }

    }
}

#endif // REPORTES_H_INCLUDED
