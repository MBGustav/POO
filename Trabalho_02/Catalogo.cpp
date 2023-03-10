#include "Catalogo.h"


namespace catalogo
{

    bool Catalogo::adicionaMidia(Midia &M){

    }
    bool Catalogo::removeMidia(string titulo){
        bool removed = false;
        // Midia *aux_M = obtemMidia(m_name);
        // if(aux_M == NULL) return false; 
        
        // return true;


    }
    Midia* Catalogo::obtemMidia(string titulo){
        int x = quantidadeDeMidias(); 
        while (x-->0)
        {
            if(midia[x]->getTitulo() == titulo){
                return midia[x];
        }
        
        return NULL;

    }

    int Catalogo::quantidadeDeMidias() const{
        return (int)(totalMidia);
    }
    
    int Catalogo::quantidadeDeCDs() const{
        int total_CD = 0; 
        for(int i=0; i < quantidadeDeMidias(); i++){
            if(midia[i]->getTipo() == DEF_CD) total_CD++;
        }
        return total_CD;
    }

    int Catalogo::quantidadeDeDVDs() const{
        int total_DVD = 0; 
        for(int i=0; i < quantidadeDeMidias(); i++){
            if(midia[i]->getTipo() == DEF_DVD) total_DVD++;
        }
        return total_DVD;
    }

    int Catalogo::quantidadeDeJogos() const{
        int total_JOGO = 0; 
        for(int i=0; i < quantidadeDeMidias(); i++){
            if(midia[i]->getTipo() == DEF_JOGO) total_JOGO++;
        }
        return total_JOGO;
    }

    void Catalogo::imprimeColecao() const{
        //necessario ?
        vector<Midia*> v_aux;
        for(int i = 0; i<totalMidia; i++){
            v_aux.push_back(midia[i]);
        } 
        //outra opção : inserção ja ordenada ?
        // sort_midia(v_aux);
        for(int i=0; i< totalMidia;i++)
            v_aux[i]->imprimeFicha();
    }


    void Catalogo::imprimeColecaoPorTipo(int) const{

    }

}