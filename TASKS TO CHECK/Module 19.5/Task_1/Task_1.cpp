#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream Words;
    Words.open("C:\\VS Code\\VS Code Projects\\MySkillboxTasks\\TASKS TO CHECK\\Module 19.5\\Task_1\\Words.txt");

    if (!Words.is_open())
    {
      std::cout << "Error: file 'words.txt' not found!" << "\n";
        return 1;
    }

    std::string targetWord;
    std::cout << "Input the search word: ";
    std::cin >> targetWord;

    int count = 0;
    std::string word;

    while (Words >> word)
    {
        if (word == targetWord)
        {
            count++;
        }
    }

    Words.close();

    std::cout << "Word '" << targetWord << "' occurs " << count << " times.\n";

    return 0;
}