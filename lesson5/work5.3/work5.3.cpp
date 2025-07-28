#include <iostream>
#include <windows.h>
#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrilateral.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"

void print_info(const Figure* figure) 
{
    figure->print_info();
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20, 22.36, 26.57, 63.43);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    RectangleShape RectangleShape(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    print_info(&triangle);
    print_info(&right_triangle);
    print_info(&isosceles_triangle);
    print_info(&equilateral_triangle);

    print_info(&quadrilateral);
    print_info(&RectangleShape);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);

    return EXIT_SUCCESS;
}