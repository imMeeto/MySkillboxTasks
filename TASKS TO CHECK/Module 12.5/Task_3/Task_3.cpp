#include <iostream>
#include <cassert>

float travelTime(float distance, float speed) {
    assert(speed > 0);

    return distance / speed;
}

int main() {
    float distance, speed;

    std::cout << "Enter the distance (km): ";
    std::cin >> distance;

    std::cout << "Enter the speed (km/h): ";
    std::cin >> speed;

    float time = travelTime(distance, speed);
    std::cout << "Travel time: " << time << " hours" << "\n";

    return 0;
}