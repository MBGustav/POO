#ifndef __VOO_H__
#define __VOO_H__

//Built-in Libs
#include <iostream>
#include <iomanip>
using std::setfill, std::setw;

#include <cstring>

//Usr libs
#include "Pessoa.h"
#include "DataHorario.h"

constexpr int max_passengers = 100;

class Voo
{
private:
    //parametros
    int nro_voo;
    DataHorario Data;
    int total_vagos;//total de poltronas vagas

    //declaração Estatica - comentado
    // Pessoa *assentos[max_passengers];

    //Alocação dinamica - funcionamento atual
    Pessoa **assentos;
public:
    //Destrutor e Construtor
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



#endif //__VOO_H__