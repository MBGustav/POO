

#include "Aluno.h"

Aluno::Aluno(std::string nome, std::string _CPF, int _RA, double _P1, double _P2, double _T1) :
    Pessoa(nome, _CPF), RA(_RA), P1(_P1), P2(_P2), T1(_T1){}



int Aluno::getRA() const {return this->RA;}

double Aluno::media() const {return (P1*7+P2*7+6)/20;};

bool Aluno::aprovado() const {return (this->media()>=6.0f)? true : false;}

bool Aluno::sac() const {return (5.0f < this->media() && this->media()<=6.0f) ? true : false;}

double Aluno::notaSAC() const {
    if(!this->sac()) return 0;
    return 6.0f * 2.0f - this->media();
}

void Aluno::imprime() const {
    // std::cout << "Impressao Aluno\n";
    // std::cout << "Nome.: " << getNome() <<"\n";
    // std::cout << "CPF. : " << getCPF() << "\n";
    Pessoa::imprime();
    std::cout << "RA   : " << this->getRA() << "\n";
    std::cout << "Media: " << this->media() << "\n";
}

Aluno::~Aluno(){/*std::cout << "Destroi Aluno\n";*/}
