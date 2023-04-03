#ifndef __DVD_H__
#define __DVD_H__


#include <iostream> 
using std::pair;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Midia.h" 

#include "Artista.h"

namespace catalogo{

    // typedef struct data_DVD{string *N_artista; string *Papel;}data_DVD;

    class DVD  : public Midia
    {
    private:
        string Diretor;

        // vector<Artista *> Artistas;
        // vector<pair<string, string>> Artistas;
        int totalArtistas;
    public:
        DVD(std::string titulo, int ano,std::string diretor);
        virtual ~DVD();
        virtual int getTipo() const;
        string getDiretor() const; 
        virtual void imprimeDados() const;
        
        

        // void adicionaArtista(string Artista, string Papel);
        // void adicionaArtista(Artista &A);
        // Artista& GetArtista(int idx);
        // int gettotalArtistas() const;

    };

    //Inicializa em ZERO
    // int DVD::totalArtistas = 0;
}
#endif //__DVD_H__

