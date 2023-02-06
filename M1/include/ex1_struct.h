#include <cmath>
#include <cstdio>

struct point{
  float x, y, z;
};

//Construtores (3D) & (2D)
struct point *new_point3D(float x1, float y1, float z1){
  struct point *ptr;
  ptr = (struct point*) malloc(sizeof(struct point));

  ptr->x = x1;
  ptr->y = y1;
  ptr->z = z1;
  return ptr;  
}
struct point *new_point2D(float x1, float y1){
  struct point *ptr;
  ptr = (struct point*) malloc(sizeof(struct point));
  ptr->x = x1;
  ptr->y = y1;
  ptr->z = 0.0f;
  return ptr;  
}

//Distancia entre 2 pontos -> estrutural
float dist_point(struct point *P1, struct point *P2)
{
  float a,b,c;
  a = P2->x - P1->x;
  b = P2->y - P1->y;
  c = P2->z - P1->z;
  return sqrt(a*a + b*b + c*c);
}

void print_point(struct point *P1){printf("Struct (%.3f, %.3f)\n", P1->x, P1->y);}

void move_point(struct point *P1,float x, float y)
{
  P1->x = x;
  P1->y = y;
}