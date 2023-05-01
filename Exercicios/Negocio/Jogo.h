#ifndef JOGO_H
#define JOGO_H

#include "Produto.h"

namespace produtos{
  class Jogo : public Produto{
    public:
      Jogo(string titulo, double preco, int ano, string genero) : Produto(titulo, preco, ano), genero(genero){}
      virtual ~Jogo(){}
      virtual int getTipo() const{ return JOGO; }
      string getGenero() const{
        return this->genero;
      }
      static bool compara(const Jogo* j1, const Jogo* j2){
        if (j1->genero == j2->genero){
          return j1->getTitulo() < j2->getTitulo();
        }
        else{
          return j1->genero < j2->genero;
        }
      }
      virtual void imprime() const{
        Produto::imprime();
        cout << this->genero << " " << endl;
      }
    private:
      string genero;
  };
}


#endif