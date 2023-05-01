
#include "DVD.h"
#include "Midia.h"

namespace catalogo{
    DVD::DVD(std::string titulo, int ano,std::string diretor):
    Midia(titulo, ano), Diretor(diretor){
        // Artistas.clear();
        // type = type_DVD;
        // totalArtistas = 0;
    }


    DVD::~DVD(){}


    string DVD::getDiretor() const{return Diretor;}


    int DVD::getTipo() const{
        return type_DVD;
    }
    
    void DVD::imprimeDados() const{ 

        cout << "Tipo: Filme em DVD" <<endl; 
        cout << "Diretor: " <<getDiretor() <<endl;
        // for(int i = 0; i < totalArtistas; i++){
        //     cout << "Artista " << (i+1) <<":  "
        //         << Artistas[i]->getNome()
        //         << ", papel: "
        //         << Artistas[i]->getPapel() << endl;
        // }
    }


    // Artista& DVD::GetArtista(int idx){
    //     return *Artistas[idx];
    // }

    // int DVD::gettotalArtistas() const{return Artistas.size();}
    // void DVD::adicionaArtista(Artista &A){
    //     Artistas.push_back(&A);
    //     // Artistas[totalArtistas ++] = &A;
    // }

    // void DVD::adicionaArtista(string nome, string papel){
    //     if(totalArtistas>= MAX_ARTISTAS) 
    //         return;
    //     //else..
    //     Artista *A = new Artista(nome, papel);
    //     Artistas.push_back(A);
    //     // Artistas[totalArtistas].first = nome;
    //     // Artistas[totalArtistas++].second = papel;
    // }
}
