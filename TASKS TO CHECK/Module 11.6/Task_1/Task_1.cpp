#include <iostream>

std::string encrypt_caesar(std::string text, int code) {
  code = code % 26;
  std::string result = "";

  for (char c : text) {
    if ('A'<= c && c <= 'Z') {
      char new_char = (c - 'A' + code) % 26 + 'A'; // Сдвиг символа по коду, %26 для зацикливания, +A для преобразования обратно в символ
      result += new_char;
    } else if ('a' <= c && c <= 'z') {
      char new_char = (c - 'a' + code) % 26 + 'a';
      result += new_char;
    } else {
      result += c;
    }
  }
  return result;
}

int main() {
  std::cout << "*A text encryption program for Julius Caesar.*\n";

  std::string textMain;
  int codeMain;

  std::cout << "Text: ";
  std::getline(std::cin, textMain);
  std::cout << "Code: ";
  std::cin >> codeMain;

  std::cout << "Result: " << encrypt_caesar(textMain, codeMain) << "\n";
  
  return 0;
}