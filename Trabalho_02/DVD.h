#ifndef __DVD_H__
#define __DVD_H__


#include <iostream> 
using std::pair;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Midia.h"  
namespace catalogo{

    // typedef struct data_DVD{string *N_artista; string *Papel;}data_DVD;

    class DVD  : public Midia
    {
    private:
        string Diretor;
        vector<pair<string, string>> Artistas;
        int totalArtistas;
    public:
        DVD(string, int ,string);
        virtual ~DVD();
        
        void adicionaArtista(string Artista, string Papel);
        virtual int getTipo() const;
        
        int gettotalArtistas() const;
        string getDiretor() const; 

        virtual void imprimeDados() const;

    };

    //Inicializa em ZERO
    // int DVD::totalArtistas = 0;
}
#endif //__DVD_H__

