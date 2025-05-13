#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <sstream>

struct Friend
{
  std::string name;
  std::tm birthday;
};

bool parseDate(const std::string& dateStr, std::tm& tm)
{
  std::istringstream ss(dateStr);
  char splitter;
  ss >> tm.tm_year >> splitter >> tm.tm_mon >> splitter >> tm.tm_mday;

  if (ss.fail() || splitter != '/')
      return false;

  tm.tm_year -= 1900;
  tm.tm_mon -= 1;

  return true;
}

bool compareBirthdays(const Friend& first, const Friend& second)
{
  std::time_t now = std::time(nullptr);
  std::tm today = *std::localtime(&now);

  std::tm firstDate = first.birthday;
  firstDate.tm_year = today.tm_year;
  std::time_t firstTime = std::mktime(&firstDate);

  std::tm secondDate = second.birthday;
  secondDate.tm_year = today.tm_year;
  std::time_t secondTime = std::mktime(&secondDate);

  if (firstTime < now)
  {
    firstDate.tm_year++;
    firstTime = std::mktime(&firstDate);
  }

  if (secondTime < now)
  {
    secondDate.tm_year++;
    secondTime = std::mktime(&secondDate);
  }

  return firstTime < secondTime;
}

int main()
{
  std::cout << "*** Birthday reminder programs. ***\n\n";
  std::vector<Friend> friends;
  std::string name, birthdayDate;

  while (true)
  {
    std::cout << "Input friend name or command 'end': ";
    std::getline(std::cin, name);

    if (name.empty() || name == "end" || name == "End") break;

    std::cout << "Input the birthday (year/month/day): ";
    std::getline(std::cin, birthdayDate);

    std::tm tm = {};
    if (!parseDate(birthdayDate, tm))
    {
      std::cout << "Invalid date format. Please try again.\n";
      continue;
    }

    friends.push_back({name, tm});

    std::cout << "------------------------------\n";

    if (friends.size() >= 2)
    {
      std::cout << "Do you want to continue typing or compare the dates you have already inputed?\n";
      std::cout << "Input 'continue' or 'compare': ";
      std::string choice; 
      std::getline(std::cin, choice);
      std::cout << "------------------------------\n";

      if (choice == "continue" || choice == "Continue")
      {
        continue;
      }
      else if (choice == "compare" || choice == "Compare")
      {
        break;
      }
    }
  }

  if (friends.empty())
  {
    std::cout << "Ok! Goodbye!\n";
    return 0;
  }

  std::time_t now = std::time(nullptr);
  std::tm today = *std::localtime(&now);

  std::vector<Friend> todayBirthday;
  for (const auto& f : friends)
  {
    if (f.birthday.tm_mon == today.tm_mon && f.birthday.tm_mday == today.tm_mday)
    {
      todayBirthday.push_back(f);
    }
  }

  if (!todayBirthday.empty())
  {
    std::cout << "- Today is the birthday of: ";
    for (const auto& f : todayBirthday)
    {
      std::cout << f.name << " (" << std::setfill('0') << std::setw(2) << f.birthday.tm_mon + 1 << "/"
                << std::setw(2) << f.birthday.tm_mday << ")\n";
    }
  }

  std::sort(friends.begin(), friends.end(), compareBirthdays);

  Friend nearest = friends[0];
  std::tm nearestDate = nearest.birthday;
  nearestDate.tm_year = today.tm_year;
  std::time_t nearestTime = mktime(&nearestDate);

  if (nearestTime < now)
  {
    nearestDate.tm_year++;
    nearestTime = mktime(&nearestDate);
  }

  std::cout << "- Nearest birthday: ";
  std::cout << nearest.name << " (" << std::setfill('0') << std::setw(2) << nearest.birthday.tm_mon + 1
            << "/" << std::setw(2) << nearest.birthday.tm_mday << ")\n";

  return 0;
}