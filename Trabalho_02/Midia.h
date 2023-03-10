#ifndef __MIDIA_H__
#define __MIDIA_H__

#include <iostream>
using std::cout, std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iomanip>
using std::setfill, std::setw;

#define MAX_FAIXAS 1000
#define MAX_ARTISTAS 1000
#define DEF_CD 1
#define DEF_DVD 2
#define DEF_JOGO 3
//outra maneira, mas como ? 

namespace catalogo{
    typedef enum midia_type{
        vCD=1,
        vDVD, // DVD = 2 
        vJOGO // JOGO = 3
    }midia_type;


    class Midia
    {
    protected:
       static midia_type type; 

    private:
        string Titulo;
        int anoCriacao;
        
    public:
        Midia(string Titulo, int Ano);

        virtual string getTitulo() const;
        virtual int getanoCriacao() const;

        
        virtual void imprimeFicha() const;

//metodos abstratos -- decl. em CD, DVD & JOGO
        virtual int getTipo() const = 0;
        virtual void imprimeDados() const=0;

        
        
        virtual ~Midia();
    };

}


#endif // __MIDIA_H__

