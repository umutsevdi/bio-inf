/******************************************************************************

 * File: main.cpp
 *
 * Author: Umut Sevdi
 * Created: 03/12/23
 * Description: Bioinformatics Lecture Tutorial - 1 examples
*****************************************************************************/
#include "parser.hpp"
#include "process_utils.hpp"

#define EXAMPLE_1

inline void read_seq(std::string &s) {
  std::cout << "Enter a DNA sequence string: ";
  /* std::string s = "    TCAT AATA CGTT TTGT ATTC GCCA GCGC TTCG GTGT"; */
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
  str = process_utils::erase_space(str);
  std::cout << str << "\n";
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
  str = process_utils::erase_space(str);
  std::cout << str << "\n";
  process_utils::thymine2uracil(process_utils::transcribe_dna(str));
  std::cout << str << "\n";
}
#endif

/******************************************************************************
                                    EXAMPLE 3
*****************************************************************************/
/*
 * Description: Calculate the Hamming distance and Levenshtein distances
 * of the given strings.
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

/******************************************************************************
                            EXAMPLE 4
*****************************************************************************/
/*
 * Description: Using the BLOSUM62 substitution matrix,
 * what is the best alignment of these two
 * sequences? (Slide one over the other, and
 * score –1 for end gaps, i.e., letters hanging
 * over either ends).
 */

#ifdef EXAMPLE_4
int main(int argc, char *argv[]) {
  std::string str;
  std::string str2;
  read_seq(str);
  read_seq(str2);
  str = process_utils::erase_space(str);
  str2 = process_utils::erase_space(str2);
  // TODO Finish example

  return 0;
}
#endif

/******************************************************************************
                                XML Parser
*****************************************************************************/
/**
 * Description: Develop a simplified XML parser.
 */
#ifdef EXAMPLE_5
int main() {
  std::string s = "key=\"value\"   another-key      = \"another-value\"   a = "
                  "\"b\" one-key                             =                 "
                  "             \"value with space\"  key-with-single-quotes = \'QUOTED_VALUE WITH SPACE\'";

  std::cout << s << std::endl;
  parser::trim(s);
  std::cout << s << std::endl;

  /*
  std::vector<Pair> v;
  parser::map_args(s, v);
  for (parser::Pair p : v) {
    std::cout << p.key << ", " << p.value << std::endl;
  }
  */
}
#endif
