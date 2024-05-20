# 🛣️ RoadApp 🚗

Простое приложение для работы с данными о дорогах.

## 📝 Описание
![Логотип](logo.png)
Это небольшое приложение позволяет читать данные о дорогах из файла, а затем выводить информацию о них, рассчитывать примерное время проезда по дороге и предлагать развлечения в пути.

## 🚀 Запуск

1. Убедитесь, что у вас установлен компилятор C++.
2. Клонируйте репозиторий: `git clone https://github.com/your_username/RoadApp.git`
3. Перейдите в каталог проекта: `cd RoadApp`
4. Скомпилируйте приложение: `g++ -std=c++11 -o RoadApp main.cpp`
5. Запустите приложение: `./RoadApp`

## 🛠️ Пример использования

```cpp
#include "Road.h"
#include <iostream>

int main() {
    RoadApp::Road road;
    road.readDataFromFile("input.txt");
    road.printValues();
    double averageSpeed = 60; // Средняя скорость в км/ч
    double travelTime = road.calculateTravelTime(averageSpeed);
    std::cout << "Примерное время проезда по дороге: " << travelTime << " часа\n";
    road.suggestEntertainment();
    road.writeDataToFile("output.txt");
    return 0;
}
```

## 🤝 Вклад

Мы рады вашим идеям и предложениям! Не стесняйтесь создавать pull request'ы.
