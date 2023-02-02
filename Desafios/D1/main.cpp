#include <iostream>
#include "include/pilha.h"
using namespace std;

int main() {
   	int tamanhoImpar;
   	cout << "A pilha par terá o tamanho padrao." << endl;
   	cout << "Entre com o tamanho da pilha impar: ";
   	// cin  >> tamanhoImpar;

	tamanhoImpar = 10;
	Pilha par;
	Pilha impar(tamanhoImpar);

	int i = 1;
    while(par.empilha(i*2)) {
        i++;
	}

	i = 0;
    while(impar.empilha(i*2+1)) {
    	i++;
	}

    cout << "Pilha Par: ";
    par.imprime();
    
	while (par.desempilha(i)) {
		cout << "Desempilhando " << i << endl;
		cout << "Pilha Par: ";
		par.imprime();
	}

	cout << endl << "Pilha Impar: ";
    impar.imprime();

	while (impar.desempilha(i)) {
		cout << "Desempilhando " << i << endl;
		cout << "Pilha Impar: ";
		impar.imprime();
	}

    return 0;
}
