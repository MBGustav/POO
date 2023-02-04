
#include "Pessoa.h"


Pessoa::Pessoa(string _nome, int _idade):
        nome(_nome), idade(_idade)
{
    total_animals = 0;
    // memset(animals, NULL, MAX * sizeof(AnimalDomestico*));
    for(int i = 0; i < MAX; i++)
        animals[i] = NULL;
}

Pessoa::~Pessoa()
{}

string Pessoa::getnome() const {return this->nome;}
int Pessoa::getidade() const {return this->idade;}


bool Pessoa::adiciona(AnimalDomestico *A){
    bool added = false; 

    if(total_animals < MAX ){
        //insere no vetor && aumenta nro de animais
        animals[total_animals++] = A;
        //insere dono
        A->setDono(this);
        added = true;
    }


    return added;
}

bool Pessoa::remove(string _nome){
    bool found = false;
    int aux = 0;
    //itera sobre todo o vetor em busca de "nome"
    while(!found && aux < total_animals){
        if(_nome == animals[aux]->getnome()) found = true;
        else aux++;
    }
    
    if(found){// remove o animal encontrado
        for(int i = aux; i < total_animals-1;i++){
            animals[i] = animals[i+1];
        }
    }

    return found;
}

void Pessoa::imprime() const {
    
    std::cout << "Nome: "  << getnome()  << std::endl;
    std::cout << "Idade: " << getidade() << std::endl;
    std::cout << "==== Animais ====\n";
    for(int i = 0; i < total_animals; i++){
        animals[i]->imprime(); 
        std::cout << std::endl;
    }






}