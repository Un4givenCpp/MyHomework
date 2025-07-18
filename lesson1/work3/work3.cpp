#include <iostream>
#include <string>
#include <windows.h>

struct object
{
    std::string town;
    std::string street;
    int house;
    int room;
    int index;
};

void printObject(const object& obj)
{

    std::cout << "Город:" << obj.town << "\n";
    std::cout << "Улица:" << obj.street << "\n";
    std::cout << "Дом:" << obj.house << "\n";
    std::cout << "Квартира:" << obj.room << "\n";
    std::cout << "Индекс:" << obj.index << "\n";

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    object* object_array = new object[10];
    object_array[0].town = " Москва ";
    object_array[0].street = " Арбат ";;
    object_array[0].house = 12;
    object_array[0].room = 8;
    object_array[0].index = 123456;

    object_array[1].town = " Ижевск ";
    object_array[1].street = " Пушкина ";;
    object_array[1].house = 59;
    object_array[1].room = 143;
    object_array[1].index = 953769;

    for (int i = 0; i < 2; i++)
    {
        printObject(object_array[i]);
    }

    return EXIT_SUCCESS;
}