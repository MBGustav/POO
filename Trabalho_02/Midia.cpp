
#include "Midia.h"

namespace catalogo{
    Midia::Midia(string titulo, int ano):
    Titulo(titulo), anoCriacao(ano){}

    Midia::~Midia(){}

    void Midia::imprimeFicha() const{
        cout << "Titulo:  " << getTitulo() << endl;
        cout << "Ano:  "    <<this->getanoCriacao() << endl;
        this->imprimeDados();
    }
    int Midia::getanoCriacao() const{
        return anoCriacao;
    }
    string Midia::getTitulo() const {
        return Titulo;
    }
}

