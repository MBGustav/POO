
#include "Professor.hpp"
#include <iostream>



Professor::Professor(std::string nome, int idade, float salario)
  :Pessoa(nome, idade), Salario(salario)
{

}

  //setters
  void Professor::setSalario(float salario){this->Salario = salario;}

  //getters
  float Professor::getSalario() const{return this->Salario;}

  void Professor::imprime() const{
    std::cout << "Impressao do tipo - Professor\n";
    Pessoa::imprime();
    std::cout <<"Salario: R$ "<< this->Salario <<std::endl; 
    std::cout <<"\n\n";

  }


Professor::~Professor()
{

}

