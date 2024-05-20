

```markdown
# RoadApp

Простое приложение для работы с данными о дорогах.

## Описание

Это небольшое приложение позволяет читать данные о дорогах из файла, а затем выводить информацию о них, рассчитывать примерное время проезда по дороге и предлагать развлечения в пути. 

## Зависимости

- C++11 или выше

## Установка

Для использования этого приложения необходимо скомпилировать его с помощью компилятора C++.

## Использование

1. Создайте файл `input.txt` с данными о дороге в формате:
   ```
   <длина_дороги_в_метрах> <количество_полос> <качество_дороги_от_1_до_10>
   ```
2. Запустите приложение.
3. После выполнения программы, данные будут записаны в файл `output.txt`, а также выведены в консоль.

## Пример

```cpp
#include "RoadApp/Road.h"
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

## Вклад

- Автор: [Павел]

Вы можете внести свой вклад в улучшение проекта, создав pull request.
