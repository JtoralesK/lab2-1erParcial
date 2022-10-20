#ifndef CLASSCANCION_H_INCLUDED
#define CLASSCANCION_H_INCLUDED

class Cancion{
private:
    int idCancion;
    char nombre[30];
    char autor [30];
    int idInterprete;
    Fecha fechaDeEstreno;
    float duracion;
    int genero;
    bool estado;
public:
    void cargar(int id,int idInte,int gene);
    void mostrar(bool idInter,bool genero);
    ///funciones de archivo
    int leerDeDisco(int p);
    bool grabarEnDisco();
    bool modificarEndisco();
    void resetearArchivo();
    ///setteeeeeeeeeeeeeeeeeers
    bool setIdCancion(int id){
        if(id>0){
           idCancion=id;
           return true;
        }return false;
    }
     void setNombre(const char *n){
        strcpy(nombre,n);
    }
     void setAutor(const char *a){
        strcpy(autor,a);
    }
     bool setIdInterprete(int id){
        if(id>0){
           idInterprete=id;
           return true;
        }return false;
    }
    bool setDuracion(float d){
        if(d>0){
            duracion=d;
            return true;
        }return false;
    }
     bool setGenero(float d){
        if(d>0 && d<11){
            genero=d;
            return true;
        }return false;
    }
    void setFecha(){
        fechaDeEstreno.cargar();
    }
    void setEstado(bool e){
        estado=e;
    }

    ///getteeeeeeeeeeeeeeeeeers
     int getIdCancion(){return idCancion;}
     const char* getNombre(){return nombre;}
     const char* getAutor(){return autor;}
     int getIdInterprete(){return idInterprete;}
     float getDuracion(){return duracion;}
     int getGenero(){return genero;}
     bool getEstado(){return estado;}
     Fecha getFechaDeEstreno(){return fechaDeEstreno;}

};
///funcion cargar
void Cancion::cargar(int id=0,int idInter=0, int gene=0){
    if(id!=0){
     idCancion=id;
    }
     if(idInter!=0){
     idInterprete=idInter;
    }
    if(gene==0){
     cout<<"INGRESA GENERO(1-10):";cin>>genero;
     while(!(setGenero(genero))){
     cout<<"EL GENERO ES ENTRE EL 1 Y 10"<<endl;
     cout<<"INGRESA GENERO(1-10):";cin>>genero;
     }
    }else genero=gene;
     cout<<"INGRESA EL NOMBRE DE LA CANCION:";cargarCadena(nombre,29);
     cout<<"INGRESA EL AUTOR DE LA CANCION:";cargarCadena(autor,29);
     cout<<"INGRESA DURACION DE LA CANCION:";cin>>duracion;
     while(!(setDuracion(duracion))){
     cout<<"LA DURACION ES POSITIVA"<<endl;
     cout<<"INGRESA DURACION DE LA CANCION:";cin>>duracion;
     }

     cout<<"INGRESA FECHA DE ESTRENO:"<<endl;fechaDeEstreno.cargar();
     estado=true;
     genero=gene;
}
///funcion mostrar
void Cancion::mostrar(bool idInter=false,bool gene=false){
    if(estado==true){
     cout<<"ID DE LA CANCION:"<<idCancion<<endl;
     cout<<"NOMBRE DE LA CANCION:"<<nombre<<endl;
     cout<<"NOMBRE DEL AUTOR:"<<autor<<endl;
     cout<<"DURACION:"<<duracion<<endl;
     if(!gene)cout<<"GENERO:"<<genero<<endl;
     cout<<"FECHA DE ESTRENO:";fechaDeEstreno.mostar();
    if(!idInter)cout<<"ID DE INTERPRETE:"<<idInterprete<<endl;
    }
}
bool Cancion::grabarEnDisco(){

     FILE *p;
    p=fopen(archivoCancion,"ab");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        system("pause");
        return false;
    }
    bool escribio=fwrite(this, sizeof (Cancion), 1,p);
    fclose(p);
    return escribio;
}
 int Cancion::leerDeDisco(int pos){

   FILE *p;
    p=fopen(archivoCancion,"rb");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        system("pause");

        return false;
    }
    fseek(p,pos*sizeof (Cancion),0);
    bool leyo=fread(this, sizeof (Cancion), 1,p);
    fclose(p);
    return leyo;
}

void  Cancion::resetearArchivo(){
FILE *p;
    p=fopen(archivoCancion,"wb");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
    }
    fclose(p);

}




#endif // CLASSCANCION_H_INCLUDED
