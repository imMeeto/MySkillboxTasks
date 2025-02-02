#include <iostream>
using namespace std;

int main() {
    cout << "Проверка корректности записи вещественного числа.\n";
    string number;
    cout << "Введите вещественное число: ";
    cin >> number;

    // Проверка на пустую строку и первый символ
    if (number.empty() || !(number[0] >= '0' && number[0] <= '9' || number[0] == '.' || number[0] == '-')) {
        cout << "No\n";
        return 0;
    }

    int dotCount = 0; // Счетчик точек
    bool hasDigit = false; // Флаг наличия хотя бы одной цифры
    bool hasDigitAfterDot = false; // Флаг наличия цифр после точки

    for (int i = 0; i < number.length(); i++) {
        if (number[i] == '.') {
            dotCount++;
            if (dotCount > 1) { // Более одной точки
                cout << "No\n";
                return 0;
            }
        } else if (number[i] >= '0' && number[i] <= '9') {
            hasDigit = true; // Есть хотя бы одна цифра
            if (dotCount == 1) {
                hasDigitAfterDot = true; // Цифра после точки
            }
        } else {
            cout << "No\n"; // Недопустимый символ
            return 0;
        }
    }

    // Если строка начинается с минуса, проверяем, чтобы после него были цифры или точка с цифрами
    if (number[0] == '-') {
        if (number.length() == 1) { // Если только минус без цифр
            cout << "No\n";
            return 0;
        }
        if (dotCount == 1 && !hasDigitAfterDot) { // Если есть точка, но нет цифр после нее
            cout << "No\n";
            return 0;
        }
    }

    // Проверка на наличие хотя бы одной цифры
    if (!hasDigit) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n"; // Все проверки пройдены успешно
    return 0;
}