
#include <iostream>
#include "Aluno.hpp"

//Exemplo errado !
// Aluno::Aluno(std::string, int idade)
// {
//   //Quando nao ha chamada do construtor pai, 
//   //o compilador busca por um construtor padrao
//   //que nada mais eh um construtor vazio.
// }

//Exemplo correto !

Aluno::Aluno(std::string nome,int idade, int RA) : Pessoa(nome, idade), RA(RA){
  
}

int Aluno::getRA() const{return this->RA;}
void Aluno::setRA(int RA){this->RA = RA;}

void Aluno::imprime() const
{
    std::cout << "\nImpressao do tipo - Aluno\n";
    Pessoa::imprime();//Executa a função de pessoa, e complementa
    std::cout << "RA: " << this->RA << "\n" << std::endl; 
}

Aluno::~Aluno()
{
    std::cout << "Destroi Aluno\n";
}


