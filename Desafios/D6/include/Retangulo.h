#ifndef __RETANGULO_H__
#define __RETANGULO_H__

#include <vector>
#include "Retangulo.h"
#include "Poligono.h"

class Retangulo :public Poligono
{
private:

public:
    Retangulo(std::vector<double> &L);
    ~Retangulo();
};






#endif