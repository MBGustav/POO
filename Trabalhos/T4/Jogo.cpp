
#include "Jogo.h"

namespace catalogo{
    Jogo::Jogo(string titulo, int anoCriacao, string genero):
    Midia(titulo, anoCriacao), Genero(genero){
        // type = vJOGO;
    }

    Jogo::~Jogo(){
    }

    int Jogo::getTipo()const {
        // return static_cast<int>(type);
        return vJOGO;
    }

    void Jogo::imprimeDados() const{ 
        cout << "Tipo: Jogo Eletrônico" << endl;
        
    }
    
    string Jogo::getGenero() const{
        return Genero;
    }
}

