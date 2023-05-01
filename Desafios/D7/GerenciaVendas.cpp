
#include "GerenciaVendas.h"


GerenciaVendas::GerenciaVendas(string _fileName) : fileName(_fileName){}

double GerenciaVendas::totalVendas(int id){
    ifstream file(fileName, ios::binary);
    Venda v;
    double  total = 0.0f;
    if(file.is_open()){//Verifica se arquivo existe
        file.read(reinterpret_cast<char*>(&v), sizeof(Venda));
        
        //Enquanto nao chegarmos ao final do arquivo, itera
        while(file.good()){
            
            //Verifica id de Venda
            if(v.getID() == id) 
                total += v.getQuantidade() * v.getValor();
            // Movimentamos o ponteiro ao final da iteracao
            file.read(reinterpret_cast<char*>(&v), sizeof(Venda)); 
        }
        file.close();
    }


    return total;
}
double GerenciaVendas::mediaVendas(int id){
    ifstream file(fileName, ios::binary); 
    Venda  v; 

    double qtd=0, val=0;
    if(file.is_open()){
        file.read(reinterpret_cast<char*> (&v), sizeof(Venda));    

        while(file.good()){
            if(v.getID() == id){
                qtd += v.getQuantidade();
                val += v.getValor();
            }

            file.read(reinterpret_cast<char*>(&v),sizeof(Venda));
        }

        file.close();

        if(qtd == 0)
            throw string("Nao Disponivel\n");
    } else {
        throw string("Arquivo nao encontrado!");
    }

    return qtd/val;
}
Venda GerenciaVendas::maiorVenda(){
    Venda v, Mv;
    double maiorValor;
    ifstream file(fileName, ios::binary);
    
    
    if(file.is_open()){
        file.read(reinterpret_cast<char*>(&v), sizeof(Venda));
        file.read(reinterpret_cast<char*>(&Mv), sizeof(Venda));
        while(file.good()){
            if(v.getValor() * v.getQuantidade() < maiorValor)
            {
                Mv = v;
                maiorValor = v.getQuantidade() * v.getValor();
            }


        file.read(reinterpret_cast<char*>(&v), sizeof(Venda));
        }

        file.close();
    }




    return v;
}