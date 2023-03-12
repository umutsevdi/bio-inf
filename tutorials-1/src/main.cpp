/******************************************************************************

 * File: main.cpp
 *
 * Author: Umut Sevdi
 * Created: 03/12/23
 * Description:
 *     Bioinformatics Example 1 - Transcribe the following DNA to RNA, then
 use the genetic code to translate it to a sequence of amino acids.

*****************************************************************************/
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

/**
 * Returns a copy of the string in which all tabs, spaces or newline characters
 * are removed.
 */
inline std::string erase_space(const std::string &str);
/**
 * Transcribes the DNA sequence, in place. Returns the input.
 */
inline std::string &transcribe_dna(std::string &str);
/**
 * Replaces all Thymine(T) with Uracil(U), in place.
 * Returns the input.
 */
inline std::string &thymine2uracil(std::string &str);

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