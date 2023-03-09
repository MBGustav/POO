

#include <string>
using std::string;
#include "Animal.h"

class Peixe : public Animal
{
private:
    string habitat;
public:
    Peixe(string, double, string);
    ~Peixe();

    void setHabitat(string);
    string getHabitat();
    virtual string getEspecie();
    virtual void imprime();

};

Peixe::Peixe(string N , double P , string H): Animal(N, P), habitat(H){}
Peixe::~Peixe(){}


void Peixe::setHabitat(string){}
string Peixe::getHabitat(){return habitat;}
string Peixe::getEspecie(){return "Peixe" ;}
void Peixe::imprime(){
    

}