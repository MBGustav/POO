#ifndef __CARRO_H__
#define __CARRO_H__


#include <iostream>
#include <string>
using std::string;

//Usr Libs
#include "Pessoa.h"

namespace poo{
    class Carro
    {
    private:
        std::string marca, placa, cor;
        int ano;
    public:
        Carro(string _marca, string _cor, int ano, string placa);
        ~Carro();
        string getPlaca() const;
        string getMarca() const;
        string getCor() const;
        int getAno() const;
        void imprime() const;
    };
}
//=====================



#endif //__CARRO_H__