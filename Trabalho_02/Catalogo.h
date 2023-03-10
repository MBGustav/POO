#ifndef __CATALOGO_H__
#define __CATALOGO_H__

//Built-in Libraries
#include <iostream>
using std::cout, std::endl;

#include <cstring>
using std::memset;
//Usr Libraries 
#include "Midia.h"

//Catalog Declarations
#define MAX_MIDIA 100

namespace catalogo{

class Catalogo{
    private:
        Midia **midia;
        int totalMidia;
    public:
        Catalogo();
        ~Catalogo();

        bool adicionaMidia(Midia &); 
        bool removeMidia(string);
        Midia* obtemMidia(string); 

        int quantidadeDeMidias() const;
        int quantidadeDeCDs() const;
        int quantidadeDeDVDs() const;
        int quantidadeDeJogos() const;
        void imprimeColecao() const;
        void imprimeColecaoPorTipo(int) const;


    };

        Catalogo::Catalogo(){
            //Alocacao Dinamica de Memoria
            midia = new Midia*[MAX_MIDIA];
            //Preenche vetor com posicao nula
            //PORQUE WARNING com NULL?
            memset(midia, 0, MAX_MIDIA * sizeof(midia));
        }

        Catalogo::~Catalogo(){}


} // namespace Catalogo









#endif //__CATALOGO_H__