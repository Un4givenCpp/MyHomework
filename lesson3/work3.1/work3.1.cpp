#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

class Address 
{
private:
    std::string city;
    std::string street;
    int house;
    int apartment;

public:
    
    Address() : house(0), apartment(0) {}

   
    void setCity(const std::string& c) { city = c; }
    void setStreet(const std::string& s) { street = s; }
    void setHouse(int h) { house = h; }
    void setApartment(int a) { apartment = a; }

  
    std::string getCity() const { return city; }
    std::string getStreet() const { return street; }
    int getHouse() const { return house; }
    int getApartment() const { return apartment; }

    std::string getFormattedAddress() const 
    {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    }
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
        std::string city, street;
        int house, apartment;

        std::getline(inFile, city);
        std::getline(inFile, street);
        inFile >> house;
        inFile.ignore();
        inFile >> apartment;
        inFile.ignore();

        addresses[i].setCity(city);
        addresses[i].setStreet(street);
        addresses[i].setHouse(house);
        addresses[i].setApartment(apartment);
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
        outFile << addresses[i].getFormattedAddress() << std::endl;
    }

    delete[] addresses;
    outFile.close();

    std::cout << "Адреса успешно записаны в файл out.txt" << std::endl;
    return EXIT_SUCCESS;
}