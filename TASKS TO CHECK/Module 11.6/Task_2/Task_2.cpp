#include <iostream>
#include <string>

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

bool isValidPart(std::string part, std::string allowedChars) {
  for (char c : part) {
    bool found = false;
    for (char allowed : allowedChars) {
      if (c == allowed) {
        found = true;
        break;
      }
    }
    if (!found) {
      return false;
    }
  }

  return true;
}

bool hasValidDots(std::string part) {
  if (part.empty()) {
    return false;
  }

  if (part.back() == '.' || part.front() == '.') {
    return false;
  }
  
  for (int i = 0; i < part.length() - 1; i++) {
    if (part[i] == '.' && part[i + 1] == '.') {
      return false;
    }
  }

  return true;
}

bool isValidEmail(std::string email) {
  std::string leftValidPart = leftPart(email);
  std::string rightValidPart = rightPart(email);
  
  int atCount = 0;
  for (char c : email) {
    if (c == '@') {
      ++atCount;
    }
  }
  
  if (atCount != 1) {
    return false;
  }
  
  if (leftValidPart.length() < 1 || leftValidPart.length() > 64 
      || rightValidPart.length() < 1 || rightValidPart.length() > 63) {
    return false;
  }
  
  if (!isValidPart(leftValidPart, allowedCharsInLeft) || !isValidPart(rightValidPart, allowedCharsInRight)) {
    return false;
  }
  
  if (!hasValidDots(leftValidPart) || !hasValidDots(rightValidPart)) {
    return false;
  }
  
  return true;
}

int main() {
  std::cout << "*Make sure that the email address is correct.*\n";

  std::string emailMain;

  std::cout << "Enter your email address: ";
  std::getline(std::cin, emailMain);

  if (isValidEmail(emailMain)) {
    std::cout << "Yes!\n";
  } else {
    std::cout << "No!\n";
  }

  return 0;
}