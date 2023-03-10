
#include "DVD.h"
#include "Midia.h"

namespace catalogo{
    DVD::DVD(std::string titulo, int ano,std::string diretor):
    Midia(titulo, ano), Diretor(diretor){
        Artistas.resize(MAX_ARTISTAS);
        // type = vDVD;
        totalArtistas = 0;
    }


    DVD::~DVD(){}

    void DVD::adicionaArtista(string nome, string papel){
        if(totalArtistas>= MAX_ARTISTAS) 
            return;
        //else..
        Artistas[totalArtistas].first = nome;
        Artistas[totalArtistas++].second = papel;
    }

    string DVD::getDiretor() const{return Diretor;}


    int DVD::getTipo() const{
        // return static_cast<int>(type);
        return DEF_DVD;
    }
    
    void DVD::imprimeDados() const{ 

        cout << "Tipo: Filme em DVD" <<endl; 
        cout << "Diretor: " <<getDiretor() <<endl;
        for(int i = 0; i < totalArtistas; i++){
            cout << "Artista " << (i+1) <<":  "
                << Artistas[i].first
                << ", papel: "
                << Artistas[i].second << endl;
        }

        cout << "--------\n";
    }
}
