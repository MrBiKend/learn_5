#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <random>

namespace RoadApp {

    class Road {
    private:
        std::size_t length = 0; // Длина дороги в метрах
        std::size_t lanes = 0; // Количество полос на дороге
        std::size_t quality = 0; // Качество дороги (от 1 до 10)

    public:
        // Конструктор по умолчанию
        Road() = default;

        // Конструктор с параметрами (с использованием списков инициализации)
        Road(std::size_t length, std::size_t lanes, std::size_t quality) : length(length), lanes(lanes), quality(quality) {
            if (length == 0 || lanes == 0 || quality < 1 || quality > 10) {
                throw std::invalid_argument("Некорректные параметры дороги.");
            }
        }

        // Метод для чтения данных из файла
        void readDataFromFile(const std::string& fileName) {
            std::ifstream inputFile(fileName);
            if (!inputFile.is_open()) {
                throw std::runtime_error("Не удалось открыть файл: " + fileName);
            }

            inputFile >> length >> lanes >> quality;
            if (inputFile.fail()) {
                throw std::runtime_error("Ошибка чтения данных из файла: " + fileName);
            }
        }

        // Метод для записи данных в файл
        void writeDataToFile(const std::string& fileName) const {
            std::ofstream outputFile(fileName);
            if (!outputFile.is_open()) {
                throw std::runtime_error("Не удалось открыть файл: " + fileName);
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

        // Метод для определения, является ли дорога хорошей
        bool isGoodRoad() const {
            return quality >= 7;
        }

        // Метод для расчета примерного времени проезда по дороге
        double calculateTravelTime(double averageSpeed) const {
            if (lanes == 0 || averageSpeed == 0) {
                throw std::logic_error("Дорога без полос или нулевая средняя скорость не имеют времени проезда.");
            }
            double timeInSeconds = length / (averageSpeed * lanes);
            return timeInSeconds / 3600; // Переводим в часы
        }

        // Метод для предложения развлечений в пути
        void suggestEntertainment() const {
            std::vector<std::string> entertainmentOptions = {
                "Послушать аудиокнигу",
                "Включить любимый плейлист с музыкой",
                "Прослушать интересный подкаст",
                "Поиграть в автомобильные игры (например, 'Я-спрашиваю-ты-отвечаешь')"
            };

            std::cout << "Предлагаемые развлечения в пути:\n";
            for (const std::string& option : entertainmentOptions) {
                std::cout << "- " << option << "\n";
            }
        }
    };

    int main() {
        try {
            Road road;

            // Чтение данных из файла
            road.readDataFromFile("input.txt");

            // Вывод данных на экран
            road.printValues();

            // Проверка, является ли дорога хорошей
            if (road.isGoodRoad()) {
                std::cout << "Это хорошая дорога!\n";
            } else {
                std::cout << "Это плохая дорога.\n";
            }

            // Расчет времени проезда по дороге
            double averageSpeed = 60; // Средняя скорость в км/ч
            double travelTime = road.calculateTravelTime(averageSpeed);
            std::cout << "Примерное время проезда по дороге: " << travelTime << " часа\n";

            // Предложение развлечений в пути
            road.suggestEntertainment();

            // Запись данных в файл
            road.writeDataToFile("output.txt");
            std::cout << "Данные успешно записаны в файл 'output.txt'.\n";
        } catch(const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << "\n";
            return 1;
        }

        return 0;
    }

} // namespace RoadApp

int main() {
    return RoadApp::main();
}

