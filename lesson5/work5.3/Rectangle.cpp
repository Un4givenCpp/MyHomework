#include "Rectangle.h"

RectangleShape::RectangleShape(double a, double b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) 
{
    name = "Прямоугольник";
}