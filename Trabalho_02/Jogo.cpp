
#include "Jogo.h"

namespace catalogo{
    Jogo::Jogo(string titulo, int anoCriacao, string genero):
    Midia(titulo, anoCriacao), Genero(genero){
        type = vJOGO;
    }

    Jogo::~Jogo(){
    }

    int Jogo::getTipo()const {
        // return static_cast<int>(type);
        return DEF_JOGO;
    }

    void Jogo::imprimeDados() const{ 
        cout << "Titulo:" << getTitulo() << endl;
        cout << "Ano:" << getanoCriacao() << endl;
        cout << "Tipo: Jogo Eletrônico" << endl;
    }
}

