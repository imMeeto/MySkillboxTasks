#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream Words;
    Words.open("C:\\VS Code\\VS Code Projects\\MySkillboxTasks\\TASKS TO CHECK\\Module 19.5\\Task_1\\Words.txt");

    if (!Words.is_open())
    {
        std::cout << "Error! The word wan not found!\n";
        return 1;
    }
    
    std::cout << "Input the search word: ";
    std::string searchWord;
    std::cin >> searchWord;

    int countWords = 0;
    std::string addWord;

    while (Words >> addWord)
    {
        if (searchWord == addWord)
        {
            countWords++;
        }
    }

    Words.close();
    
    std::cout << "Word " << searchWord << " occurs " << countWords << " times.\n";
}