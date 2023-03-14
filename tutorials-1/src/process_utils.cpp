/******************************************************************************

 * File: process-utils.cpp
 *
 * Author: Umut Sevdi
 * Created: 03/12/23
 * Description: Commonly used text utility functions.
*****************************************************************************/
#include "process_utils.hpp"
#include <vector>

namespace process_utils {

std::string erase_space(const std::string &str) {
  std::string result;
  for (char c : str) {
    if (!std::isspace(static_cast<unsigned char>(c))) {
      result += c;
    }
  }
  return result;
}

std::string &transcribe_dna(std::string &str) {
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

std::string &thymine2uracil(std::string &str) {
  for (char &c : str) {
    if (c == 'U') {
      c = 'T';
    } else if (c == 'T') {
      c = 'U';
    }
  }
  return str;
}

int hamming_dist(std::string &str1, std::string &str2) {
  if (str1.length() != str2.length()) {
    return -1;
  }
  int dist = 0;
  for (long unsigned int i = 0; i < str1.length(); i++) {
    if (str1[i] != str2[i])
      dist++;
  }
  return dist;
}

int lev_dist(std::string &str1, std::string &str2) {
  // Initialize a matrix to hold the distances between prefixes
  std::vector<std::vector<int>> dist(str1.length() + 1,
                                     std::vector<int>(str2.length() + 1));
  for (long unsigned int i = 0; i <= str1.length(); ++i) {
    dist[i][0] = i;
  }
  for (long unsigned int j = 0; j <= str2.length(); ++j) {
    dist[0][j] = j;
  }
  // Calculate the distances between prefixes
  for (long unsigned int j = 1; j <= str2.length(); ++j) {
    for (long unsigned int i = 1; i <= str1.length(); ++i) {
      if (str1[i - 1] == str2[j - 1]) {
        dist[i][j] = dist[i - 1][j - 1];
      } else {
        dist[i][j] =
            1 + std::min({dist[i - 1][j], dist[i][j - 1], dist[i - 1][j - 1]});
      }
    }
  }
  // The Levenshtein distance is the distance between the full strings
  return dist[str1.length()][str2.length()];
}
} // namespace process_utils
