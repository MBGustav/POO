#include "Artista.h"

namespace catalogo{
Artista::Artista(std::string Nome,std::string Papel):
Nome(Nome), Papel(Papel){}
Artista::~Artista(){}

string Artista::getNome() const{return this->Nome;}
string Artista::getPapel() const{return this->Papel;}

}