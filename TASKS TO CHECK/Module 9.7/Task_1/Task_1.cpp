#include <iostream>

int main() {
  std::cout << "Travel time calculator program.\n";

  std::string depTime;
  std::string arrTime;
  int totalDepMinutes = 0;
  int totalArrMinutes = 0;

  while (true) {
    std::cout << "Input departure time (HH:MM): ";
    std::cin >> depTime;

    if (depTime.length() != 5 || depTime[2] != ':' 
        || depTime[0] < '0' || depTime[0] > '9'
        || depTime[1] < '0' || depTime[1] > '9'
        || depTime[3] < '0' || depTime[3] > '9'
        || depTime[4] < '0' || depTime[4] > '9') {
      std::cout << "Error! Input correct format!\n";
      continue;
    } else {
      int depHours = (depTime[0] - '0') * 10 + (depTime[1] - '0');
      int depMinutes = (depTime[3] - '0') * 10 + (depTime[4] - '0');

      if (depHours > 23 || depMinutes > 59) {
        std::cout << "Error! Input correct format!\n";
        continue;
      } else {
        totalDepMinutes = 60 * depHours + depMinutes; // Get all departure time in minutes
        break;
      }
    }
  }  

  while (true) {
    std::cout << "Input arrival time (HH:MM): ";
    std::cin >> arrTime;

    if (arrTime.length() != 5 || arrTime[2] != ':' 
        || arrTime[0] < '0' || arrTime[0] > '9'
        || arrTime[1] < '0' || arrTime[1] > '9'
        || arrTime[3] < '0' || arrTime[3] > '9'
        || arrTime[4] < '0' || arrTime[4] > '9') {
      std::cout << "Error! Input correct format!\n";
      continue;
    } else {
      int arrHours = (arrTime[0] - '0') * 10 + (arrTime[1] - '0');
      int arrMinutes = (arrTime[3] - '0') * 10 + (arrTime[4] - '0');

      if (arrHours > 23 || arrMinutes > 59) {
        std::cout << "Error! Input correct format!\n";
        continue;
      } else {
        totalArrMinutes = 60 * arrHours + arrMinutes; // Get all arrival time in minutes
        break;
      }
    }
  }

  if (totalArrMinutes < totalDepMinutes) {
    totalArrMinutes += 1440; // Add 24 hours to display number of days
  }

  int tripMinutes = totalArrMinutes - totalDepMinutes; // The trip time in minutes

  int hours = tripMinutes / 60; // Get number of hours 
  int mins = tripMinutes % 60; // Get number of minutes

  std::cout << "The trip was " << hours << " hours, and " << mins << " minutes.\n";

  return 0;
}
