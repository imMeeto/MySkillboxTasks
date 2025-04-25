#include <iostream>
#include <cmath>
#include <string>

struct Vector2D
{
  double x;
  double y;
};

Vector2D add(const Vector2D& a, const Vector2D& b)
{
  return {a.x + b.x, a.y + b.y};
}

Vector2D subtract(const Vector2D& a, const Vector2D& b)
{
  return {a.x - b.x, a.y - b.y};
}

Vector2D scale(const Vector2D& v, double scalar)
{
  return {v.x * scalar, v.y * scalar};
}

double length(const Vector2D& v)
{
  return std::sqrt(v.x * v.x + v.y * v.y);
}

Vector2D normalize(const Vector2D& v)
{
  double len = length(v);
  if (len == 0.0)
  {
    return {0.0, 0.0};
  }
  return {v.x / len, v.y / len};
}

int main()
{
  std::cout << "***Mathematical vector programm.***\n\n";
  std::cout << "- Available commands:\n";
  std::cout << "add - Add two vectors\n";
  std::cout << "subtract - Subtract two vectors\n";
  std::cout << "scale - Scale a vector by a number\n";
  std::cout << "length - Calculate vector length\n";
  std::cout << "normalize - Normalize a vector\n\n";
  std::cout << "- Enter command: ";
  
  std::string operation;
  std::cin >> operation;

  if (operation == "add" || operation == "subtract")
  {
    Vector2D a, b;
    std::cout << "Enter first vector (x y): ";
    std::cin >> a.x >> a.y;
    std::cout << "Enter second vector (x y): ";
    std::cin >> b.x >> b.y;
    
    Vector2D result;
    if (operation == "add")
    {
      result = add(a, b);
      std::cout << "----------------------\n";
      std::cout << "Sum of vectors: ";
    } 
    else
    {
      result = subtract(a, b);
      std::cout << "Difference of vectors: ";
    }
    
    std::cout << result.x << " " << result.y << std::endl;
  }
  else if (operation == "scale")
  {
    Vector2D v;
    double scalar;
    std::cout << "Enter vector (x y): ";
    std::cin >> v.x >> v.y;
    std::cout << "Enter scale factor: ";
    std::cin >> scalar;
    
    Vector2D result = scale(v, scalar);
    std::cout << "----------------------\n";
    std::cout << "Scaled vector: " << result.x << " " << result.y << std::endl;
  }
  else if (operation == "length")
  {
    Vector2D v;
    std::cout << "Enter vector (x y): ";
    std::cin >> v.x >> v.y;
    
    double result = length(v);
    std::cout << "----------------------\n";
    std::cout << "Vector length: " << result << std::endl;
  }
  else if (operation == "normalize")
  {
    Vector2D v;
    std::cout << "Enter vector (x y): ";
    std::cin >> v.x >> v.y;
    
    Vector2D result = normalize(v);
    std::cout << "----------------------\n";
    std::cout << "Normalized vector: " << result.x << " " << result.y << std::endl;
  }
  else
  {
    std::cout << "Error: Unknown operation!\n";
  }

  return 0;
}