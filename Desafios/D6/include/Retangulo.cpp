
#include "Retangulo.h"


Retangulo::Retangulo(std::vector<double> & L) : Poligono(L){}



double Poligono::getArea() const {
    return this->getLado(1) * this->getLado(2);
}

bool Poligono::comparaArea(const Poligono *p1, const Poligono *p2){
    return p1->getArea() > p2->getArea();
}

bool Poligono::comparaNroLados(const Poligono *p1, const Poligono *p2){ 
    return p1->getNroLados() > p2->getNroLados();

}

Retangulo::~Retangulo()
{

}

