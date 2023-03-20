
#include "Pessoa.h"


Pessoa::Pessoa(std::string _CPF, std::string _Nome) : Nome(_Nome), CPF(_CPF){}
Pessoa::~Pessoa(){/*std::cout << "Destroi Pessoa\n";*/}


std::string Pessoa::getCPF() const{return this->CPF;}
std::string Pessoa::getNome() const{return this->Nome;} 
    
void Pessoa::imprime() const{
    std::cout << "Nome: " << getNome() << std::endl; 
    std::cout << "CPF : " << getCPF() << std::endl; 
}



