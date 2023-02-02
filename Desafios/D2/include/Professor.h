
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
  float getSalario();


  //Impressao
  void imprime() const;


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
void Professor::imprime() const{
  std::cout <<"Impressao do tipo Professor" <<std::endl;
  Pessoa::imprime();
  std::cout << this->Salario;
}

Professor::~Professor()
{
  std::cout << "Destroi Professor\n";
}

#endif//__PROFESSOR_HPP__