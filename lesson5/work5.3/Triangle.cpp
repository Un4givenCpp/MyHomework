#include "Triangle.h"
#include <iostream>

Triangle::Triangle(double a, double b, double c, double A, double B, double C)
    : Figure("Треугольник", 3), a(a), b(b), c(c), A(A), B(B), C(C) {}

void Triangle::print_info() const 
{
    std::cout << get_name() << ":\n";
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
}