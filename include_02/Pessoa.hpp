
#ifndef __PESSOA_HPP__
#define __PESSOA_HPP__

#include <stdio.h>
#include <string>

class Pessoa
{
private:
  std::string nome;
  int idade;

public:
  Pessoa(std::string, int );

  //setters
  void setIdade(int);
  void setNome(std::string);
  
  //getters
  int getIdade() const;
  std::string getNome() const;

  //funcao imprime
  virtual void imprime() const;

  //comparacao entre pessoas.
  int compare(const Pessoa&);

  ~Pessoa();
};



#endif //__PESSOA_HPP__