
#include "AnimalDomestico.h"




AnimalDomestico::AnimalDomestico(string _nome, double _peso):
            nome(_nome), peso(_peso){}

AnimalDomestico::~AnimalDomestico(){}


void AnimalDomestico::setDono(Pessoa *P){dono = P;}
string AnimalDomestico::getnome() const {return this->nome;}
double AnimalDomestico::getpeso() const {return this->peso;}
Pessoa* AnimalDomestico::getDono()const {return this->dono;}

void AnimalDomestico::imprime() const{
    cout << "nome: " << this->getnome() << endl;
    cout << "peso: " << this->getpeso() << endl;
}


