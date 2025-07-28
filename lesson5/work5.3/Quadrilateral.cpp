#include "Quadrilateral.h"
#include <iostream>

Quadrilateral::Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D) : Figure("���������������", 4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

void Quadrilateral::print_info() const 
{
    std::cout << get_name() << ":\n";
    std::cout << "�������: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
    std::cout << "����: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
}