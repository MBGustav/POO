#ifndef __PROFESSOR_HPP__
#define __PROFESSOR_HPP__

#include "Pessoa.hpp"

class Professor : public Pessoa
{
private:
  float Salario;
public:
  Professor(std::string,int ,float);

  //setters
  void setSalario(float);

  //getters
  float getSalario() const;

  //impressao dos dados
  void imprime() const;

  ~Professor();
};


#endif//__PROFESSOR_HPP__