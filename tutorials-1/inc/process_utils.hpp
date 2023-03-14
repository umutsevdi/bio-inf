/******************************************************************************

 * File: process_utils.hpp
 *
 * Author: Umut Sevdi
 * Created: 03/12/23
 * Description: Commonly used text utility functions.
*****************************************************************************/
#ifndef __PROCESS_UTILS__
#define __PROCESS_UTILS__

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
namespace process_utils {
/**
 * Returns a copy of the string in which all tabs, spaces or newline characters
 * are removed.
 */
std::string erase_space(const std::string &str);
/**
 * Transcribes the DNA sequence, in place. Returns the input.
 */
std::string &transcribe_dna(std::string &str);
/**
 * Replaces all Thymine(T) with Uracil(U), in place.
 * Returns the input.
 */
std::string &thymine2uracil(std::string &str);

/**
 * Returns the hamming distance of the given strings
 * -1 if not equal
 *
 */
int hamming_dist(std::string &str1, std::string &str2);

/**
 * Returns the Levenshtein distance of the given strings
 * -1 if not equal
 *
 */
int lev_dist(std::string &str1, std::string &str2);

} // namespace process_utils

#endif
