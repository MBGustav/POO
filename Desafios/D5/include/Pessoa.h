#ifndef  __PESSOA_H__
#define  __PESSOA_H__

#include <string> 
#include <cstring>

using std::string, std::memset;

#define MAX 4
#include "AnimalDomestico.h"
class AnimalDomestico;
class Pessoa
{
private:
    string nome; 
    int idade;
    int total_animals;
    
    AnimalDomestico *animals[MAX];
public:
    Pessoa(string nome, int idade);
    ~Pessoa();

    string getnome() const;
    int getidade() const;
    bool adiciona(AnimalDomestico *A);
    bool remove(string nome); 

    void imprime() const;
};


#endif //__PESSOA_H__