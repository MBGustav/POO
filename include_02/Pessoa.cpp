
#include <iostream>
#include "Pessoa.hpp"

//Constructor
Pessoa::Pessoa(std::string nome, int idade) : nome(nome), 
                                              idade(idade){}


//setters
  void Pessoa::setIdade(int idade){this->idade = idade;}
  void Pessoa::setNome(std::string){this->nome = nome;}
  
  //getters
  int Pessoa::getIdade() const{ return this->idade;}
  std::string Pessoa:: getNome() const{return this->nome;}

  //funcao imprime
  void Pessoa::imprime() const{
    std::cout << "Nome:  " << this->nome << std::endl;
    std::cout << "idade: " << this->idade << std::endl;    
  }

  int Pessoa::compare(const Pessoa& P){
    if(P.getNome() != this->getNome()) return 0;

    return 1;
    
  }


//Destructor
Pessoa::~Pessoa()
{
}
