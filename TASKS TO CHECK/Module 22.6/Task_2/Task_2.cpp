#include <iostream>
#include <map>
#include <string>

void displayQueue(const std::map<std::string, int>& queue)
{
  std::cout << "______________________\n\n";
  std::cout << "Current queue:\n";

  if (queue.empty())
  {
    std::cout << "The queue is empty.\n";
  }
  else
  {
    for (std::map<std::string, int>::const_iterator it = queue.begin(); it != queue.end(); ++it)
    {
    std::cout << "- " << it->first << ": " << it->second << " human.\n";
    }
  }

  std::cout << "______________________\n\n";
}

int main()
{
  std::cout << "* The queue at the reception ***\n\n";
  std::cout << "Use next commands:\n";
  std::cout << "- Last name (add patient)\n";
  std::cout << "- Next (call the next patient)\n";
  std::cout << "- Exit (to escape)\n";

  std::map<std::string, int> queue;
  std::string input;

  while (true)
  {
    displayQueue(queue);

    std::cout << "Input the command: ";
    std::cin >> input;

    if (input == "Exit" || input == "exit")
    {
      break;
    }
    else if (input == "Next" || input == "next")
    {
      if (!queue.empty())
      {
        std::map<std::string, int>::iterator nextPatient = queue.begin();
        std::cout << "The patient is called: " << nextPatient->first << "\n";
        
        if (nextPatient->second > 1)
        {
          nextPatient->second--;
        } 
        else
        {
          queue.erase(nextPatient);
        }
      }
    }
    else
    {
      queue[input]++;
      std::cout << "\nA patient has been added: " << input << "\n";
    }
  }

  std::cout << "The system has been completed.\n";
  return 0;
}