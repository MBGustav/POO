#include <iostream> 

#include "Pessoa.hpp"
#include "Aluno.hpp"

int main() {

  Pessoa P("Joao", 50);
  Aluno A("Fulano", 18, 587890);

  P.imprime();
  A.imprime();


  return 0;
}

