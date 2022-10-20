#ifndef CLASSGENERO_H_INCLUDED
#define CLASSGENERO_H_INCLUDED

class Genero{
    private:
        int idGenero;
        char nombre[40];
        int pais;
        int tipoDeInst;
        bool estado;

    public:
        void cargar(int id);
        void mostrar(bool use);
    ///funciones de archivo
        int leerDeDisco(int p);
        bool grabarEnDisco();
        bool modificarEndisco();
        void resetearArchivo();
        ///Setters
        void setIdGenero(int id){idGenero = id;}
        void setNombre(const char *n){strcpy(nombre, n);}
        bool setPais(int p){
            if(p > 0  && p <= 100){
                pais = p;
                return true;
            }else return false;
        }

        bool setInstrumento(int i){
            if(i > 0 && i <=5){
                tipoDeInst = i;
                return true;
            }else return false;
        }
        void setEstado(int e){estado = e;}

        ///Getters
        int getIdGenero(){return idGenero;}
        const char* getNombre(){return nombre;}
        int getPais(){return pais;}
        int getInstrumento(){return tipoDeInst;}
        bool getEstado(){return estado;}



};

///funcion cargar
void Genero::cargar(int id=0){
    if(idGenero!=0){
     idGenero=id;
    }
     cout<<"INGRESA EL NOMBRE DEL GENERO:";cargarCadena(nombre,29);
     cout<<"INGRESA PAIS (1-100):";cin>>pais;
     while(!(setPais(pais))){
     cout<<"EL PAIS ES ENTRE 1 Y 100"<<endl;
     cout<<"INGRESA PAIS:";cin>>pais;
     }
     cout<<"INGRESA TIPO DE INSTRUMENTACION(1-5):";cin>>tipoDeInst;
     while(!(setInstrumento(tipoDeInst))){
     cout<<"EL TIPO DE INSTRUMENTACION ES ENTRE EL 1 Y 5"<<endl;
     cout<<"INGRESA TIPO DE INSTRUMENTACION(1-5):";cin>>tipoDeInst;
     }
     estado=true;
}
///funcion mostrar
void Genero::mostrar(bool use=false){
    if(estado==true){
    if(use==false) {
     cout<<"GENERO ID :"<<idGenero<<endl;
     cout<<"NOMBRE DEL GENERO:"<<nombre<<endl;
     cout<<"PAIS:"<<pais<<endl;
     cout<<"TIPO DE INSTRUMENTACION:"<<tipoDeInst<<endl;
    }else{
     cout<<"NOMBRE DEL GENERO:"<<nombre<<endl;
    }}
}
bool Genero::grabarEnDisco(){

     FILE *p;
    p=fopen(archivoGenero,"ab");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        system("pause");
        return false;
    }
    bool escribio=fwrite(this, sizeof (Genero), 1,p);
    fclose(p);
    return escribio;
}
 int Genero::leerDeDisco(int pos){

   FILE *p;
    p=fopen(archivoGenero,"rb");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        system("pause");

        return false;
    }
    fseek(p,pos*sizeof (Genero),0);
    bool leyo=fread(this, sizeof (Genero), 1,p);
    fclose(p);
    return leyo;
}

void  Genero::resetearArchivo(){
FILE *p;
    p=fopen(archivoGenero,"wb");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        system("pause");
    }
    fclose(p);

}






































#endif // CLASSGENERO_H_INCLUDED
