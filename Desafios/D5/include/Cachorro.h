#ifndef  __CACHORRO_H__
#define  __CACHORRO_H__

#include <string> 
using std::string;

#include "AnimalDomestico.h"


class Cachorro : public AnimalDomestico
{
private:
    string raca;
public:
    Cachorro(string Nome, double peso, string raca);
    virtual ~Cachorro();

    string getRaca() const;
    void imprime() const;
};


#endif //__CACHORRO_H__