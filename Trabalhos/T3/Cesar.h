#ifndef __CESAR_H__
#define __CESAR_H__

#include <string>
using std::string;

#include <algorithm>
using std::getline;
#include <fstream>
using std::ifstream, std::ofstream;

#include <vector>
using std::vector;

#include <iostream>



namespace cifra{
    typedef const std::string cstring;
    typedef std::vector<std::string>  s_vector;

    

    class Cesar
    {
    private:
    void transf(char& c, const int k);
    public:
        Cesar();
        ~Cesar();
        void encripte(cstring in, cstring out, const int k);
    };
    
    Cesar::Cesar(){}
    Cesar::~Cesar(){}
    void Cesar::encripte(cstring in, cstring out, const int k){
        ifstream input_file(in, ifstream::in);
        ofstream output_file(out, ofstream::out);
        s_vector linhas;
        string linha; 
        
        // Abertura do Arquivo - alteração do em k posicoes
        while(getline(input_file, linha)){
            for(size_t i=0; i< linha.size(); i++){
                transf(linha[i], k);
                std::cout << linha[i];
            }
                std::cout << std::endl;
        
            linhas.push_back(linha);
        }

        for(size_t i=0; i < linhas.size(); i++)
            output_file << linhas[i] << std::endl;
            
        input_file.close();
        output_file.close();
    
    }

        void Cesar::transf(char& c, const int k){
            
            int aux = k;
            if(k != std::abs(k))
                aux = 26 - std::abs(k)%26;

            //Set Conditions to change letters
            if ('A' <= c  && c <= 'Z') 
                c = (char)((int) 'A' + ((c-'A')+aux)%26);
            else if (c >= 'a' && c <= 'z')
                c = (char)((int) 'a' + ((c-'a')+aux)%26);
        }

}   


#endif // __CESAR_H__
