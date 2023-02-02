#ifndef __PESSOA_H__
#define __PESSOA_H__

#include <string>
using std::string;
//Usr libs
#include "Carro.h"

static int MAX_CARRO = 3;

namespace poo{
    class Carro; // ?? duvida -> porque devo adicionar ?
    class Pessoa
    {
    private:
        string Nome, CPF;
        Carro **carro;
        int total_carros;
    public:
        //Constructor & Destructor
        Pessoa(string _Nome, string _CPF);
        ~Pessoa();

        //Getter & Setter 
        string getCPF() const;
        string getNome() const;

        void setCPF(string _CPF);
        void setNome(string _Nome);

        bool adicionaCarro(Carro *c);
        Carro *removeCarro(string placa);
        void imprime() const;


    };
}


#endif // __PESSOA_H__