#include <iostream>

int main () {
  std::cout << "Прогресс загрузки файла.\n";

  float fileSize = 0.0f, internetSpeed = 0.0f, downloaded = 0.0f;
  int percentages = 0;

  std::cout << "Укажите размер файла для скачивания (мб): ";
  std::cin >> fileSize;
  std::cout << "Укажите скорость интернет-соединения (мб/сек): ";
  std::cin >> internetSpeed;
  std::cout << "Загрузка файла...\n";

  if (fileSize <= 0 || internetSpeed <= 0) {
    std::cout << "Размер файла и скорость соединения должны быть положительными!\n";
    return 1;
  }
  
  for (int secondsCount = 1; fileSize >= downloaded; secondsCount++) {
    downloaded += internetSpeed;
    percentages = static_cast<int>(downloaded / fileSize * 100); // Вычисляем процент

    if (downloaded < fileSize) {
      std::cout << "Прошло " << secondsCount << " сек. Скачано " << downloaded << " из " << fileSize << " МБ (" << percentages << "%).\n";
    }

    if (downloaded >= fileSize) {
      downloaded = fileSize;
      std::cout << "Прошло " << secondsCount << " сек. Скачано " << downloaded << " из " << fileSize << " МБ (100%).\n";
      std::cout << "Загрузка файла завершена.\n";
      break;
    }
    
  }
  
  return 0;
}