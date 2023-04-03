
#include "Midia.h"

namespace catalogo{
    Midia::Midia(string titulo, int ano):
    Titulo(titulo), anoCriacao(ano){}

    Midia::~Midia(){}

    void Midia::imprimeFicha() const{
        cout << "Titulo:  " << getTitulo() << endl;
        cout << "Ano:  "    <<this->getanoCriacao() << endl;
        this->imprimeDados();
        cout << "--------\n";
    }
    int Midia::getanoCriacao() const{
        return anoCriacao;
    }

    void Midia::setanoCriacao(int _anoCriacao){
        anoCriacao = _anoCriacao;
    }

    string Midia::getTitulo() const {
        return this->Titulo;
    }


    bool Midia::comparaAno(const Midia* M1, const Midia* M2){
        return M1->getanoCriacao() == M2->getanoCriacao();
    }

    bool Midia::operator>(const Midia & M) const{
        //ordena pelo titulo
        return(this->getTitulo() > M.getTitulo());
    }
    bool Midia::operator<(const Midia & M) const{
        //se anos sao iguais, ordena pelo titulo
        return(this->getTitulo() < M.getTitulo());
    }

}

