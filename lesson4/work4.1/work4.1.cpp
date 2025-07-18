#include <iostream>
#include <string>
#include <windows.h>

class Shape 
{
protected:
    int sides_count; 

public:
 
    Shape() : sides_count(0) {}

    Shape(int sides) : sides_count(sides) {}

    int get_sides_count() const 
    {
        return sides_count;
    }


    virtual ~Shape() {}
};

class Triangle : public Shape 
{
public:
 
    Triangle() : Shape(3) {}


    int get_sides_count() const 
    {
        return sides_count;
    }
};

class Quadrilateral : public Shape 
{
public:
 
    Quadrilateral() : Shape(4) {}

      int get_sides_count() const
      {
        return sides_count; 
      }
};

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Shape unknown_shape;
    Triangle triangle;
    Quadrilateral quadrilateral;

    std::cout << "Неизвестная фигура имеет " << unknown_shape.get_sides_count() << " сторон\n";
    std::cout << "Треугольник имеет " << triangle.get_sides_count() << " стороны\n";
    std::cout << "Четырехугольник имеет " << quadrilateral.get_sides_count() << " стороны\n";

    return EXIT_SUCCESS;
}