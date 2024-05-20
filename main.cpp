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

    // Метод для записи данных в файл
    void writeDataToFile(const std::string& fileName) const {
        std::ofstream outputFile(fileName);
        if (!outputFile.is_open()) {
            throw std::runtime_error("Не удалось открыть файл для записи: " + fileName);
        }

        outputFile << "Длина дороги: " << length << " метров\n";
        outputFile << "Количество полос: " << lanes << "\n";
    }

    // Метод для вывода значений полей
    void printValues() const {
        std::cout << "Длина дороги: " << length << " метров" << std::endl;
        std::cout << "Количество полос: " << lanes << std::endl;
    }

    // Метод для обновления данных о дороге
    void updateData(std::size_t newLength, std::size_t newLanes) {
        length = newLength;
        lanes = newLanes;
    }
};

int main() {
    Road road;

    try {
        // Чтение данных из файла
        road.readDataFromFile("input.txt");

        // Вывод значений полей
        road.printValues();

        // Обновление данных о дороге
        std::size_t newLength, newLanes;
        std::cout << "Введите новую длину дороги (в метрах): ";
        std::cin >> newLength;
        std::cout << "Введите новое количество полос: ";
        std::cin >> newLanes;
        road.updateData(newLength, newLanes);

        // Запись обновленных данных в файл
        road.writeDataToFile("output.txt");
        std::cout << "Обновленные данные успешно записаны в файл 'output.txt'." << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
