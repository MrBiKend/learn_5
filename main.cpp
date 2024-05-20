#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept> // Для исключений

// Класс дороги
class Road {
private:
  int length; // Длина дороги в метрах
  int lanes; // Количество полос на дороге

public:
  // Конструктор без параметров
  Road() : length(0), lanes(0) {}

  // Метод для чтения данных из файла
  void readDataFromFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
      if (!(inputFile >> length >> lanes)) {
        throw std::runtime_error("Ошибка чтения данных из файла.");
      }
      inputFile.close();
    } else {
      throw std::runtime_error("Не удалось открыть файл: " + fileName);
    }
  }

  // Метод для вывода значений полей
  void printValues() {
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
