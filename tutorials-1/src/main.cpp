#include "example_1.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>

int main(int argc, char *argv[]) {
  std::string s;
  /* std::string s = "    TCAT AATA CGTT TTGT ATTC GCCA GCGC TTCG GTGT
     "; */
  std::cout << "Enter a DNA sequence string: ";
  std::getline(std::cin, s);

  std::cout << erase_space(s) << "\n";
  s = erase_space(s);
  thymine2uracil(transcribe_dna(s));
  std::cout << s << "\n";
}

inline std::string erase_space(const std::string &str) {
  std::string result;
  for (char c : str) {
    if (!std::isspace(static_cast<unsigned char>(c))) {
      result += c;
    }
  }
  return result;
}

inline std::string &transcribe_dna(std::string &str) {
  for (char &c : str) {
    switch (c) {
    case 'A':
      c = 'T';
      break;
    case 'T':
      c = 'A';
      break;
    case 'G':
      c = 'C';
      break;
    case 'C':
      c = 'G';
      break;
    }
  }
  return str;
}

inline std::string &thymine2uracil(std::string &str) {
  for (char &c : str) {
    if (c == 'U') {
      c = 'T';
    } else if (c == 'T') {
      c = 'U';
    }
  }
  return str;
}
