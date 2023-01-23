#ifndef __PESSOA_H__
#define __PESSOA_H__

#include <string>
#include <iostream>


class Pessoa
{
private:
    std::string Nome;
    std::string CPF;
public:

    Pessoa(std::string _CPF, std::string _NOME);
    virtual ~Pessoa();

    //setters & getters
    std::string getCPF() const;
    std::string getNome() const; 

    
    //methods
    virtual void imprime() const;

};

Pessoa::Pessoa(std::string _CPF, std::string _Nome) : Nome(_Nome), CPF(_CPF){}
Pessoa::~Pessoa(){/*std::cout << "Destroi Pessoa\n";*/}


std::string Pessoa::getCPF() const{return this->CPF;}
std::string Pessoa::getNome() const{return this->Nome;} 
    
void Pessoa::imprime() const{
    std::cout << "Nome: " << getNome() << std::endl; 
    std::cout << "CPF : " << getCPF() << std::endl; 
}






#endif //__PESSOA_H__