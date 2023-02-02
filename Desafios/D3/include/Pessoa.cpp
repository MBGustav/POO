


#include "Pessoa.h"

namespace poo
{
    Pessoa::Pessoa(string _Nome, string _CPF): Nome(_Nome), CPF(_CPF)
    { //Cria no ponteiro um vetor de carros
        this->carro = new Carro*[MAX_CARRO];
        total_carros = 0;
    }

    Pessoa::~Pessoa()
    {
    }


    string Pessoa::getCPF() const{
        return this->CPF;
    }


    string Pessoa::getNome() const{
        return this->Nome;
    }


    void Pessoa::setCPF(string _CPF){
        this->CPF = _CPF;
    }


    void Pessoa::setNome(string _Nome){
        this->Nome = _Nome;
    }


    bool Pessoa::adicionaCarro(Carro *c){
        if(total_carros >= MAX_CARRO-1) return false;
        //else total_Carros<MAX_CARRO
        carro[total_carros++] = c;
        return true;
    }


    Carro* Pessoa::removeCarro(string placa){
        bool found = false;
        Carro *ptr_carro = NULL;
        int aux = 0;
        
        while (!found && aux<total_carros)
        {
            if(carro[aux]->getPlaca() == placa) found = true;
            else aux+=1;
        }
        if(found) {
            //Pega ponteiro do carro..
            ptr_carro = carro[aux];
            //substitui os valores de carros posteriores p/ organização do vetor.. 
        for(int i = aux; i < MAX_CARRO-1; i++)
            carro[i] = carro[i+1];
        }

        return ptr_carro; 
    }

    void Pessoa::imprime() const{
        std::cout << "Impressao Pessoa: \n";
        std::cout << "Nome: " << this->getNome() << std::endl;
        std::cout << "CPF: " << this->getCPF() << std::endl;
        std::cout << "Carros:\n";



    }
}
