#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

struct Bank
{
    int number;
    std::string name;
    int balance;
};

void changeBalance(Bank& account, int newBalance)
{
    account.balance = newBalance;
    std::cout << "Баланс успешно изменён на: " << newBalance << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Bank person;
    std::cout << "Введите номер счета" << std::endl;
    std::cin >> person.number;
    std::cout << "Введите имя" << std::endl;
    std::cin >> person.name;
    std::cout << "Введите баланс" << std::endl;
    std::cin >> person.balance;

    std::cout << "Текущие данные счёта:" << std::endl;
    std::cout << "Имя: " << person.name << std::endl;
    std::cout << "Номер счёта: " << person.number << std::endl;
    std::cout << "Баланс: " << person.balance << std::endl;

    int newBalance;
    std::cout << "Введите новый баланс: ";
    std::cin >> newBalance;

    changeBalance(person, newBalance);

    std::cout << "Ваш счет: " << person.name << " , " << person.number << " , " << person.balance << std::endl;

    return EXIT_SUCCESS;
}