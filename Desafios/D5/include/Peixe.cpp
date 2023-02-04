
#include "Peixe.h"


Peixe::Peixe(string _nome, double _peso, string habitat):
            AnimalDomestico(_nome, _peso), tipoHabitat(habitat){}

Peixe::~Peixe(){}

string Peixe::gethabitat() const{return this->tipoHabitat;}

void Peixe::imprime() const{
    //Imprime nome e Peso
    AnimalDomestico::imprime();
    std::cout << "Espécie: Peixe.\n";
    std::cout << "Habitat: " << gethabitat() << "\n";
}