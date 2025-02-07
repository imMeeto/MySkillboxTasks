#include <iostream>
#include <cmath>

int main() {
    float a, b, c;
    std::cout << "a, b, c: ";
    std::cin >> a >> b >> c;

    if (a == 0) {
        std::cout << "Not a quadratic equation!" << std::endl;
        return 0;
    }

    float discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {  // Two real roots
        float x1 = (-b + std::sqrt(discriminant)) / (2 * a);
        float x2 = (-b - std::sqrt(discriminant)) / (2 * a);
        std::cout << "Roots: " << x1 << ", " << x2 << std::endl;
    } else if (discriminant == 0) {
        float x = -b / (2 * a);
        std::cout << "Root: " << x << std::endl;
    } else {
        std::cout << "Complex scenario is not supported!" << std::endl;
    }

    return 0;
}