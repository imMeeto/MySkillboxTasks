#include <iostream>

// раскомментируй нужный макрос
// #define SPRING
// #define SUMMER
// #define AUTUMN
// #define WINTER

int main() {
#if defined(SPRING)
    std::cout << "Spring" << std::endl;
#elif defined(SUMMER)
    std::cout << "Summer" << std::endl;
#elif defined(AUTUMN)
    std::cout << "Autumn" << std::endl;
#elif defined(WINTER)
    std::cout << "Winter" << std::endl;
#else
    #error "Please define one of: SPRING, SUMMER, AUTUMN or WINTER"
#endif

    return 0;
}