#include "Faixa.h"

namespace catalogo{

Faixa::Faixa(std::string Nome, int duracao):
            Nome(Nome), duracao(duracao){}
    
Faixa::~Faixa(){}

int Faixa::getDuracao() const{return this->duracao;}

int Faixa::getMinutos() const{return this->duracao/60;}

int Faixa::getSegundos() const{return this->duracao%60;}

string Faixa::getNome() const{return this->Nome;}

}