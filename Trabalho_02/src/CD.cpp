
#include "CD.h"
#include "Midia.h"



namespace catalogo{
    CD::CD(const string titulo, int ano,string artista):
    Midia(titulo, ano), Artista(artista){
        //type = vCD;
        Faixas.resize(MAX_ARTISTAS);
        totalFaixas=0;

    }


    CD::~CD(){}


    void CD::adicionaFaixa(string nome, int duracao){
        
        if(totalFaixas >= MAX_FAIXAS) 
            return;
        //else..

        Faixas[totalFaixas].first = nome;
        Faixas[totalFaixas++].second = duracao;

    }

    long int CD::getTotalFaixas() const{return totalFaixas;}
    string CD::getArtista() const{return Artista;}

    int CD::getTipo() const{
        // return static_cast<int>(type);
        return DEF_CD;
    }
    void CD::imprimeDados() const{       
        cout << "Tipo: CD de música"        <<endl;
        cout << "Artista: " << getArtista() <<endl;
        int min, seg;
        for(int i=0; i < (int)getTotalFaixas(); i++){
            min = Faixas[i].second/60;
            seg = Faixas[i].second%60;
            cout << "Faixa " << (i+1)<< ":  "
                << Faixas[i].first
                << ", duração: " << min
                <<":" << setfill('0') << setw(2) << seg <<endl;
        }    
        

    }
}