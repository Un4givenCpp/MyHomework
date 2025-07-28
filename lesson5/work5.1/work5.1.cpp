#include <iostream>
#include "Calculator.h"
#include <windows.h>


int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double num1;
    int num2;
    int operation;

    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите второе число (для степени - целое число): ";
    std::cin >> num2;

    std::cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> operation;

    double result;
    bool error = false;

    switch (operation) 
    {
    case 1:
        result = Calculator::add(num1, num2);
        std::cout << num1 << " + " << num2 << " = " << result << std::endl;
        break;
    case 2:
        result = Calculator::subtract(num1, num2);
        std::cout << num1 << " - " << num2 << " = " << result << std::endl;
        break;
    case 3:
        result = Calculator::multiply(num1, num2);
        std::cout << num1 << " * " << num2 << " = " << result << std::endl;
        break;
    case 4:
        if (num2 == 0) 
        {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            error = true;
        }

        else {
            result = Calculator::divide(num1, num2);
            std::cout << num1 << " / " << num2 << " = " << result << std::endl;
        }
        break;
    case 5:
        result = Calculator::power(num1, num2);
        std::cout << num1 << " в степени " << num2 << " = " << result << std::endl;
        break;
    default:
        std::cout << "Неверный выбор операции!" << std::endl;
        return 1;
    }

    if (error) 
    {
        return 1;
    }

    return EXIT_SUCCESS;
}