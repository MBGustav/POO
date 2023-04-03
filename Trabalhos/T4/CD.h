#ifndef __CD_H__
#define __CD_H__

#include <iostream> 
using std::pair;
#include <string>
using std::string;
#include <vector>
using std::vector;



#include "Midia.h"  
#include "Faixa.h"
namespace catalogo{
    // typedef struct data_CD{string *Nome;int Duracao;}data_CD;

    class CD : public Midia
    {
    private:
        string Artista;
        long unsigned int totalFaixas;
        vector<Faixa*> Faixas; 
        // vector<pair<string,int>> Faixas;
        // static 
    public:
        CD(const string titulo, int ano,string artista);
        string getArtista() const;

        virtual int getTipo()const;
        virtual void imprimeDados() const;
        virtual ~CD();
        void adicionaFaixa(string nome, int duracao); 
        // void adicionaFaixa(Faixa &F);
        long int getTotalFaixas()const;
        // Faixa &GetFaixa(int) const;
    };

    //Inicializa sempre em 0;
    // long int CD::totalFaixas = 0;
}

#endif //__CD_H__

