#include <iostream>
#include <vector>

int main() { 
  std::cout << "*Calculate the total cost of the items.*\n";

  std::cout << "Input how many items you want to buy: ";
  int items = 0;
  std::cin >> items;

  std::vector<float> prices(items);
  std::cout << "Input the prices of the items:\n";
  for (int i = 0; i < items; i++) {
      std::cout << "- price for item " << i + 1 << ": ";
      std::cin >> prices[i];
  }

  std::cout << "Input the numbers of the bought items (1 to " << items << "):\n";
  std::vector<int> numbers(items); 
  for (int i = 0; i < items; i++) {
      std::cout << "- number of item: ";
      std::cin >> numbers[i];

      if (numbers[i] < 1 || numbers[i] > items) {
          std::cerr << "Error: Invalid item number " << numbers[i] << ". It must be between 1 and " << items << ".\n";
          return 1; 
      }

      numbers[i]--; // Преобразуем номер товара во внутренний индекс
  }

  float totalCost = 0;

  for (int index : numbers)
  {
    totalCost += prices[index];
  } 

  std::cout << "Total cost: " << totalCost << "\n";
  return 0;
}