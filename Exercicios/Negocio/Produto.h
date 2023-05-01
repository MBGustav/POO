#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <algorithm>
#include <iostream>
#include "Ebook.h"
#include "Jogo.h"

enum Tipo {EBOOK = 'E', JOGO = 'J'};

using namespace std;

namespace produtos{
  class Produto{
    public:
      Produto(string titulo, double preco, int ano){}
      virtual ~Produto(){}
      virtual int getTipo() const = 0;
      virtual string getTitulo() const{
        return this->titulo;
      }
      static bool compare(Produto* p1, Produto* p2){
        int t1 = p1->getTipo();
        int t2 = p2->getTipo();

        if (t1 == t2){
          if (t1 == EBOOK){
            return Ebook::compara(dynamic_cast<const Ebook*>(p1), dynamic_cast<const Ebook*>(p2));
          }
          else{
            return Jogo::compara(dynamic_cast<const Jogo*>(p1), dynamic_cast<const Jogo*>(p2));
          }
        }
        else{
          return t1 < t2;
        }
      }
      virtual void imprime() const{
        cout << "[" << (this->getTipo()?"Jogo":"Ebook") << "] ";
        cout << this->titulo << " ";
        cout << this->preco << " ";
        cout << this->ano << " ";
      }
    private:
      string titulo;
      double preco;
      int ano;
  };
}

#endif