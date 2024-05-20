#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <ctime>
#include <cstdlib>

class Road {
private:
    std::size_t length = 0; // Длина дороги в метрах
    std::size_t lanes = 0; // Количество полос на дороге
    int quality = 0; // Качество дороги (от 1 до 10)

public:
    // Конструктор по умолчанию
    Road() = default;

    // Конструктор с параметрами (с использованием списков инициализации)
    Road(std::size_t length, std::size_t lanes, int quality) : length(length), lanes(lanes), quality(quality) {}

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
        if (lanes == 0) {
            throw std::logic_error("Дорога без полос не имеет времени проезда.");
        }
        double timeInSeconds = length / (averageSpeed * lanes);
        return timeInSeconds / 3600; // Переводим в часы
    }

    // Метод для шуток о качестве дороги
    void jokeAboutRoadQuality() const {
        if (quality >= 8) {
            std::cout << "Качество этой дороги так высоко, что даже у машин начинают расти крылья!\n";
        } else if (quality >= 6) {
            std::cout << "На этой дороге иногда можно увидеть зайцев, которые обгоняют автомобили!\n";
        } else {
            std::cout << "Дорога так плоха, что здесь даже улитки предпочитают пользоваться автобусом!\n";
        }
    }

    // Метод для вывода случайного анекдота о дороге
    void tellRoadJoke() const {
        std::vector<std::string> jokes = {
            "Знаете, почему на дорогах много дыр? Потому что инженеры следуют принципу 'от дурака - на дурака'!",
            "На дороге стоит знак 'Осторожно, дорожные работы'. Чтобы не потеряться, наверное, стоит взять с собой навигатор!",
            "Дорожные знаки вроде 'Проезд запрещен' - это всего лишь рекомендации для настоящих героев дорог!",
            "Почему иногда на дорогах стоят знаки 'Опасный поворот'? Чтобы водители не заснули от скуки!",
            "Если дорога вас напугала, просто представьте, что это аттракцион на выживание!"
        };

        srand(time(0)); // Инициализируем генератор случайных чисел
        int index = rand() % jokes.size(); // Получаем случайный индекс
        std::cout << "Анекдот о дороге: " << jokes[index] << std::endl;
    }
};

int main() {
    try {
        Road road;

        // Чтитение данных из файла
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

    // Шутки о качестве дороги
    road.jokeAboutRoadQuality();

    // Случайный анекдот о дороге
    road.tellRoadJoke();

    // Запись данных в файл
    road.writeDataToFile("output.txt");
    std::cout << "Данные успешно записаны в файл 'output.txt'.\n";
} catch(const std::exception& e) {
    std::cerr << "Ошибка: " << e.what() << "\n";
    return 1;
}

return 0;

