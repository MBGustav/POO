#ifndef  __PEIXE_H__
#define  __PEIXE_H__

#include "AnimalDomestico.h"
class Peixe : public AnimalDomestico
{
private:
string tipoHabitat;

public:
    Peixe(string nome, double peso, string habitat);
    virtual ~Peixe();

    virtual void imprime() const;
    string gethabitat() const;
};



#endif //__PEIXE_H__