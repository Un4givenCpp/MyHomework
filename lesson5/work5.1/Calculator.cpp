#include "Calculator.h"
#include <iostream>

double Calculator::add(double a, double b)
{
    return a + b;
}

double Calculator::subtract(double a, double b) 
{
    return a - b;
}

double Calculator::multiply(double a, double b) 
{
    return a * b;
}

double Calculator::divide(double a, double b) 
{
    if (b == 0) 
    {
        std::cout << "Ошибка: деление на ноль!" << std::endl;
        return 0;
    }
    return a / b;
}

double Calculator::power(double a, int b) 
{
    if (b == 0) 
    {
        return 1;
    }

    double result = 1;
    bool negative = false;

    if (b < 0) 
    {
        negative = true;
        b = -b;
    }

    for (int i = 0; i < b; ++i) 
    {
        result *= a;
    }

    if (negative) 
    {
        return 1.0 / result;
    }
    else 
    {
        return result;
    }
}