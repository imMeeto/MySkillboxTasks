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

std::tm parseDate(const std::string& dateStr)
{
  std::tm tm = {};
  std::istringstream ss(dateStr); //поток ввода из строки
  char splitter;

  ss >> tm.tm_year >> splitter >> tm.tm_mon >> splitter >> tm.tm_mday;

  tm.tm_year -= 1900; //потому что tm считает от 1900
  tm.tm_mon -= 1; //потому что tm считает с 0

  return tm;
}

bool compareBirthdays(const Friend& first, const Friend& second)
{
  std::time_t now = std::time(nullptr); //получаем текущее время в секундах
  std::tm* today  = std::localtime(&now); //преобразуем в локальную дату/время

  //для друга First: устанавливаем текущий год
  std::tm firstDate = first.birthday;
  firstDate.tm_year = today->tm_year;
  std::time_t firstTime = std::mktime(&firstDate); //преобразуем обратно в секундный формат

  //для друга Second: устанавливаем текущий год
  std::tm secondDate = second.birthday;
  secondDate.tm_year = today->tm_year;
  std::time_t secondTime = std::mktime(&secondDate);

  //если день рождения уже прошёл, берём следующий год
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