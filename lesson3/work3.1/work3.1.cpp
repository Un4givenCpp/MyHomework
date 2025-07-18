#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>


struct Address 
{
    std::string city;
    std::string street;
    int house;
    int apartment;
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream inFile("in.txt");
    if (!inFile.is_open()) 
    {
        std::cerr << "Не удалось открыть файл in.txt" << std::endl;
        return 1;
    }

    int N;
    inFile >> N;
    inFile.ignore();

    Address* addresses = new Address[N];

    for (int i = 0; i < N; ++i) 
    {
        std::getline(inFile, addresses[i].city);
        std::getline(inFile, addresses[i].street);
        inFile >> addresses[i].house;
        inFile.ignore(); 
        inFile >> addresses[i].apartment;
        inFile.ignore();
    }
    inFile.close();

    std::ofstream outFile("out.txt");
    if (!outFile.is_open())
    {
        std::cerr << "Не удалось создать файл out.txt" << std::endl;
        delete[] addresses;
        return 1;
    }

    outFile << N << std::endl;

    for (int i = N - 1; i >= 0; --i) 
    {
        outFile << addresses[i].city << ", "
            << addresses[i].street << ", "
            << addresses[i].house << ", "
            << addresses[i].apartment << std::endl;
    }

    delete[] addresses;
    outFile.close();

    std::cout << "Адреса успешно записаны в файл out.txt" << std::endl;
    return EXIT_SUCCESS;
}