#include <iostream>
#include <limits>

int main () {
    std::cout << "Прогресс загрузки файла.\n";

    float fileSize = 0.0f, internetSpeed = 0.0f, downloaded = 0.0f;
    int percentages = 0;

    while (true) {
        std::cout << "Укажите размер файла для скачивания (мб): ";
        std::cin >> fileSize;
        if (std::cin.fail() || fileSize <= 0) {
            std::cin.clear(); // Очистка флага ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорирование некорректного ввода
            std::cout << "Пожалуйста, введите положительное число.\n";
            continue;
        }
        break;
    }

    while (true) {
        std::cout << "Укажите скорость интернет-соединения (мб/сек): ";
        std::cin >> internetSpeed;
        if (std::cin.fail() || internetSpeed <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Пожалуйста, введите положительное число.\n";
            continue;
        }
        break;
    }

    std::cout << "Загрузка файла...\n";

    for (int secondsCount = 1; downloaded < fileSize; secondsCount++) {
        downloaded += internetSpeed;
        percentages = static_cast<int>(downloaded / fileSize * 100); // Вычисляем процент

        if (downloaded < fileSize) {
            std::cout << "Прошло " << secondsCount << " сек. Скачано " << downloaded << " из " << fileSize << " МБ (" << percentages << "%).\n";
        }
    }

    downloaded = fileSize; // Устанавливаем загруженное значение в размер файла
    std::cout << "Прошло " << (static_cast<int>(downloaded / internetSpeed) + 1) << " сек. Скачано " << downloaded << " из " << fileSize << " МБ (100%).\n";
    std::cout << "Загрузка файла завершена.\n";

    return 0;
}