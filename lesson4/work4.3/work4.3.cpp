#include <iostream>
#include <string>
#include <windows.h>

class Figure 
{
protected:
    std::string name;
    int sides_count;

public:
    Figure() : name("Фигура"), sides_count(0) {}
    virtual ~Figure() {}

    virtual void print_info() const 
    {
        std::cout << name << ":\n";
        std::cout << (check() ? "Правильная" : "Неправильная") << "\n";
        std::cout << "Количество сторон: " << sides_count << "\n";
    }

    virtual bool check() const 
    {
        return sides_count == 0;
    }
};

class Triangle : public Figure 
{
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C) 
    {
        name = "Треугольник";
        sides_count = 3;
    }

    void print_info() const override 
    {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }

    bool check() const override 
    {
        return (sides_count == 3) && (A + B + C == 180);
    }
};

class RightTriangle : public Triangle 
{
public:
    RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90)
    {
        name = "Прямоугольный треугольник";
    }

    bool check() const override {
        return Triangle::check() && (C == 90);
    }
};

class IsoscelesTriangle : public Triangle 
{
public:
    IsoscelesTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A) 
    {
        name = "Равнобедренный треугольник";
    }

    bool check() const override 
    {
        return Triangle::check() && (a == c) && (A == C);
    }
};

class EquilateralTriangle : public Triangle 
{
public:
    EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) 
    {
        name = "Равносторонний треугольник";
    }

    bool check() const override 
    {
        return Triangle::check() && (a == b && b == c) && (A == 60 && B == 60 && C == 60);
    }
};

class Quadrilateral : public Figure 
{
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) 
    {
        name = "Четырехугольник";
        sides_count = 4;
    }

    void print_info() const override 
    {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }

    bool check() const override 
    {
        return (sides_count == 4) && (A + B + C + D == 360);
    }
};

class Rectanglee : public Quadrilateral 
{
public:
    Rectanglee(double a, double b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) 
    {
        name = "Прямоугольник";
    }

    bool check() const override 
    {
        return Quadrilateral::check() && (a == c && b == d) && (A == 90 && B == 90 && C == 90 && D == 90);
    }
};

class Square : public Quadrilateral 
{
public:
    Square(double a) : Quadrilateral(a, a, a, a, 90, 90, 90, 90) 
    {
        name = "Квадрат";
    }

    bool check() const override 
    {
        return Quadrilateral::check() && (a == b && b == c && c == d) && (A == 90 && B == 90 && C == 90 && D == 90);
    }
};

class Parallelogram : public Quadrilateral 
{
public:
    Parallelogram(double a, double b, double A, double B) : Quadrilateral(a, b, a, b, A, B, A, B) 
    {
        name = "Параллелограмм";
    }

    bool check() const override 
    {
        return Quadrilateral::check() && (a == c && b == d) && (A == C && B == D);
    }
};

class Rhombus : public Quadrilateral 
{
public:
    Rhombus(double a, double A, double B) : Quadrilateral(a, a, a, a, A, B, A, B) 
    {
        name = "Ромб";
    }

    bool check() const override 
    {
        return Quadrilateral::check() && (a == b && b == c && c == d) && (A == C && B == D);
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure figure;
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(3, 4, 5, 30, 60);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(10);

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectanglee rectangle(10, 20);
    Square square(10);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(10, 30, 40);

    Figure* figures[] = 
    {
        &figure,
        &triangle,
        &right_triangle,
        &isosceles_triangle,
        &equilateral_triangle,
        &quadrilateral,
        &rectangle,
        &square,
        &parallelogram,
        &rhombus
    };

    for (Figure* fig : figures) 
    {
        fig->print_info();
    }

    return EXIT_SUCCESS;
}