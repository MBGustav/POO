#ifndef __ALUNO_HPP__
#define __ALUNO_HPP__

#include <stdio.h>
#include <string>

#include "Pessoa.hpp"
class Aluno : public Pessoa 
{
private:
  int RA;

public:
  Aluno(std::string, int, int);
  
  int getRA() const;
  void setRA(int);
  
  void imprime() const;

  ~Aluno();
};



#endif //__ALUNO_HPP__