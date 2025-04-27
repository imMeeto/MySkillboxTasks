#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
std::map<std::string, std::string> phoneToName; 
std::map<std::string, std::vector<std::string>> nameToPhones;

std::cout << "*** Phone Directory. ***\n\n";
std::cout << "Input the query in the following formats:\n";
std::cout << "1) 69-70-30 Ivanov (add the subscriber's phone number and last name to the directory)\n";
std::cout << "2) 69-70-30 (find out the subscriber's last name by phone number)\n";
std::cout << "3) Ivanov (find out the subscriber's phone number by last name)\n\n";

std::string query;
while (std::getline(std::cin, query))
{
  if (query.empty()) continue;

  size_t spacePos = query.find(' ');
  
  if (spacePos != std::string::npos)
  {
    //добавление (69-70-30 Ivanov)
    std::string phone = query.substr(0, spacePos);
    std::string name = query.substr(spacePos + 1);
    
    std::cout << "Entry added!\n";
    phoneToName[phone] = name;
    nameToPhones[name].push_back(phone);
  }
  else
  {
    if (query.find('-') != std::string::npos)
    {
      //поиск по телефону
      std::map<std::string, std::string>::iterator it = phoneToName.find(query);
      if (it != phoneToName.end())
      {
        std::cout << "Name: ";
        std::cout << it->second << std::endl;
      }
    }
    else
    {
      //поиск по фамилии
      std::map<std::string, std::vector<std::string>>::iterator it = nameToPhones.find(query);
      if (it != nameToPhones.end())
      {
        for (size_t i = 0; i < it->second.size(); ++i)
        {
          if (i != 0) std::cout << " ";
          std::cout << "Phone: ";
          std::cout << it->second[i];
        }
        std::cout << std::endl;
      }
    }
  }
}

return 0;
}