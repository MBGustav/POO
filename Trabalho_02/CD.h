#ifndef __CD_H__
#define __CD_H__

#include <iostream> 
using std::pair;
#include <string>
using std::string;
#include <vector>
using std::vector;



#include "Midia.h"  

namespace catalogo{
    // typedef struct data_CD{string *Nome;int Duracao;}data_CD;

    class CD : public Midia
    {
    private:
        string Artista;
        vector<pair<string,int>> Faixas;
        // static 
        long int totalFaixas;
    public:
        CD(const string, int ,string);
        void adicionaFaixa(string nome, int duracao); 

        string getArtista() const;
        long int getTotalFaixas()const;


        virtual int getTipo()const;
        virtual void imprimeDados() const;
        virtual ~CD();
    };

    //Inicializa sempre em 0;
    // long int CD::totalFaixas = 0;
}

#endif //__CD_H__

