#include "Catalogo.h"
#include "Produto.h"
#include "Jogo.h"
#include "Ebook.h"

using namespace produtos;

int main(){
  int n, a;
  char tipo;
  string b, c;
  double d;
  Catalogo c1();
  Produto* p;
  cin >> n;
  while(n--){
    cin >> b;
    cin >> a >> d;
    cin >> c;
    switch(tipo){
      case 'E':
        p = new Ebook(b, a, d, c);
        c1.adicionaProduto(p);
        break;
      case 'J':
        p = new Jogo(b, a, d, c);
        c1.adicionaProduto(p);
        break;
    }
  }
  c1.imprime();
}


