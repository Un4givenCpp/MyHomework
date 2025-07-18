#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

enum months
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int i;
    while (1 == 1)
    {
        {
            std::cout << "Введите номер месяца: ";
            std::cin >> i;

            if (i == 0)
            {
                std::cout << "До свидания" << std::endl;
                break;
            }


            months month = static_cast<months>(i);
            switch (month)
            {
            case January: std::cout << "Январь" << std::endl; break;
            case February: std::cout << "Февраль" << std::endl; break;
            case March: std::cout << "Март" << std::endl; break;
            case April: std::cout << "Апрель" << std::endl; break;
            case May: std::cout << "Май" << std::endl; break;
            case June: std::cout << "Июнь" << std::endl; break;
            case July: std::cout << "Июль" << std::endl; break;
            case August: std::cout << "Август" << std::endl; break;
            case September: std::cout << "Сентябрь" << std::endl; break;
            case October: std::cout << "Октябрь" << std::endl; break;
            case November: std::cout << "Ноябрь" << std::endl; break;
            case December: std::cout << "Декабрь" << std::endl; break;
            default: std::cout << "Неправильный номер!" << std::endl; break;
            }
        }
    }

    return EXIT_SUCCESS;
}