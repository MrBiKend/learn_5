#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class Road {
private:
    std::size_t length = 0; // Длина дороги в метрах
    std::size_t lanes = 0; // Количество полос на дороге
    int quality = 0; // Качество дороги (от 1 до 10)

public:
    // Конструктор с параметрами
    Road(std::size_t length, std::size_t lanes, int quality) : length(length), lanes(lanes), quality(quality) {}

    // Конструктор по умолчанию
    Road() = default;

    // Метод для чтения данных из файла
    void readDataFromFile(const std::string& fileName) {
        std::ifstream inputFile(fileName);
        if (!inputFile.is_open()) {
            throw std::runtime_error("Файл не существует или не удалось открыть: " + fileName);
        }

        if (!(inputFile >> length >> lanes >> quality)) {
            throw std::runtime_error("Ошибка чтения данных из файла: " + fileName);
        }
    }

    // Метод для записи данных в файл
    void writeDataToFile(const std::string& fileName) const {
        std::ofstream outputFile(fileName);
        if (!outputFile.is_open()) {
            throw std::runtime_error("Не удалось открыть файл для записи: " + fileName);
        }

        outputFile << "Длина дороги: " << length << " метров\n"
                   << "Количество полос: " << lanes << "\n"
                   << "Качество дороги: " << quality << "\n";
    }

    // Метод для вывода значений полей
    void printValues() const {
        std::cout << "Длина дороги: " << length << " метров\n"
                  << "Количество полос: " << lanes << "\n"
                  << "Качество дороги: " << quality << "\n";
    }

    // Метод для обновления данных о дороге
    void updateData(std::size_t newLength, std::size_t newLanes, int newQuality) {
        length = newLength;
        lanes = newLanes;
        quality = newQuality;
    }

    // Методы для получения значений длины, количества полос и качества дороги
    std::size_t getLength() const { return length; }
    std::size_t getLanes() const { return lanes; }
    int getQuality() const { return quality; }
};

int main() {
    try {
        // Создание объекта Road с заданными значениями
        Road road(1000, 2, 8);

        // Вывод значений полей
        road.printValues();

        // Запись данных в файл
        road.writeDataToFile("output.txt");
        std::cout << "Данные успешно записаны в файл 'output.txt'.\n";
    } catch(const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
