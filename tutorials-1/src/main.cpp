/******************************************************************************

 * File: main.cpp
 *
 * Author: Umut Sevdi
 * Created: 03/12/23
 * Description: Bioinformatics Lecture Tutorial - 1 examples
*****************************************************************************/
#include "process_utils.hpp"
#include <cctype>
#include <iostream>
#include <string>

#define EXAMPLE_2

void read_seq(std::string &s) {
  /* std::string s = "    TCAT AATA CGTT TTGT ATTC GCCA GCGC TTCG GTGT
     "; */
  std::cout << "Enter a DNA sequence string: ";
  std::getline(std::cin, s);
}

/******************************************************************************
                                    EXAMPLE 1
*****************************************************************************/
/*
 * Description: Transcribe the following DNA to RNA, then
 * use the genetic code to translate it to a sequence of amino acids.
 */
#ifdef EXAMPLE_1
int main(int argc, char *argv[]) {
  std::string str;
  read_seq(str);
  std::cout << process_utils::erase_space(str) << "\n";
  str = process_utils::erase_space(str);
  process_utils::thymine2uracil(process_utils::transcribe_dna(str));
  std::cout << str << "\n";
}
#endif

/******************************************************************************
                                    EXAMPLE 2
*****************************************************************************/
/*
 * Description: Remove the first letter from the sequence given
 * in example 1, and redo the translation. Explain
 * what happened?
 */

#ifdef EXAMPLE_2
int main(int argc, char *argv[]) {
  std::string str;
  read_seq(str);
  /*remove the first line*/
  str = str.substr(1);

  std::cout << process_utils::erase_space(str) << "\n";
  str = process_utils::erase_space(str);
  process_utils::thymine2uracil(process_utils::transcribe_dna(str));
  std::cout << str << "\n";
}
#endif

/******************************************************************************
                                    EXAMPLE 3
*****************************************************************************/
/*
 * Description: Remove the first letter from the sequence given
 * in example 1, and redo the translation. Explain
 * what happened?
 */

#ifdef EXAMPLE_3
int main(int argc, char *argv[]) {
  std::string str;
  std::string str2;
  read_seq(str);
  read_seq(str2);
  str = process_utils::erase_space(str);
  str2 = process_utils::erase_space(str2);

  std::cout << "Hamming Distance:     "
            << process_utils::hamming_dist(str, str2) << "\n"
            << "Levenshtein Distance: " << process_utils::lev_dist(str, str2)
            << "\n";
}
#endif
