
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
  float getSalario();
  ~Coordenador();
};

Coordenador::Coordenador(std::string Nome, int CPF, float Sal, std::string Curso):
            Professor(Nome, CPF, Sal), Curso(Curso){}

Coordenador::~Coordenador()
{
}


float Coordenador::getSalario(){
  return bonus + Professor::getSalario();
}


#endif // __COORD_H__
