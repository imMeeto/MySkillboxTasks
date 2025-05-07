#include <iostream>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

#define DAY_TO_STR(day) DAY_##day##_STR

#define DAY_1_STR "MONDAY"
#define DAY_2_STR "TUESDAY"
#define DAY_3_STR "WEDNESDAY"
#define DAY_4_STR "THURSDAY"
#define DAY_5_STR "FRIDAY"
#define DAY_6_STR "SATURDAY"
#define DAY_7_STR "SUNDAY"

#define CHECK_PRINT_DAY(num) \
        if (inputDay == num) \
        { \
          std::cout << "Current day: " << DAY_TO_STR(num) << std::endl; \
          return 0; \
        }


int main()
{
  std::cout << "Input the day of the week number (1-7): ";
  int inputDay;
  std::cin >> inputDay;

  CHECK_PRINT_DAY(1)
  CHECK_PRINT_DAY(2)
  CHECK_PRINT_DAY(3)
  CHECK_PRINT_DAY(4)
  CHECK_PRINT_DAY(5)
  CHECK_PRINT_DAY(6)
  CHECK_PRINT_DAY(7)

  std::cout << "Error! Input day of the week number from 1 to 7!\n";
  return 0;
}