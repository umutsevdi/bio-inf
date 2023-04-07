/******************************************************************************

 * File: inc/parser.hpp
 *
 * Author: Umut Sevdi
 * Created: 04/05/23
 * Description: XML Parsing utilities

*****************************************************************************/
#ifndef __PARSER__

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace parser {
struct Pair {
  std::string key;
  std::string value;
};

struct Tree {
  std::string tag;
  std::vector<Pair> data;
  std::vector<Tree> children;
};

/*
 * Returns the string in-between the tag symbols.
 */
inline std::string read_tag(std::string &s);

/**
 * removes spaces from given string. Ignores space in-between quotes.
 */
void trim(std::string &str);

/**
 * parse_pairs - parses given line of string into a vector of key value
 * pairs. Value can be either inside single quote or double quotes.
 */
std::vector<Pair> parse_pairs(const std::string &input);

/**
 * map_args parses xml tag parameters into a pair of vector.
 */
std::vector<Pair> map_args(std::string &input);

/**
 * Recursively parses the XML file.
 */
Tree *parse_tree(Tree &t, std::vector<std::string> &s, size_t i = 0);
} // namespace parser
#endif // !__PARSER__
