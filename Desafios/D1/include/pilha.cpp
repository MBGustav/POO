
#include <iostream>
#include "pilha.h"

Pilha::Pilha(int x){
	array = new int[x];
	max = x;
	total = 0;
}

Pilha::Pilha(){
	array = new int[10];
	max = 10;
	total = 0;
}

bool Pilha::empilha( int x){
	
	if(total > max) return false; 
	// if total < max..
	array[total++] = x;
	return true;

}
bool Pilha::desempilha( int& x ){
	if(total == 0) return false;

	x = array[total--];
	return true;
}
int  Pilha::tamanho() const{
	return this->total;
}
void Pilha::imprime() const{

	for(auto i = 0; i < total; i++)
		std::cout << "pos[" << i << "] = " 
				  <<  array[i] <<std::endl;
}

Pilha::~Pilha(){

}