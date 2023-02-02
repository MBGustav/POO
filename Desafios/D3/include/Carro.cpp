

#include "Carro.h"



namespace poo {
    Carro::Carro(string _marca, string _cor, int _ano, string _placa):
        marca(_marca), placa(_placa), cor(_cor), ano(_ano)
    {

    }

    Carro::~Carro(){std::cout <<"Destroi carro\n";}



    string Carro::getPlaca() const{
        return this->placa;

    }
    string Carro::getMarca() const{
        return this->marca;

    }
    string Carro::getCor() const{
        return this->cor;

    }
    int Carro::getAno() const{
        return this->ano;

    }

    void Carro::imprime() const{
        std::cout << "Marca: " << getMarca() << std::endl;
        std::cout << "Placa: " << getPlaca() << std::endl;
        std::cout << "Cor: " << getCor() << std::endl;
        std::cout << "Ano: " << getAno() << std::endl;
        
    }

}