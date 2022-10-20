#ifndef CLASSFECHA_H_INCLUDED
#define CLASSFECHA_H_INCLUDED

class Fecha{
protected:
    int dia,mes,anio;
public:
    Fecha(int d=1,int m=1, int a=2022){
        dia=d;
        mes=m;
        anio=a;
    }
    void cargar();
    void mostar();
    ///sets
    bool setDia(int d){
        if(d>0 && d<32){
            dia=d;
            return true;
        }
        return false;
    }
     bool setMes(int m){
        if(m>0 && m<13){
            mes=m;
            return true;
        }
        return false;
    }
     bool setAnio(int a){
        if(a>1900){
            anio=a;
            return true;
        }
        return false;
    }
    ///gets
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
};
void Fecha::cargar(){
    cout<<"Dia:";cin>>dia;
    while(!(setDia(dia))){
        cout<<"Se puede ingresar del 1 al 31  nomas"<<endl;
        cout<<"ingresa el dia:";cin>>dia;
    }
    cout<<"Mes:";cin>>mes;
    while(!(setMes(mes))){
        cout<<"Se puede ingresar del 1 al 12 nomas"<<endl;
        cout<<"ingresa el Mes:";cin>>mes;

    }
     cout<<"Anio:";cin>>anio;
    while(!(setAnio(anio))){
        cout<<"Se puede ingresar a partir del anio 1900"<<endl;
        cout<<"ingresa el anio:";cin>>anio;

    }
}
void Fecha::mostar(){
cout<<"Fecha:"<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

#endif // CLASSFECHA_H_INCLUDED
