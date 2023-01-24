
#ifndef __PESSOA_H__
#define __PESSOA_H__



#include <string>
#include <iostream>

using std::string;



class Pessoa
{
private:

  std::string Nome;
  int CPF;

public:
  //constructor
  Pessoa(std::string , int);
  
  //getters
  int getCPF() const;
  std::string getNome() const;

  //setters
  void setCPF(int);
  void setNome(std::string);

  virtual void imprime() const;

  //destructor
  ~Pessoa();
};


Pessoa::Pessoa(std::string Nome, int CPF ): Nome(Nome), CPF(CPF){

}
int Pessoa::getCPF() const{
  return this->CPF;
}
std::string Pessoa::getNome() const{
  return this->Nome;
}
void Pessoa::imprime() const{
  std::cout << "Nome: " << this->Nome << std::endl;
  std::cout << "CPF : " << this->CPF << std::endl;
}

  void Pessoa::setCPF(int cpf){
    this->CPF = cpf;
  }
  void Pessoa::setNome(std::string nome){
    this->Nome = nome; 
  }

//destructor
Pessoa::~Pessoa(){

}


#endif //__PESSOA_H__