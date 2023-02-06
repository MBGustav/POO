
#include <iostream>
#include "ex1_obj.hpp"
#include "ex1_struct.h"
int main()
{
    Point  p1(3.0, 4.0, 9.0);
    Point *p2 = new Point(0,0);

    point *P1 = new_point3D(3.0, 4.0, 9.0);
    point *P2 = new_point2D(3.0, 4.0);

    float dist_st = dist_point(P1, P2);
    float dist_oo = p1.dist_point(p2);

    p1.print();
    print_point(P1);

    return 0;
}