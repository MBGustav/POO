#include "Complexo.h"


Complexo::Complexo(float real, float imaginary): a(real), b(imaginary)
{}
Complexo::~Complexo()
{}

Complexo Complexo::operator+(const Complexo &_z){
    return Complexo(_z.a + this->a, _z.b + this->b);
}

Complexo Complexo::operator-(const Complexo &_z){
    return Complexo(_z.a - this->a, _z.b - this->b);
}

//Ele cria um outro objeto? acho que nao, a alteração eh feita no proprio obj.
Complexo Complexo::operator-(){
    return Complexo(-this->a, -this->b);
}

// A multiplicação z1(a+bi) ∗ z2(c+di) = ac − bd + (ad + bc)i.
// Exemplo: z1 = 1 + 2i e z2 = 3 + 4i. A multiplicação z1 ∗ z2 = −5 + 10i.
Complexo Complexo::operator*(const Complexo &_z){
    return Complexo(this->a*_z.a -this->b*_z.b, this->a*_z.b + this->b * _z.a);
}


Complexo Complexo::operator/(const Complexo &_z){
    //z1 = a+bi ; z2 = c+di
    //div  = c² + d²
    //real = a*c - b*d
    //img  = b*c + a*d
    float div = (_z.a*_z.a + _z.b *_z.b);
    float real = this->a * _z.a + this->b * _z.b;
    float img  = this->b * _z.a - this->a * _z.b;
    return Complexo(real/div, img/div);

}

//?? Porque retornamos os, e colocamos como parametro ? 
//Porque este metodo eh fora da classe ?
//o cout é um objeto de ostream, que precisa ser enviado como parametro para nosso
//para o retorno, é porque ele pode ser usado em longas cadeias. 
//metodos friend  eh uma liberação de acesso a todos os elementos
// que permitem o acesso a funções do 
 ostream &operator<<(ostream &os, const Complexo &_z){
    os << _z.a << (_z.b>0 ? " + ": " - ") << fabs(_z.b) <<"i" ;
    return os;
}




