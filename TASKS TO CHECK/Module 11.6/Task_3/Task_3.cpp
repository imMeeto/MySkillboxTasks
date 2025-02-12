#include <iostream>
#include <string>

bool isValidOctet(std::string octet) {
  if (octet.empty() || octet.size() > 3) return false;

  for (int i = 0; i < octet.size(); i++) {
    if (!isdigit(octet[i])) return false;
  }

  int num = 0;
  
  
  


}