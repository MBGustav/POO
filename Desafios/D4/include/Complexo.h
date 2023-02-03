#ifndef __COMPLEXO_H__
#define __COMPLEXO_H__

//Builtin Libs
#include <iostream>
#include <cmath>
using std::fabs;
using std::ostream;


class Complexo
{
private:
    float a, b; 
public:
    Complexo(float r, float i);
    ~Complexo();
    Complexo operator+(const Complexo &a);
    Complexo operator-(const Complexo &a);
    Complexo operator*(const Complexo &a);
    Complexo operator/(const Complexo &a); 
    Complexo operator-();
    //qual a função do friend ? -> declaracao fora ?
    friend ostream &operator<<(ostream &os, const Complexo &a);

};










#endif  // __COMPLEXO_H__