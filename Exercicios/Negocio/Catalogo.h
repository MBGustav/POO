#ifndef CATALOGO_H
#define CATALOGO_H

#include "Produto.h"
#include <vector>

namespace produtos{
  class Catalogo{
    public:
      Catalogo();
      virtual ~Catalogo();
      bool adicionaProduto(Produto* p){
        this->produtos.push_back(p);
        return true;
      }
      void imprime() const{
        sort(produtos.begin(), produtos.end(), Produto::compare);
        for (int i = 0; i < produtos.size(); i++){
          produtos[i]->imprime();
        }
      }
      int qtdeProdutos() const{
        return produtos.size();
      }
      int qtdeEbooks() const{
        return qtde(EBOOK);
      }
      int qtdeJogos() const{
        return qtde(JOGO);
      }
    private:
      vector<Produto*> produtos;
      int qtde(Tipo tipo) const{
        int qtde;
        for (int i = 0; i < produtos.size(); i++){
          if (produtos[i]->getTipo() == tipo){
            qtde++;
          }
        }
        return qtde;
      }
  };
}

#endif