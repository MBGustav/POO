#ifndef _ALUNO_HPP_
#define _ALUNO_HPP_

#include <string>
#include <iostream>


class Aluno
{
private:
    //Atributos
    std::string Nome, CPF;
    int RA;
    int n_sei;
    double P1,P2,T1;


public:
    //Constructor
    Aluno(std::string nome, int RA, int nao_sei, double P1, double P2, double T1);
    
    //Metodos
    int getRA() const;
    bool aprovado() const;
    bool reprovado() const;
    double media() const;
    bool sac() const;
    double notaSAC() const;
    void imprime() const;


    //Destructor
    ~Aluno();

};

//Execução Naive - devemos chamar pelo constructor Pessoa
Aluno::Aluno(std::string nome, int RA, int nao_sei, double P1, double P2, double T1) :
                     Nome(nome), RA(RA), n_sei(nao_sei), P1(P1), P2(P2), T1(T1)
{}



int Aluno::getRA() const {return this->RA;}

double Aluno::media() const {return (P1*7+P2*7+6)/20;};

bool Aluno::aprovado() const {return (this->media()>=6.0f)? true : false;}

bool Aluno::sac() const {return (5.0f < this->media() && this->media()<=6.0f) ? true : false;}

double Aluno::notaSAC() const {
    if(!this->sac()) return 0;
    return 6.0f * 2.0f - this->media();
}

void Aluno::imprime() const {
    std::cout << "Impressao Aluno\n";
    std::cout << "Nome.: " << this->Nome <<"\n";
    std::cout << "CPF. : " << this->CPF << "\n";
    std::cout << "RA   : " << this->getRA() << "\n";
    std::cout << "Media: " << this->media() << "\n";
}

Aluno::~Aluno()
{
}





#endif //_ALUNO_HPP_

