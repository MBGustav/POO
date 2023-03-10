#include "Catalogo.h"


namespace catalogo
{
    Catalogo::Catalogo(){}
    Catalogo::~Catalogo(){}

    bool Catalogo::adicionaMidia(Midia &M){

        //caso seja encontrado em algum local => falso
        if(this->obtemMidia(M.getTitulo())!=NULL)
            return false;
        
        //Insere no vetor
        vMidia.push_back(&M);

        //Ordenamos o vetor que temos armazenado
        sort(vMidia.begin(), vMidia.end(), CatalogoOrder);
        return true;
    }
    
    bool Catalogo::removeMidia(string titulo){
        vector<Midia*>::iterator it=vMidia.begin();
        bool remove = false;
        while(it != vMidia.end() && !remove){
            if((*it)->getTitulo() == titulo){
                //remove na posicao em que o 
                //iterator se encontra
                vMidia.erase(it);
                remove = true;
            }
            else it++;


        }
        return remove;
    }

    Midia* Catalogo::obtemMidia(string titulo){
        bool found = false;
        int i = static_cast<int>(vMidia.size());

        while(!found && i>0)
            if(vMidia[--i]->getTitulo() == titulo)
                found = true; 
            
        //em caso de ser encontrado
        if(found) return vMidia[i];

        //em caso de nao ser encontrao
        return NULL;

        
    }

    int Catalogo::quantidadeDeMidias() const{return static_cast<int>(vMidia.size());}
        
    int Catalogo::quantidadeDeCDs() const{
        int total_CD = 0; 
        for(int i=0; i < quantidadeDeMidias(); i++){
            if(vMidia[i]->getTipo() == DEF_CD) total_CD++;
        }
        return total_CD;
    }

    int Catalogo::quantidadeDeDVDs() const{
        int total_DVD = 0; 
        for(int i=0; i < quantidadeDeMidias(); i++){
            if(vMidia[i]->getTipo() == DEF_DVD) total_DVD++;
        }
        return total_DVD;
    }

    int Catalogo::quantidadeDeJogos() const{
        int total_JOGO = 0; 
        for(int i=0; i < quantidadeDeMidias(); i++){
            if(vMidia[i]->getTipo() == DEF_JOGO) total_JOGO++;
        }
        return total_JOGO;
    }

    void Catalogo::imprimeColecao() const{
        //outra opção : inserção ja ordenada ? sim
        for(auto it=vMidia.begin(); it != vMidia.end();it++)
            (*it)->imprimeFicha();
    }

    void Catalogo::imprimeColecaoPorTipo(int type) const{
        for(auto it=vMidia.begin(); it != vMidia.end();it++)
            if((*it)->getTipo()== type) (*it)->imprimeFicha();
    }



    bool Catalogo::CatalogoOrder(const Midia *M1, const Midia *M2){
        return *M1<*M2;
    }

}