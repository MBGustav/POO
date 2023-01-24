#include "DataHorario.h"



//construtor
DataHorario::DataHorario(int _dia, int _mes, int _ano, int _hora, int _min, int _seg): 
                    dia(_dia),  mes(_mes),  ano(_ano),  hora(_hora),  min(_min),  seg(_seg){}

//Destrutor
DataHorario::~DataHorario()
{
}

//getters
int DataHorario::getDia() const{return this->dia;}
int DataHorario::getMes() const{return this->mes;}
int DataHorario::getAno() const{return this->ano;}
int DataHorario::getHora() const{return this->hora;}
int DataHorario::getMinuto() const{return this->min;}
int DataHorario::getSegundo() const{return this->seg;}


int DataHorario::compara(DataHorario& D)
{   
    //  0: datas iguais
    //  1: this > D
    // -1: this < D

    //Dias iguais -> verifica hora
    if(this->comparaData(D) == 0)
        return this->comparaHora(D);
    
    //atributo < parametro == -1
    if(this->comparaData(D) > 0) return 1;

    //ultimo caso: se data é menor 
    return -1;
}


//Fiz essa função para facilitar na comparaçao de datas
int DataHorario::comparaHora(DataHorario &D){
    //  0: horas iguais
    //  1: this > D
    // -1: this < D
    if(getHora() > D.getHora()) return 1;
    if(getHora() < D.getHora()) return -1;
    //Sobra o caso de Hora == D.Hora

    if(getMinuto() > D.getMinuto()) return 1;
    if(getMinuto() < D.getMinuto()) return -1;
    //Sobra o caso de Minuto == D.Minuto

    if(getSegundo() > D.getSegundo()) return 1;
    if(getSegundo() < D.getSegundo()) return -1;
    //Sobra o caso de Segundo == D.Segundo

    //Mas se HH:MM:SS == HH:MM:SS, horas sao iguais
    return 0;
}      

int DataHorario::comparaData(DataHorario &D){
    // 0 : Datas iguais
    // 1 : this > D
    // -1: this < D
    if(getAno() > D.getAno()) return 1;
    if(getAno() < D.getAno()) return -1;
    //Sobra o caso de Ano == D.Ano

    if(getMes() > D.getMes()) return 1;
    if(getMes() < D.getMes()) return -1;
    //Sobra o caso de Mes == D.Mes

    if(getDia() > D.getDia()) return 1;
    if(getDia() < D.getDia()) return -1;
    //Sobra o caso de Dia == D.Dia

    //Mas se D/M/AAAA == D/M/AAAA, horas sao iguais
    return 0;
}

void DataHorario::imprime(bool type=false) const{
        std::cout << getDia() << "/" ;
        std::cout << getMes() << "/" ;
        std::cout << getAno()  << " - ";
    if(type){
        std::cout << getHora()%12 << ":" ;
        std::cout << getMinuto()  << ":" ;
        std::cout << getSegundo() << " - ";
        std::cout << (getHora() < 12 ? "AM" : "PM") <<std::endl;
    }else{
        std::cout << getHora()   << ":" ;
        std::cout << getMinuto() << ":" ;
        std::cout << getSegundo() << "." <<std::endl;
    }
}

void DataHorario::imprimePorExtenso() const{

    //Data
    std::cout <<  getDia() << " de " 
              <<  Month[getMes()-1] << " de "
              <<  getAno() << " - ";
    //Hora
    std::cout << getHora() << " Horas, "
              << getMinuto() << " Minutos, " 
              << getSegundo()<< "segundos." << std::endl;
}
