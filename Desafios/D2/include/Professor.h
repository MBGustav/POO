
#ifndef __PROFESSOR_HPP__
#define __PROFESSOR_HPP__


#include "Pessoa.h"


class Professor : public Pessoa
{
private:
  //atributes
  float Salario;
public:

//methods
  Professor(std::string Nome, int CPF, float Sal);

  //setters
  void setSalario(float input);

  //getters
  float getSalario() const;


  //Impressao
  virtual void imprime() const;


  virtual ~Professor();
};


Professor::Professor(std::string Nome, int CPF, float Sal):
                      Pessoa(Nome, CPF), Salario(Sal){}



void Professor::setSalario(float in){
  this->Salario = in;
}

float Professor::getSalario() const {
  return this->Salario;
}
void Professor::imprime() const{
  std::cout <<"Professor" <<std::endl;
  Pessoa::imprime();
  std::cout <<"Salario: R$" << this->getSalario() <<"\n\n";
}

Professor::~Professor()
{
  std::cout << "Destroi Professor\n";
}

#endif//__PROFESSOR_HPP__