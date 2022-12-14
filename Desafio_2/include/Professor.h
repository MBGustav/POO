
#ifndef __PROFESSOR_HPP__
#define __PROFESSOR_HPP__


#include "Pessoa.h"


class Professor : public Pessoa
{
private:
  float Salario;
public:
  Professor(std::string Nome, int CPF, float Sal);

  //setters
  void setSalario(float input);

  //getters
  float getSalario();

  ~Professor();
};


Professor::Professor(std::string Nome, int CPF, float Sal):
                      Pessoa(Nome, CPF), Salario(Sal){}



void Professor::setSalario(float in){
  this->Salario = in;
}

float Professor::getSalario(){
  return this->Salario;
}


Professor::~Professor()
{
}

#endif//__PROFESSOR_HPP__