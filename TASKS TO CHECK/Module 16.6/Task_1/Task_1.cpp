#include <iostream>

int main()
{
  float speed = 0.0f;
  float delta;

  std::cout << "*Сar speedometer simulator.*\n";
  std::cout << "Speed: " << speed << "\n"; 

  do
  {
    std::cout << "Input delta: ";
    std::cin >> delta;
    speed += delta;
    
    if (speed > 150.0)
    {
      speed = 150.0;
    } else if (speed < 0.0)
    {
      speed = 0.0;
    }
    
    char speed_str[6];
    sprintf(speed_str, "%.1f", speed);

    std::cout << "Speed: " << speed_str << "\n";
  } while (speed > 0.1);

  std::cout << "Car has stoped!\n";
  return 0;
}