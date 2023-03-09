#include "Poligono.h"

double Poligono::getPerimetro() const {

    double s = 0.f; 

    for(auto it = lados.begin(); it != lados.end(); it++){
        s += *it;
    }
    return s;

}

int Poligono::getNroLados() const{
    return lados.size();
}

double Poligono::getLado(int i) const{ 
    return lados[i-1];
}

void Poligono::imprime() const {
    std::cout <<  *this;   
}

ostream & operator<<(std::ostream &os, const Poligono &p){
    os << "NroLados " << p.getNroLados() << std::endl;
    os << "Perimetro" << p.getPerimetro() << std::endl;
    os << "Area" << p.getArea()<< std::endl;
}



