
#include "CD.h"
#include "Midia.h"



namespace catalogo{
    CD::CD(const string titulo, int ano,string artista):
    Midia(titulo, ano), Artista(artista){
        Faixas.clear();
    }


    CD::~CD(){}



    string CD::getArtista() const{return Artista;}

    int CD::getTipo() const{
        return type_CD;
    }
    void CD::imprimeDados() const{       
        cout << "Tipo: CD de música"        <<endl;
        cout << "Artista: " << getArtista() <<endl;
        int min, seg; 
        std::cout << "Saida CD && size: " << getTotalFaixas() << std::endl;
        for(auto i=0; i < this->getTotalFaixas(); i++){
            min = Faixas[i]->getMinutos();
            seg = Faixas[i]->getSegundos();
            cout << "Faixa " << (i+1)<< ":  "
                << Faixas[i]->getNome()
                << ", duração: " << min
                <<":" << setfill('0') << setw(2) << seg <<endl;
        }
    }


    Faixa *CD::GetFaixa(int i) const{
        return Faixas[i];
    }

    void CD::adicionaFaixa(string nome, int duracao){
        Faixas.push_back(new Faixa(nome, duracao));
    }
    long int CD::getTotalFaixas() const{return Faixas.size();}
}