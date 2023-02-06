#include <cmath>
#include <cstdio>

class Point{
  public:
    Point(float, float);
    Point(float, float, float);
    //funcoes-membro
    float dist_point(Point *P1);
    void print();
    void move(float x, float y);
  private:
  float x,y, z;
};

//Construtores (3D) & (2D)
Point::Point(float x1, float y1, float z1):x(x1), y(y1), z(z1) {}
Point::Point(float x1, float y1):x(x1), y(y1),z(0.0f) {}

//Distancia entre 2 pontos - OO
float Point::dist_point(Point *P1)
{
  float a,b,c;
  a = this->x - P1->x; 
  b = this->y - P1->y;
  c = this->z - P1->z;
  
  return sqrt(a*a + b*b + c*c);
}

void Point::print(){printf(" Object: (%.3f, %.3f)\n", x, y);}

void Point::move(float x, float y)
{
  this->x = x;
  this->y = y;
}