#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class Road {
private:
  int length;
  int lanes;

public:
  Road() : length(0), lanes(0) {}

  void readDataFromFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
      throw std::runtime_error("Не удалось открыть файл: " + fileName);
    }
    if (!(inputFile >> length >> lanes) || length <= 0 || lanes <= 0) {
      throw std::runtime_error("Некорректные данные в файле: " + fileName);
    }
    inputFile.close();
  }

  void printValues() {
    std::cout << "Длина дороги: " << length << " метров\n";
    std::cout << "Количество полос: " << lanes << '\n';
  }
};

int main() {
  Road road;

  try {
    road.readDataFromFile("input.txt");
    road.printValues();
  } catch(const std::exception& e) {
    std::cerr << "Ошибка: " << e.what() << '\n';
    return 1;
  }

  return 0;
}
