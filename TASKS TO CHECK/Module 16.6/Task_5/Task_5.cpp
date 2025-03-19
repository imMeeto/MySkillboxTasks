#include <iostream>
#include <sstream>
#include <string>

enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

int main()
{
    int switches_state = 0;  // Битовая маска
    int color_temperature = 5000;  // Цветовая температура света 
    int time = 0;  // Время от 0 до 47

    std::cout << "*Smart-home simulator.*\n";

    while (time < 48)
    {
        std::string input;
        std::cout << "Temperature inside, temperature outside, movement, lights: ";
        std::getline(std::cin, input);

        std::stringstream ss(input);
        int temp_inside, temp_outside;
        std::string movement, lights;
        ss >> temp_inside >> temp_outside >> movement >> lights;

        // Управление обогревом водопровода
        if (temp_outside < 0 && !(switches_state & WATER_PIPE_HEATING))
        {
            switches_state |= WATER_PIPE_HEATING;
            std::cout << "Water pipe heating ON!" << "\n";
        } 
        else if (temp_outside > 5 && (switches_state & WATER_PIPE_HEATING))
        {
            switches_state &= ~WATER_PIPE_HEATING;
            std::cout << "Water pipe heating OFF!" << "\n";
        }
        else if (temp_outside > 5 && !(switches_state & WATER_PIPE_HEATING))
        {
            std::cout << "Water pipe heating OFF!" << "\n";
        }

        // Управление садовым освещением
        bool is_evening = (time % 24 >= 16 || time % 24 < 5);
        if (is_evening && movement == "yes" && !(switches_state & LIGHTS_OUTSIDE))
        {
            switches_state |= LIGHTS_OUTSIDE;
            std::cout << "Garden lights ON!" << "\n";
        } 
        else if ((!is_evening || movement == "no") && (switches_state & LIGHTS_OUTSIDE))
        {
            switches_state &= ~LIGHTS_OUTSIDE;
            std::cout << "Garden lights OFF!" << "\n";
        }

        // Управление отоплением
        if (temp_inside < 22 && !(switches_state & HEATERS))
        {
            switches_state |= HEATERS;
            std::cout << "Heaters ON!" << "\n";
        }
        else if (temp_inside >= 25 && (switches_state & HEATERS))
        {
            switches_state &= ~HEATERS;
            std::cout << "Heaters OFF!" << "\n";
        }

        // Управление кондиционером
        if (temp_inside >= 30 && !(switches_state & CONDITIONER))
        {
            switches_state |= CONDITIONER;
            std::cout << "Conditioner ON!" << "\n";
        }
        else if (temp_inside <= 25 && (switches_state & CONDITIONER))
        {
            switches_state &= ~CONDITIONER;
            std::cout << "Conditioner OFF!" << "\n";
        }

        // Управление внутренним освещением и цветовой температурой
        if (lights == "on")
        {
            if (!(switches_state & LIGHTS_INSIDE))
            {
                switches_state |= LIGHTS_INSIDE;
                std::cout << "Lights ON!" << "\n";
            }

            // Изменение цветовой температуры
            if (time % 24 >= 16 && time % 24 <= 20)
            {
                int start_time = 16;
                int end_time = 20;
                int start_temp = 5000;
                int end_temp = 2700;

                color_temperature = start_temp + (end_temp - start_temp) * (time % 24 - start_time) / (end_time - start_time);
            }
            else if (time % 24 == 0)
            {
                color_temperature = 5000;  // Сброс в 00:00
            }

            std::cout << "Color temperature: " << color_temperature << "K" << "\n";
        }
        else if (lights == "off" && (switches_state & LIGHTS_INSIDE))
        {
            switches_state &= ~LIGHTS_INSIDE;
            std::cout << "Lights OFF!" << "\n";
        }

        time++;
    }

    return 0;
}