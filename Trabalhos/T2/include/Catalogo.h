#ifndef __CATALOGO_H__
#define __CATALOGO_H__

//Built-in Libraries
#include <iostream>
using std::cout, std::endl;

#include <algorithm>
using std::sort;

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
        vector<Midia*> vMidia;
        
    public:
        Catalogo();
        ~Catalogo();

        bool adicionaMidia(Midia &); 
        bool removeMidia(string c);
        Midia* obtemMidia(string c); 

        int quantidadeDeMidias() const;
        int quantidadeDeCDs() const;
        int quantidadeDeDVDs() const;
        int quantidadeDeJogos() const;
        void imprimeColecao() const;
        void imprimeColecaoPorTipo(int) const;

        static bool CatalogoOrder(const Midia *M1, const Midia *M2);
    };




} // namespace Catalogo









#endif //__CATALOGO_H__