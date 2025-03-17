#include <iostream>
#include <vector>

std::vector<std::vector<bool>> bubbleWrap(12, std::vector<bool>(12));

void initBubbleWrap()
{
  for (int i = 0; i < 12; ++i)
  {
    for (int j = 0; j < 12; ++j)
    {
      bubbleWrap[i][j] = true;
    }
  }
}

void displayBubbleWrap()
{
  for (int i = 0; i < 12; ++i)
  {
    for (int j = 0; j < 12; ++j)
    {
      std::cout << (bubbleWrap[i][j] ? 'o' : 'x') << " ";
    }
    std::cout << "\n";
  }
}

void popRegion (int startX, int startY, int endX, int endY) 
{
  if (startX < 0 || startX >= 12 || startY < 0 || startY >= 12 ||
      endX < 0 || endX >= 12 || endY < 0 || endY >= 12)
  {
    std::cout << "Error! Region out of bounds.\n";
    return;
  }

  for (int i = startX; i <= endX; ++i)
  {
    for (int j = startY; j <= endY; ++j)
    {
      if (bubbleWrap[i][j])
      {
        bubbleWrap[i][j] = false;
        std::cout << "Pop!\n";  
      }
    }
  }
}

bool allBubblesPoped()
{
  for (int i = 0; i < 12; ++i)
  {
    for (int j = 0; j < 12; ++j)
    {
      if (bubbleWrap[i][j])
      {
        return false;
      }
    }
  }
  return true;
}

int main() 
{
  std::cout << "*Bubble Wrap game.*\n";

  initBubbleWrap();

  while (!allBubblesPoped())
  {
    displayBubbleWrap();
  
    int startX, startY, endX, endY;
    std::cout << "Input start region to pop (x, y): \n";
    std::cin >> startX >> startY;
    std::cout << "Input end region to pop (x, y): \n";
    std::cin >> endX >> endY;

    popRegion(startX, startY, endX, endY);
  }

  std::cout << "All bubbles popped!\n";
  return 0;
}
