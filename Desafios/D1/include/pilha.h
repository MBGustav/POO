#ifndef __PILHA_HPP__

#define __PILHA_HPP__

class Pilha
{
private:
	int *array;
	int total;
	int max;

public:
	Pilha(int);
	Pilha();
	~Pilha();

	
	bool empilha( int x );
	bool desempilha( int& x );
	
	int tamanho() const;
	void imprime() const;


};





#endif //__PILHA_HPP__
