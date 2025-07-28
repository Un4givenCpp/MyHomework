#include <iostream>
#include <string>
#include "Counter.h"
#include <windows.h>

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string answer;
    int initialValue = 1;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> answer;

    if (answer == "да") 
    {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initialValue;
    }

    Counter counter(initialValue);
    std::string command;

    while (true) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        if (command == "+") {
            counter.increment();
        }
        else if (command == "-") {
            counter.decrement();
        }
        else if (command == "=") {
            std::cout << counter.getValue() << std::endl;
        }
        else if (command == "x") {
            std::cout << "До свидания!" << std::endl;
            break;
        }
        else {
            std::cout << "Неизвестная команда!" << std::endl;
        }
    }

    return 0;
}