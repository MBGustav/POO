#ifndef __CATALOGO_H__
#define __CATALOGO_H__

//Built-in Libraries
#include <iostream>
using std::cout, std::cin, std::endl, std::getline;

#include <algorithm>
using std::sort;

#include <cstring>
using std::memset;
#include <string>
using std::string;
#include <fstream> 
using std::ifstream, std::ofstream;
using std::ios;
//Usr Libraries 
#include "Midia.h"
#include "Jogo.h"
#include "CD.h"
#include "DVD.h"




//Catalog Declarations
#define MAX_MIDIA 100

namespace catalogo{

class Catalogo{
    private:
        Midia **midia;
        vector<Midia*> vMidia;
        
        string filename;

        void grava(); 
        void recupera();

        int indice(string Titulo)const;
        
        static bool CatalogoOrder(const Midia *M1, const Midia *M2);
        
    public:
        // Catalogo();
        Catalogo(string filename);
        ~Catalogo();

        bool adicionaMidia(int tipo);
        bool adicionaMidia(Midia &); 
        
        bool removeMidia(string c);
        Midia* obtemMidia(string c); 

        // int indice(string nome_midia) const;
        static char opcao();
        static bool continuar(int tipo);

        int quantidadeDeMidias() const;
        int quantidadeDeCDs() const;
        int quantidadeDeDVDs() const;
        int quantidadeDeJogos() const;
        void imprimeColecao(bool ord);
        void imprimeColecao(string Titulo);
        void imprimeColecaoPorTipo(int) const;

        bool ModificaAno(string Titulo, int Ano);
        void Clear_All();
    };




} // namespace Catalogo









#endif //__CATALOGO_H__