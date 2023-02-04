#ifndef  __ANIMALDOMESTICO_H__
#define  __ANIMALDOMESTICO_H__

#include <iostream>
using std::cout, std::endl;
#include <string>
using std::string;

#include "Pessoa.h"
class Pessoa;
class AnimalDomestico
{
private:
    string nome;
    double peso;
    Pessoa *dono;
public:
    AnimalDomestico(string nome, double Peso);
    virtual ~AnimalDomestico();
  
    void setDono(Pessoa*);
  
    Pessoa *getDono() const;
    string getnome() const;
    double getpeso() const;

    virtual void imprime() const;
};




#endif //__ANIMALDOMESTICO_H__