

#include "Cachorro.h"

Cachorro::Cachorro(string Nome, double _peso, string _raca):
                AnimalDomestico(Nome, _peso), raca(_raca){}

Cachorro::~Cachorro(){}

string Cachorro::getRaca() const{ return this->raca;}
void Cachorro::imprime() const{
    //Imprime nome e Peso
    AnimalDomestico::imprime();
    std::cout << "Espécie: Cachorro.\n";
    std::cout << "Raça: " << getRaca() << "\n";
}
