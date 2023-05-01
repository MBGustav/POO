
#include "Jogo.h"

namespace catalogo{
    Jogo::Jogo(string titulo, int anoCriacao, string genero):
    Midia(titulo, anoCriacao), Genero(genero){
        // type = type_JOGO;
    }

    Jogo::~Jogo(){
    }

    int Jogo::getTipo()const {
        // return static_cast<int>(type);
        return type_JOGO;
    }

    void Jogo::imprimeDados() const{ 
        cout << "Tipo: Jogo Eletrônico" << endl;
        
    }
    
    string Jogo::getGenero() const{
        return Genero;
    }
}

