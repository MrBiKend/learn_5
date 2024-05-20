#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class Road {
private:
    std::size_t length; // Длина дороги в метрах
    std::size_t lanes; // Количество полос на дороге

public:
    // Конструктор с параметрами
    Road(std::size_t length, std::size_t lanes) : length(length), lanes(lanes) {}

    // Конструктор по умолчанию
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

    // Методы для получения значений длины и количества полос на дороге
    std::size_t getLength() const {
        return length;
    }

    std::size_t getLanes() const {
        return lanes;
    }

    // Метод для проверки, является ли дорога шоссе
    bool isHighway() const {
        return lanes > 2;
    }
};

int main() {
    try {
        // Создание объекта Road с заданными значениями
        Road road(1000, 2);

        // Вывод значений полей
        road.printValues();

        // Проверка, является ли дорога шоссе
        if (road.isHighway()) {
            std::cout << "Дорога является шоссе." << std::endl;
        } else {
            std::cout << "Дорога не является шоссе." << std::endl;
        }

        // Запись данных в файл
        road.writeDataToFile("output.txt");
        std::cout << "Данные успешно записаны в файл 'output.txt'." << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
