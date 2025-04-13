#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

const int SECTORS_COUNT = 13;
const int WIN_SCORE = 6;

struct Sector
{
  int sectorNumber;
  bool isSectorPlayed; 
  std::string question;
  std::string answer;
};

std::vector<std::string> readAllLines(const std::string& fileName)
{
  std::vector<std::string> lines;
  std::ifstream file(fileName);
  if (!file.is_open())
  {
      std::cout << "Error opening file: " << fileName << std::endl;
      exit(1);
  }
  
  std::string line;
  while (std::getline(file, line))
  {
      lines.push_back(line);
  }
  file.close();
  
  return lines;
}

int main()
{

    std::cout << "To get started: \n";
    std::string questionsPath, answersPath;
  
    std::cout << "1) Input the full path to the question file: \n";
    std::getline(std::cin, questionsPath);
    
    std::cout << "2) Input the full path to the answers file: \n";
    std::getline(std::cin, answersPath);

  std::vector<std::string> allQuestions = readAllLines(questionsPath);
  std::vector<std::string> allAnswers = readAllLines(answersPath);
  
  if (allQuestions.size() < SECTORS_COUNT || allAnswers.size() < SECTORS_COUNT)
  {
      std::cout << "Files must contain at least " << SECTORS_COUNT 
                << " questions and answers" << std::endl;
      return 1;
  }

  std::vector<Sector> sectors;
  for (int i = 0; i < SECTORS_COUNT; ++i)
  {
      sectors.push_back(
        {
          i + 1,
          false,
          allQuestions[i],
          allAnswers[i]
        });
  }

  int currentSectorIndex = 0;
  int playerScore = 0;
  int viewersScore = 0;

  std::cout << "\n***Welcome to 'What? Where? When?' game!***" << std::endl;
  std::cout << "You need " << WIN_SCORE << " points to win." << std::endl << std::endl;

  while (playerScore < WIN_SCORE && viewersScore < WIN_SCORE)
  {
      int offset;
      std::cout << "Current sector: " << sectors[currentSectorIndex].sectorNumber << std::endl;
      std::cout << "Input spin offset: ";
      std::cin >> offset;

      currentSectorIndex = (currentSectorIndex + offset) % SECTORS_COUNT;
      if (currentSectorIndex < 0) currentSectorIndex += SECTORS_COUNT;

      int attempts = 0;
      while (sectors[currentSectorIndex].isSectorPlayed && attempts < SECTORS_COUNT)
      {
          currentSectorIndex = (currentSectorIndex + 1) % SECTORS_COUNT;
          attempts++;
      }

      if (attempts == SECTORS_COUNT)
      {
          std::cout << "All sectors have been played. Game over." << std::endl;
          break;
      }

      Sector& currentSector = sectors[currentSectorIndex];
      currentSector.isSectorPlayed = true;

      std::cout << "\n- Sector " << currentSector.sectorNumber << ". A question: " << std::endl;
      std::cout << currentSector.question << std::endl;

      std::string playerAnswer;
      std::cout << "\nYour answer: ";
      std::cin.ignore();
      std::getline(std::cin, playerAnswer);

      std::transform(playerAnswer.begin(), playerAnswer.end(), playerAnswer.begin(), ::tolower);
      std::string correctAnswerLower = currentSector.answer;
      std::transform(correctAnswerLower.begin(), correctAnswerLower.end(), correctAnswerLower.begin(), ::tolower);

      if (playerAnswer == correctAnswerLower)
      {
          playerScore++;
          std::cout << "Correct! Your score: " << playerScore 
                    << " (Viewers: " << viewersScore << ")" << std::endl;
      }
      else
      {
          viewersScore++;
          std::cout << "Incorrect. The right answer: " << currentSector.answer << std::endl;
          std::cout << "Score: You - " << playerScore << ", Viewers - " << viewersScore << std::endl;
      }

      std::cout << "----------------------------------------" << std::endl;
  }

  if (playerScore >= WIN_SCORE)
  {
      std::cout << "\nCongratulations! You won with score " 
                << playerScore << ":" << viewersScore << "!" << std::endl;
  }
  else if (viewersScore >= WIN_SCORE)
  {
      std::cout << "\nUnfortunately, you've lost! Viewers won with score " 
                << viewersScore << ":" << playerScore << "." << std::endl;
  }
  else
  {
      std::cout << "\nGame ended early. Final score: You - " 
                << playerScore << ", Viewers - " << viewersScore << std::endl;
  }

  return 0;
}