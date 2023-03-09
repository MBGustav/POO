

#include <string>
using std::string;
#include "Animal.h"

class Cachorro : public Animal
{
private:
    string raca;
public:
    Cachorro(string, double, string);
    ~Cachorro();

    void setHabitat(string);
    string getRaca();
    virtual string getEspecie();
    virtual void imprime();

};

Cachorro::Cachorro(string N , double P , string H): Animal(N, P), raca(H){}

Cachorro::~Cachorro()
{
}


void Cachorro::setHabitat(string){}
string Cachorro::getRaca(){return raca;}
string Cachorro::getEspecie(){return "Cachorro";}
void Cachorro::imprime(){

}