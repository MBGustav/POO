#include <iostream>
#include <string>

using std::string;
using std::cout, std::endl;


class Animal
{
private:
    string Nome;
    double Peso; 
public:
    Animal(string, double);
    ~Animal();
    string getNome(); 
    void setNome(string);
    void setPeso(double);

    double getPeso();
    virtual string getEspecie() const = 0;
    virtual void imprime();
};

Animal::Animal(string N, double P): Nome(N), Peso(P){}

Animal::~Animal(){

}
void Animal::setNome(string N){this->Nome = N;}
void Animal::setPeso(double N){this->Peso = N;}

string Animal::getNome(){return this->Nome;} 
double Animal::getPeso(){return this->Peso;} 


void Animal::imprime(){
    cout << "Especie " << this->getEspecie() << endl;
    cout << "Nome " << this->getNome() << endl;
    cout << "Peso " << this->getPeso() << endl; 
}