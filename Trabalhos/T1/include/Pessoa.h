#ifndef __PESSOA_H__
#define __PESSOA_H__

#include <string>
#include <iostream>


class Pessoa
{
private:
    //atributos
    std::string Nome;
    std::string CPF;

public:
    //Construtor
    Pessoa(std::string _CPF, std::string _NOME);
    //Destrutor
    virtual ~Pessoa();

    //getters
    std::string getCPF() const;
    std::string getNome() const; 

    
    //methods
    virtual void imprime() const;

};



#endif //__PESSOA_H__