
#include "CD.h"
#include "Midia.h"



namespace catalogo{
    CD::CD(const string titulo, int ano,string artista):
    Midia(titulo, ano), Artista(artista){
        //type = vCD;
        // Faixas.clear();
        totalFaixas=0;

    }


    CD::~CD(){}



    string CD::getArtista() const{return Artista;}

    int CD::getTipo() const{
        // return static_cast<int>(type);
        return vCD;
    }
    void CD::imprimeDados() const{       
        cout << "Tipo: CD de música"        <<endl;
        cout << "Artista: " << getArtista() <<endl;
        // for(int i=0; i < (int)getTotalFaixas(); i++){
        //     // min = Faixas[i].second/60;
        //     // seg = Faixas[i].second%60;
        //     min = Faixas[i]->getMinutos();
        //     seg = Faixas[i]->getSegundos();
        //     cout << "Faixa " << (i+1)<< ":  "
        //         << Faixas[i]->getNome()
        //         << ", duração: " << min
        //         <<":" << setfill('0') << setw(2) << seg <<endl;
        // }    
        

    }


    // Faixa &CD::GetFaixa(int i) const{
    //     return *Faixas[i];
    // }
    // void CD::adicionaFaixa(Faixa &F){
    //     Faixas.push_back(&F);
    //     // Faixas[totalFaixas++] = &F;
    // }
    // void CD::adicionaFaixa(string nome, int duracao){
        
    //     if(totalFaixas >= MAX_FAIXAS) 
    //         return;
    //     //else..
        
    //     // Faixas[totalFaixas].first = nome;
    //     // Faixas[totalFaixas++].second = duracao;
    //     Faixa *F = new Faixa(nome, duracao);
    //     Faixas.push_back(F);

    // }
    // long int CD::getTotalFaixas() const{return totalFaixas;}
}