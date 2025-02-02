#include <iostream>

int main() {
  std::cout << "A program-counter the number of words in a text.\n";

  std::string str;
  int wordsCount = 0;
  bool inWord = false;

  std::cout << "Input words: ";
  std::getline(std::cin, str);

  for (char ch : str) {
    if (ch != ' ') {
      if (!inWord) {
        ++wordsCount;
        inWord = true;
      }
    } else {
      inWord = false;
    }
  }

  std::cout << "Ответ: " << wordsCount << "\n";
  

  return 0;
}