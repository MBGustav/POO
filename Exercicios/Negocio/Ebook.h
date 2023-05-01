#ifndef EBOOK_H
#define EBOOK_H

#include "Produto.h"

namespace produtos{
  class Ebook : public Produto{
    public:
      Ebook(string titulo, double preco, int ano, string autor) : Produto(titulo, preco, ano), autor(autor){}
      virtual ~Ebook(){}
      virtual int getTipo() const{ return EBOOK; }
      string getAutor() const{
        return this->autor;
      }
      static bool compara(const Ebook* e1, const Ebook* e2){
          if (e1->autor == e2->autor){
            return e1->getTitulo() < e2->getTitulo();
          }
          else{
            return e1->autor < e2->autor;
          }
      }
      virtual void imprime() const{
        Produto::imprime();
        cout << this->autor << " " << endl;
      }
    private:
      string autor;
  };
}


#endif