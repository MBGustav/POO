#ifndef __FAIXA_H__
#define __FAIXA_H__


#include <string>
using std::string;
#include "Midia.h"


namespace catalogo{
    class Faixa{
    private:
        std::string Nome; 
        int duracao;
    public:
        Faixa(std::string Nome, int duracao);
        ~Faixa();

        int getDuracao() const;
        int getMinutos() const;
        int getSegundos() const;
        string getNome() const;
    };
    
}

#endif // __FAIXA_H__
