#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>

void timer(int minutes, int seconds)
{
  int total_seconds = minutes * 60 + seconds;
  time_t start_time = time(nullptr);
  
  while (true) 
  {
    time_t current_time = time(nullptr);
    int elapsed = difftime(current_time, start_time);
    int remaining = total_seconds - elapsed;
    
    if (remaining <= 0) break;
    
    int mins = remaining / 60;
    int secs = remaining % 60;
    
    std::cout << "\rTime remaining: " 
              << std::setfill('0') << std::setw(2) << mins << ":" 
              << std::setfill('0') << std::setw(2) << secs << std::flush;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(200)); //задержка 200 мс для обновления
  }
  
  std::cout << "\rDING! DING! DING!            \n";
}

int main() 
{
  std::cout << "*** Timer Program. ***\n\n";
  
  int minutes, seconds;
  std::cout << "Enter minutes and seconds (mm ss): ";
  std::cin >> minutes >> seconds;
  
  if (minutes < 0 || seconds < 0 || seconds >= 60) 
  {
    std::cout << "Invalid time format!\n";
    return 1;
  }
  
  std::cout << "Timer set for: "
            << std::setfill('0') << std::setw(2) << minutes << ":"
            << std::setfill('0') << std::setw(2) << seconds << "\n";
  
  timer(minutes, seconds);
  
  return 0;
}