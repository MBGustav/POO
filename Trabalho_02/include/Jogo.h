#ifndef __JOGO_H__
#define __JOGO_H__

#include <iostream> 
#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Midia.h"  
namespace catalogo{
    class Jogo : public Midia
    {
    private:
        string Genero;

    public:
        Jogo(string titulo, int anoCriacao, string genero);

        virtual int getTipo() const;
        virtual void imprimeDados() const;
        virtual ~Jogo();
    };
}



#endif //__JOGO_H__

