#include <iostream>
#include <string>

using namespace std;

string encrypt_caesar(string text, int code) {
    code = code % 26;

    string result = "";

    for (char c : text) { 
        if ('A' <= c && c <= 'Z') {
            char new_char = (c - 'A' + code) % 26 + 'A';
            result += new_char;  
        }
        else if ('a' <= c && c <= 'z') {
            char new_char = (c - 'a' + code) % 26 + 'a';
            result += new_char;  
        } else {
            result += c; 
        }
    }

    return result;
}

int main() {
    string text1 = "aBxZ*";
    int code1 = 67;
    cout << "Text: " << text1 << endl;
    cout << "Code: " << code1 << endl;
    cout << "Result: " << encrypt_caesar(text1, code1) << endl;

    string text2 = "The quick brown fox jumps over the lazy dog";
    int code2 = 3;
    cout << "\nText: " << text2 << endl;
    cout << "Code: " << code2 << endl;
    cout << "Result: " << encrypt_caesar(text2, code2) << endl;

    return 0;
}