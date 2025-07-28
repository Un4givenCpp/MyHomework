#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Quadrilateral.h"

class RectangleShape : public Quadrilateral 
{
public:
    RectangleShape(double a, double b);
};

#endif // RECTANGLE_H