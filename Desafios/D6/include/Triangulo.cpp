#include "Triangulo.h"
#include <cmath>


Triangulo::Triangulo(vector<double> &L): Poligono(L){}

double Triangulo::getArea() const{
    double p = this->getPerimetro();
    for(size_t i = 0; i < this->getNroLados(); i++){
        p *= p - getLado(i+1);
    }
    return sqrt(p);
}

