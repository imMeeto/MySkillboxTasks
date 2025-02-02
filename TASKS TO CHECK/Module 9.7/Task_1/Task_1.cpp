#include <iostream>

int main() {
  std::cout << "Travel time calculator program.\n";

  std::string depTime;
  std::string arrTime;
  int totalDepMinutes;
  int totalArrMinutes;

  std::cout << "Input departure time (HH:MM): ";
  std::cin >> depTime;

  if (depTime.length() !=5 || depTime[2] != ':' 
      || depTime[0] < '0' || depTime[0] > '9'
      || depTime[1] < '0' || depTime[1] > '9'
      || depTime[3] < '0' || depTime[3] > '9'
      || depTime[4] < '0' || depTime[4] > '9') {
    std::cout << "Error! Input (HH:MM) format!\n"; 
  } else {
    int depHours = (depTime[0] - '0') * 10 + (depTime[1] - '0');
    int depMinutes = (depTime[3] - '0') * 10 + (depTime[4] - '0');

    if (depHours > 23 || depMinutes > 59) {
      std::cout << "Error! Input (HH:MM) format!\n";
    } else {
      totalDepMinutes = 60 * depHours + depMinutes; // Get all departure time in minutes
    }
  }

  std::cout << "Input arrival time (HH:MM): ";
  std::cin >> arrTime;

  if (arrTime.length() !=5 || arrTime[2] != ':' 
      || arrTime[0] < '0' || arrTime[0] > '9'
      || arrTime[1] < '0' || arrTime[1] > '9'
      || arrTime[3] < '0' || arrTime[3] > '9'
      || arrTime[4] < '0' || arrTime[4] > '9') {
    std::cout << "Error! Input (HH:MM) format!\n"; 
  } else {
    int arrHours = (arrTime[0] - '0') * 10 + (arrTime[1] - '0');
    int arrMinutes = (arrTime[3] - '0') * 10 + (arrTime[4] - '0');

    if (arrHours > 23 || arrMinutes > 59) {
      std::cout << "Error! Input (HH:MM) format!\n";
    } else {
      totalArrMinutes = 60 * arrHours + arrMinutes; // Get all arrival time in minutes
    }
  }

  int tripMinutes = totalArrMinutes - totalDepMinutes; // The trip time in minutes

    // Get number of days
    int days = tripMinutes / 1440;
    tripMinutes = tripMinutes % 1440; 

    // Get number of hours 
    int hours = tripMinutes / 60;

    // Get number of minutes 
    int mins = tripMinutes % 60;

  std::cout << "The trip was " << days << " days, " << hours << " hours, and " << mins << " minutes.\n";

  return 0;
}