#include "DataHorario.h"



//construtor
// DataHorario::DataHorario(int _dia, int _mes, int _ano, int _hora, int _min, int _seg): 
//                     dia(_dia),  mes(_mes),  ano(_ano),  hora(_hora),  min(_min),  seg(_seg){}


DataHorario::DataHorario(int _dia, int _mes, int _ano, int _hora, int _min, int _seg){
    //Check Tempo:  (hora ) & (seg) & min
    bool time_OK = (0 <= _hora && _hora <= 24) && (0 <= _seg && _seg <=60) && (0 <= _min && _min <=60) ;
    // int feb_add =  (is_bissexto(_ano) && _mes == 2 ? 1:0);
    int feb_add = 0;
    if(is_bissexto(_ano) && _mes == 2) feb_add = 1;
    //check Data --> feb_add = 0 ou 1 e eh adicionado apenas quando estamos comparando mes 2 (fevereiro)
    bool date_OK = (0 <= _ano) && (0 < _mes && _mes <=12) && (0<= _dia && _dia <= day_month[_mes -1]+feb_add);

    if(time_OK && date_OK){
        this->seg = _seg;
        this->min = _min;
        this->hora = _hora;
        this->ano = _ano;
        this->mes = _mes;
        this->dia = _dia;
    }
}

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


bool DataHorario::is_bissexto(int _ano)
{
    bool is_true = (_ano % 400 == 0) || ( (_ano % 4 == 0) && (_ano % 100 != 0) );
    return is_true;
}

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
        std::cout << setfill('0') <<setw(2) << getDia() << "/" ;
        std::cout << setfill('0') <<setw(2) << getMes() << "/" ;
        std::cout << setfill('0') <<setw(4) << getAno()  << " - ";
    if(type){
        std::cout << setfill('0') <<setw(2) << getHora()%12 << ":" ;
        std::cout << setfill('0') <<setw(2) << getMinuto()  << ":" ;
        std::cout << setfill('0') <<setw(2) << getSegundo() << " - ";
        std::cout << (getHora() < 12 ? "AM" : "PM") <<std::endl;
    }else{
        std::cout << setfill('0') <<setw(2) << getHora()   << ":" ;
        std::cout << setfill('0') <<setw(2) << getMinuto() << ":" ;
        std::cout << setfill('0') <<setw(2) << getSegundo() << "." <<std::endl;
    }
}

void DataHorario::imprimePorExtenso() const{

    //Data
    std::cout  << setfill('0') <<setw(2) <<  getDia() << " de " 
              <<  Month[getMes()-1] << " de "
              <<  getAno() << " - ";
    //Hora
    std::cout << setfill('0') <<setw(2) << getHora() << " Horas, ";
    std::cout << setfill('0') <<setw(2) << getMinuto() << " Minutos, " ; 
    std::cout << setfill('0') <<setw(2) << getMinuto() << " Segundos\n" ; 

}
