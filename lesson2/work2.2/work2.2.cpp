#include <iostream>
#include <windows.h>

class Counter {
private:
    int value;

public:

    Counter() : value(1) {}
    Counter(int initialValue) : value(initialValue) {}


    void increment() 
    {
        value++;
    }

    void decrement() 
    {
        value--;
    }

    int getValue() const 
    {
        return value;
    }
};

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char choice;
    int initialValue = 1;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите y или n: ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') 
    {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initialValue;
    }

    Counter counter(initialValue);

    char command;
    while (true) 
    {
        std::cout << "Введите команду (+, -, =, x): ";
        std::cin >> command;

        switch (command) 
        {
        case '+':
            counter.increment();
            break;
        case '-':
            counter.decrement();
            break;
        case '=':
            std::cout << counter.getValue() << std::endl;
            break;
        case 'x':
        case 'X':
            std::cout << "До свидания!" << std::endl;
            return 0;
        default:
            std::cout << "Неизвестная команда!" << std::endl;
        }
    }

    return EXIT_SUCCESS;
}