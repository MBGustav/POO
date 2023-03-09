
#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
using std::string;

// #include "Carro.h"

// class Carro;
namespace poo{
class Carro;

class Pessoa{
private:
    string Nome, CPF;
    int total_carros;
    Carro *carro[3];
public:
    Pessoa(string marca, string CPF);
    ~Pessoa();

    string getNome() const;
    string getCPF() const;
    bool adicionaCarro(Carro *carro);
    Carro *removeCarro(string placa);
    void imprime() const;

    
};


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


}
poo::Pessoa::Pessoa(string Nome, string CPF):
            Nome(Nome), CPF(CPF)
{
    int total_carros = 0 ;
    for(int i = 0; i < 3; i++)
        carro[i] = NULL;
}
void poo::Pessoa::imprime() const{
    std::cout << "Nome: " << getNome() <<std::endl;
    std::cout << "CPF:  " <<getCPF() << std::endl;
    for(int i = 0 ; i < total_carros; i++){
        carro[i]->imprime();
        std::cout << "----------\n";
    }
}
poo::Pessoa::~Pessoa()
{
    std::cout << "Destruicao de Pessoa\n";
}
poo::Carro *poo::Pessoa::removeCarro(string placa){
    bool found = false;
    Carro *ptr_car = NULL;
    int i = 0;
    if(total_carros == 0) return NULL;

    while(i < total_carros && !found){
        if(placa == carro[i]->getPlaca()){
            found = true;
            break;
        } 
    }
    if(found){
        //pega ponteiro
        ptr_car = carro[i];

        //realoca posições
        while(i < 3-1){
            carro[i] = carro[i+1];
        }
        total_carros-=1;
    }
    return ptr_car;
}

bool poo::Pessoa::adicionaCarro(Carro *C){
    if(total_carros == 3) return false;
    C->setPessoa(this);
    carro[total_carros++] = C;
    
    return true;

}

string poo::Pessoa::getNome() const{return this->Nome;}
string poo::Pessoa::getCPF() const{return this->CPF;}

poo::Carro::Carro(string marca, string cor, int ano, string placa):
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


#endif // PESSOA_H
