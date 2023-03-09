
#ifndef __COORD_H__
#define  __COORD_H__


#include <string>
#include "Professor.h"

class Coordenador : public Professor
{
private:
  std::string Curso;
  float bonus = 2000;
public:
  Coordenador(std::string Nome, int CPF, float Sal, std::string Curso);
  virtual ~Coordenador();
  float getSalario() const;
  virtual void imprime() const;

};

Coordenador::Coordenador(std::string Nome, int CPF, float Sal, std::string Curso):
            Professor(Nome, CPF, Sal), Curso(Curso){}

Coordenador::~Coordenador(){
  std::cout << "Destroi Coordenador\n";
}

float Coordenador::getSalario() const{
  return bonus + Professor::getSalario();
}

void Coordenador::imprime() const{
  std::cout <<"Coordenador" <<std::endl;
  Pessoa::imprime();
  std::cout <<"Salario: R$" << this->getSalario() << "\n\n";
}



#endif // __COORD_H__
