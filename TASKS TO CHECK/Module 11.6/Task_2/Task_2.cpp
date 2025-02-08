#include <iostream>

const std::string allowedCharsInLeft = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-!#$%&'*+/=?^_`{|}~";
const std::string allowedCharsInRight = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-";

std::string leftPart(std::string email) {
  std::string left = "";

  for (char c : email) {
    if (c == '@') {
      break;
    }
    left += c;
  }
  return left;
}

std::string rightPart(std::string email) {
  std::string right = "";
  bool foundAt = false; // Flag to track if '@' has been found

  for (char c : email) {
    if (foundAt) {
      right += c;
    }

    if (c == '@') {
      foundAt = true;
    }
  }
  return right;
}

int main() {
  std::cout << "*Make sure that the email address is correct.*\n";

  std::string emailMain;

  std::cout << "Enter your email address: ";
  std::getline(std::cin, emailMain);

  return 0;
}