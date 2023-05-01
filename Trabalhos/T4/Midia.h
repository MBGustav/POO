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
//outra maneira, mas como ? => enum!

namespace catalogo{

    typedef enum midia_type{
        type_CD=1,
        type_DVD, // DVD = 2 
        type_JOGO // JOGO = 3
    }midia_type;


    class Midia
    {
    protected:
       static midia_type type; 

    private:
        string Titulo;
        int anoCriacao;
        
    public:
//Constructor && Destructor
        Midia(string Titulo, int Ano);
        virtual ~Midia();
    
// metodos virtuais -- p/ subclasses
        virtual string getTitulo() const;
        virtual int getanoCriacao() const;
        virtual void imprimeFicha() const;

        virtual void setanoCriacao(int _anoCriacao);
//metodos abstratos -- decl. em CD, DVD & JOGO
        virtual int getTipo() const = 0;
        virtual void imprimeDados() const=0;

//Metodos de Comparacao
        static bool comparaTitulo(const Midia* M1, const Midia* M2);
        static bool comparaAno(const Midia* M1, const Midia* M2);
        
        bool operator>(const Midia & M) const;
        bool operator<(const Midia & M) const;
        
    };




}


#endif // __MIDIA_H__

