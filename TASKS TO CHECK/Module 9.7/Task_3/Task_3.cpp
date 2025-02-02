#include <iostream> 

int main() {
  std::cout << "A program-counter the number of words in a text.\n";

  std::string str;
  int wordsCount = 0;
  bool inWord = false;

  std::cout << "Input words: ";
  std::getline(std::cin, str);

  for (char ch : str) { // Перебор каждого символа в строке
    if (ch != ' ') { 
      if (!inWord) { // Если мы не находимся внутри слова
        ++wordsCount; // Увеличиваем счетчик слов
        inWord = true; // Мы внутри слова
      }
    } else {
      inWord = false; // Если пробел мы не внутри слова
    }
  }

  std::cout << "Answer: " << wordsCount << "\n";

  return 0;
}
