#ifndef __ARTISTA_H__
#define __ARTISTA_H__


#include <string>
using std::string;
#include "Midia.h"


namespace catalogo{
    class Artista{
    private:
        std::string Nome, Papel;
    public:
        Artista(std::string Nome,std::string Papel);
        ~Artista();
        string getNome() const;
        string getPapel() const;
    };
    
}

#endif // __ARTISTA_H__
