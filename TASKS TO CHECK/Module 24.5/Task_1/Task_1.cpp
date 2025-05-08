#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>

struct Task
{
  std::string name;
  std::time_t startTime;
  std::time_t endTime;
};

std::vector<Task> completedTask;
Task* currentTask = nullptr;

void beginTask()
{
  if (currentTask != nullptr)
  {
    currentTask->endTime = std::time(nullptr);
    completedTask.push_back(*currentTask);
    delete currentTask;
  }
  
  std::cout << "Input task name: ";
  std::string taskName;
  std::getline(std::cin, taskName);

  currentTask = new Task{taskName, std::time(nullptr), 0};
}

void exitTask()
{
  if (currentTask == nullptr) return;

  currentTask->endTime = std::time(nullptr);
  completedTask.push_back(*currentTask);
  std::cout << "Task " << currentTask->name << " has been completed.\n";
  delete currentTask;
  currentTask = nullptr;
}

void printTime(std::time_t seconds)
{
  int hours = seconds / 3600;
  int minutes = (seconds % 3600) / 60;
  int secs = seconds % 60;
  
  std::cout << std::setfill('0') 
            << std::setw(2) << hours << ":"
            << std::setw(2) << minutes << ":"
            << std::setw(2) << secs;
}

void showStatus()
{
  std::cout << "Completed tasks:\n";
  for (const auto& task : completedTask)
  {
    std::time_t timeDuration = task.endTime - task.startTime;
    std::cout << "- " << task.name << " (";
    printTime(timeDuration); // HH:MM:SS
    std::cout << ")\n";
  }

  if (currentTask != nullptr)
  {
    std::cout << "Current task: " << currentTask->name << " started at " 
              << std::ctime(&currentTask->startTime);
  }
  else
  {
    std::cout << "No active task.\n";
  }
}

int main()
{
  std::cout << "*** Time tracking program. ***\n";

  std::string input;

  while (true)
  {
    std::cout << "------------------------------\n";

    std::cout << "Input command (begin/end/status/exit): ";
    std::getline(std::cin, input);

    std::cout << "------------------------------\n";

    if (input == "begin")
    {
      beginTask();
    } 
    else if (input == "end")
    {
      exitTask();
    } 
    else if (input == "status")
    {
      showStatus();
    } 
    else if (input == "exit")
    {
      if (currentTask != nullptr)
      {
        exitTask();
      }
      break;
    }
    else
    {
      std::cout << "Error! Unknown command!\n";
    }
  }

  return 0;
}