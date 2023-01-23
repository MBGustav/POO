#ifndef __VOO_H__
#define __VOO_H__

//Built-in Libs
#include <iostream>
#include <cstring>

//Usr libs
#include "DataHorario.h"
#include "Pessoa.h"

constexpr int max_passengers = 100;

class Voo
{
private:
    int nro_voo;
    DataHorario Data;
    int total_vagos;

    //declaração Estatica!
    // Pessoa *assentos[max_passengers];
    Pessoa **assentos;
public:
    Voo(int, DataHorario&);
    ~Voo();

    int proximoLivre() const;
    bool verifica(int pos) const; 
    bool desocupa(int pos); 
    bool ocupa(int pos, Pessoa &P); 
    int vagas() const; 

    void imprime() const;

    //Getters
    DataHorario getData() const;
    int getNroVoo() const;
    int getTotalPassageiros() const;



};

Voo::Voo(int n_voo,DataHorario& date): nro_voo(n_voo), Data(date){
    total_vagos = max_passengers;
    //alloca few passsane
    assentos = new Pessoa*[max_passengers];
    // memset(assentos, 0, max_passengers * sizeof(Pessoa *));
    for(int i = 0; i < max_passengers; i++){
        assentos[i] = NULL;
    }

}

Voo::~Voo(){}

int Voo::proximoLivre() const{
    int i = 1; 
    bool found = false;
    while (i<total_vagos && !found)
    {
        (assentos[i-1] == NULL ? found = true : i++);
    }
    return i;
}

int Voo::vagas() const{return total_vagos;}
int Voo::getNroVoo() const{return this->nro_voo;}
DataHorario Voo::getData() const{return Data;}

//Se estiver livre, retorna true !
bool Voo::verifica(int pos) const{
    //Bounder check
    if(pos > max_passengers || pos<0) EXIT_FAILURE;
    if(assentos[pos-1] == NULL) return true;
    return false;
}


bool Voo::ocupa(int pos, Pessoa &P){
    if(verifica(pos))
    {
        //Vinculamos o endereço de: Pessoa P 
        assentos[pos-1] = &P;
        total_vagos--;
        return true;
    }
    return false;
}


bool Voo::desocupa(int pos){

    //Procuramos por cadeira ocupada.
    if(verifica(pos)) return false;
    int idx = pos-1; 
    //else nao encontrado..
    //Call destructor de Pessoa => Errado !
    // delete assentos[0];
    // Nao se chama destrutor, pois é 
    // Uma associação de voo -> Pessoa

    assentos[idx] = NULL;
    
    //Corrigimos a posição de local dos passageiros
    while(idx < total_vagos -10 ){
        assentos[idx] = assentos[idx+1];
        idx++;
    }
    total_vagos++;
    return true;
}

int Voo::getTotalPassageiros() const {return max_passengers - total_vagos;}

void Voo::imprime() const{

    std::cout << "\nInformações de voo:"<<std::endl;
    std::cout << "Nro. de Voo: " << getNroVoo() << std::endl;
    std::cout << "Horario: "; Data.imprime();
    std::cout << "Total de Passageiros: " << getTotalPassageiros() << std::endl;
    std::cout << "Vagas Restantes: " << vagas() <<std::endl <<std::endl;
}





#endif //__VOO_H__