#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class Road {
private:
    std::size_t length; // Длина дороги в метрах
    std::size_t lanes; // Количество полос на дороге

public:
    Road() : length(0), lanes(0) {}

    // Метод для чтения данных из файла
    void readDataFromFile(const std::string& fileName) {
        std::ifstream inputFile(fileName);
        if (!inputFile.is_open()) {
            throw std::runtime_error("Файл не существует или не удалось открыть: " + fileName);
        }

        if (!(inputFile >> length >> lanes)) {
            throw std::runtime_error("Ошибка чтения данных из файла: " + fileName);
        }
    }

    // Метод для вывода значений полей
    void printValues() const {
        std::cout << "Длина дороги: " << length << " метров" << std::endl;
        std::cout << "Количество полос: " << lanes << std::endl;
    }
};

int main() {
    Road road;

    try {
        // Чтение данных из файла
        road.readDataFromFile("input.txt");

        // Вывод значений полей
        road.printValues();
    } catch(const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
