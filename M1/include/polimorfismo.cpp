#include <iostream>


float soma(float a, float b){
    return 1 + a+b;
}

int soma(int a, int b){
    return 2 + a+b;
}
int main(){
    float a = 2.0f;
    float b = 2.0f;

    int ia = 2.0f;
    int ia = 2.0f;

    std::cout << "float:" << soma(a,b);
    std::cout << "int:" << soma(ia,ib);


    return 0;
}
