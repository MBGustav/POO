#ifndef CARRO_H
#define CARRO_H

#include <string>
using std::string;

#include "Pessoa.h"
namespace poo{
// class Pessoa;

class Carro
{
private:
    string marca, cor, placa;
    int ano;
    Pessoa *pessoa;
public:
    Carro(string marca, string cor, int ano, string placa);
    ~Carro();

    string getMarca() const;
    string getCor() const;
    string getPlaca() const;
    string getDono() const;
    void setPessoa(Pessoa *P);
    void imprime();
        
};

}poo::Carro::Carro(string marca, string cor, int ano, string placa):
            marca(marca), cor(cor), ano(ano), placa(placa)
{
    pessoa = NULL;
}

poo::Carro::~Carro()
{
    std::cout << "Destruicao de Carro\n";
}


string poo::Carro::getMarca() const{
    return marca;
    }
string poo::Carro::getCor() const{
    return cor;
    }
string poo::Carro::getPlaca() const{
    return placa;
    }   

void poo::Carro::setPessoa(Pessoa *P) {
    pessoa = P;
}

void poo::Carro::imprime(){
    std::cout << "\nMarca: " << getMarca() << std::endl;
    std::cout << "Cor:     " << getCor() <<std::endl;
    std::cout << "Placa:   " << getPlaca() <<std::endl;
    if(pessoa != NULL) 
        std::cout <<"Dono:  "<< pessoa->getNome() <<std::endl;
}


#endif // Carro_H
