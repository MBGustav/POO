#ifndef _ALUNO_h_
#define _ALUNO_h_


//Built-in libs
#include <string>
#include <iostream>

//Usr libs 
#include "Pessoa.h"


class Aluno : public Pessoa 
{
private:
    //Atributos
    int RA;
    double P1,P2,T1;


public:
    //Constructor
    Aluno(std::string nome, std::string CPF, int RA, double P1, double P2, double T1);
    
    //Metodos
    int getRA() const;
    bool aprovado() const;

    double media() const;
    bool sac() const;
    double notaSAC() const;

    //metodo impressao - 
    //usa-se virtual para escolha em tempo de Compilação !
    virtual void imprime() const;


    //Destructor - > destroi aluno -> Pessoa, nessa ordem
    virtual ~Aluno();

};



#endif //_ALUNO_h_

