#include <iostream>
#include <string>
#include <windows.h>


class Figure 
{
protected:
    std::string name;
    int sides_count;

public:
    Figure(std::string n, int s) : name(n), sides_count(s) {}
    virtual ~Figure() {}
    virtual void print_info() const = 0;
    std::string get_name() const { return name; }
    int get_sides_count() const { return sides_count; }
};


class Triangle : public Figure 
{
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : Figure("Треугольник", 3), a(a), b(b), c(c), A(A), B(B), C(C) {}

    void print_info() const override {
        std::cout << get_name() << ":\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};


class RightTriangle : public Triangle 
{
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90) 
    {
        name = "Прямоугольный треугольник";
    }
};


class IsoscelesTriangle : public Triangle 
{
public:
    IsoscelesTriangle(double a, double b, double A, double B)
        : Triangle(a, b, a, A, B, A) 
    {
        name = "Равнобедренный треугольник";
    }
};


class EquilateralTriangle : public Triangle 
{
public:
    EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) 
    {
        name = "Равносторонний треугольник";
    }
};


class Quadrilateral : public Figure 
{
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D) : Figure("Четырехугольник", 4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    void print_info() const override 
    {
        std::cout << get_name() << ":\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};


class Rectanglee : public Quadrilateral 
{
public:
    Rectanglee(double a, double b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) 
    {
        name = "Прямоугольник";
    }
};


class Square : public Quadrilateral 
{
public:
    Square(double a) : Quadrilateral(a, a, a, a, 90, 90, 90, 90) 
    {
        name = "Квадрат";
    }
};


class Parallelogram : public Quadrilateral 
{
public:
    Parallelogram(double a, double b, double A, double B) : Quadrilateral(a, b, a, b, A, B, A, B) 
    {
        name = "Параллелограмм";
    }
};


class Rhombus : public Quadrilateral 
{
public:
    Rhombus(double a, double A, double B) : Quadrilateral(a, a, a, a, A, B, A, B) 
    {
        name = "Ромб";
    }
};

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
    Rectanglee rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    print_info(&triangle);
    print_info(&right_triangle);
    print_info(&isosceles_triangle);
    print_info(&equilateral_triangle);

    print_info(&quadrilateral);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);

    return EXIT_SUCCESS;
}