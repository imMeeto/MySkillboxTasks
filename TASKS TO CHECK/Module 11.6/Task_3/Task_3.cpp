#include <iostream>
#include <string>

// Функция для проверки корректности одного октета
bool isValidOctet(std::string octet) {
  if (octet.empty() || octet.size() > 3) return false;

  for (int i = 0; i < octet.size(); i++) {
    if (!isdigit(octet[i])) return false; // Проверяем, что все символы цифры
  }

  int num = 0;
  for (int i = 0; i < octet.size(); i++) { 
    num = num * 10 + (octet[i] - '0'); // Преобразуем строку в число
  }
  
  if (num < 0 || num > 255) return false;
  
  if (octet.size() > 1 && octet[0] == '0') return false;

  return true;
}

// Функция для проверки всего IP-адреса
bool isValidIP(std::string ip) {
  int octetCount = 0;
  int startOctet = 0;

  // Добавляем точку чтобы обработать последний октет даже если строка заканчивается без дополнительной точки
  for (int i = 0; i <= ip.size(); i++) {
    char c = (i < ip.size()) ? ip[i] : '.';

    if (c == '.') {
      std::string octet = ip.substr(startOctet, i - startOctet);
      if (!isValidOctet(octet)) return false;
      octetCount++;
      startOctet = i + 1;
    } else if (!isdigit(c)) {
      return false;
    }
  }

  return octetCount == 4;
}

int main() {
  std::cout << "*Check that the IP-address is valid.*\n";
  std::string inputIP;
  std::cout << "Input IP-address: ";
  std::cin >> inputIP;

  if(isValidIP(inputIP)) {
    std::cout << "IP-address is valid!\n";
  } else {
    std::cout << "IP-address is not valid!\n";
  }

  return 0;
}