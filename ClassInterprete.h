#ifndef CLASSINTERPRETE_H_INCLUDED
#define CLASSINTERPRETE_H_INCLUDED


class Interprete{
private:
    int idInterprete;
    char nombre[30];
    int nacionalidad;
    int tipoInterprete;
    int generoMusical;
    Fecha fechaDeInicioActividad;
    bool estado;
public:
    void cargar(int id,int g);
    void mostrar(bool use,bool gene);
    ///funciones de archivo
    int leerDeDisco(int p);
    bool grabarEnDisco();
    bool modificarEndisco();
    int daUltimoIdCreado();
    void resetearArchivo();
    ///setteeeeeeeeeeeeeeeeeers

    bool setIdInterprete(int id){
        if(id>0){
           idInterprete=id;
           return true;
        }return false;
    }
     void setNombre(const char *n){
        strcpy(nombre,n);
    }
     bool setNacionalidad(int n){
        if(n>0 && n<101){
           nacionalidad=n;
           return true;
        }return false;
    }
   bool setTipoInterprete(int t){
        if(t>0 && t<6){
           tipoInterprete=t;
           return true;
        }return false;
    }
     bool setGeneroMusical(int g){
        if(g>0 && g<11){
           generoMusical=g;
           return true;
        }return false;
    }
    void setFecha(){fechaDeInicioActividad.cargar();}
    void setEstado(bool e){estado=e;}

    ///getteeeeeeeeeeeeeeeeeers

     int getIdInterprete(){return idInterprete;}
     const char* getNombre(){return nombre;}
     int getNacionalidad(){return nacionalidad;}
     int getTipoInterprete(){return tipoInterprete;}
     int getGeneroMusical(){return generoMusical;}
     bool getEstado(){return estado;}
    Fecha getFechaDeInicio(){return fechaDeInicioActividad;}
};
///funcion cargar
void Interprete::cargar(int id=0,int g=0){
    if(id!=0){
     idInterprete=id;
    }
     cout<<"INGRESA EL NOMBRE DEL INTERPRETE:";cargarCadena(nombre,29);
     cout<<"INGRESA LA NACIONALIDAD(1-100):";cin>>nacionalidad;
     while(!(setNacionalidad(nacionalidad))){
     cout<<"LA NACIONALIDAD SOLO PUEDE SER ENTRE 1 Y 100"<<endl;
     cout<<"INGRESA LA NACIONALIDAD";cin>>nacionalidad;
     }
     cout<<"INGRESA TIPO DE INTERPRETE(1-5):";cin>>tipoInterprete;
     while(!(setTipoInterprete(tipoInterprete))){
     cout<<"EL TIPO DE INTERPRETE SOLO PUEDE SER ENTRE 1 Y 5"<<endl;
     cout<<"INGRESA TIPO DE INTERPRETE";cin>>tipoInterprete;
     }
        if(g!=0){
        generoMusical=g;
        }else{
        cout<<"INGRESA TIPO DE GENERO MUSICAL(1-10):";cin>>generoMusical;
        while(!(setGeneroMusical(generoMusical))){
        cout<<"EL TIPO DE GENERO MUSICAL SOLO PUEDE SER ENTRE 1 Y 10"<<endl;
        cout<<"INGRESA TIPO DE GENERO MUSICAL";cin>>generoMusical;
        }
        }
     cout<<"INGRESA FECHA DE ESTRENO:"<<endl;fechaDeInicioActividad.cargar();
    estado=true;
}
///funcion mostrar
void Interprete::mostrar(bool use=false,bool gene=false){
    if(estado==true){
            if(use==false){
            cout<<"ID DEL INTERPRETE:"<<idInterprete<<endl;
            cout<<"NOMBRE INTERPRETE:"<<nombre<<endl;
            cout<<"NACIONALIDAD:"<<nacionalidad<<endl;
            cout<<"TIPO DE INTERPRETE:"<<tipoInterprete<<endl;
            if(gene==false)cout<<"GENERO MUSICAL DEL INTERPRETE:"<<generoMusical<<endl;
            cout<<"FECHA DE INICIO DE ACTIVIDAD DEL INTERPRETE:";fechaDeInicioActividad.mostar();
            }else{
            cout<<"NOMBRE INTERPRETE:"<<nombre<<endl;
            }

    }

}
bool Interprete::grabarEnDisco(){

     FILE *p;
    p=fopen(archivoInterprete,"ab");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        system("pause");
        return false;
    }
    bool escribio=fwrite(this, sizeof (Interprete), 1,p);
    fclose(p);
    return escribio;
}
 int Interprete::leerDeDisco(int pos){

   FILE *p;
    p=fopen(archivoInterprete,"rb");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        system("pause");

        return false;
    }
    fseek(p,pos*sizeof (Interprete),0);
    bool leyo=fread(this, sizeof (Interprete), 1,p);
    fclose(p);
    return leyo;
}

void  Interprete::resetearArchivo(){
FILE *p;
    p=fopen(archivoInterprete,"wb");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        system("pause");
    }
    fclose(p);

}


#endif // CLASSINTERPRETE_H_INCLUDED
