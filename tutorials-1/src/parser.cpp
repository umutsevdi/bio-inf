#include "parser.hpp"
inline bool is_space(char x) { return (x == ' ' || x == '\t' || x == '\n'); }
inline bool is_quote(char x) { return (x == '"' || x == '\''); }

namespace parser {
inline std::string read_tag(std::string &s) {
  size_t f_i = s.find('<');
  size_t f_o = s.find('>');
  if (f_i < f_o) {
    return s.substr(f_i + 1, f_o - 1);
  }
  return "";
}

void trim(std::string &str) {
  bool quote = false;
  size_t j = 0;
  for (char &s : str) {
    if (is_quote(s)) {
      quote = !quote;
    }
    if ((!quote && !is_space(s)) || quote) {
      str[j++] = s;
    }
  }
  // resize only if any trimming is applied
  if (j < str.length()) {
    str.resize(j);
  }
}

/**
 * parse_pairs - parses given line of string into a vector of key value
 * pairs. Value can be either inside single quote or double quotes.
 */
std::vector<Pair> parse_pairs(const std::string &input) {
  std::vector<Pair> result;
  size_t pos = 0;
  while (pos < input.length()) {
    size_t eq_pos = input.find('=', pos);
    if (eq_pos == std::string::npos) {
      break; // No more pairs found
    }

    std::string key = input.substr(pos, eq_pos - pos);

    // Find the next quote character
    size_t quote_pos = input.find_first_of("'\"", eq_pos + 1);
    if (quote_pos == std::string::npos) {
      break; // Error: no quote found after '='
    }

    char quote = input[quote_pos];
    std::string::size_type end_pos = input.find(quote, quote_pos + 1);
    if (end_pos == std::string::npos) {
      break; // Error: no closing quote found
    }
    std::string value = input.substr(quote_pos + 1, end_pos - quote_pos - 1);

    result.push_back(Pair{key, value});
    pos = end_pos + 1;
  }
  return result;
}

std::vector<Pair> map_args(std::string &input) {
  parser::trim(input);
  std::vector<Pair> pair = parser::parse_pairs(input);
  for (Pair p : pair) {
    std::cout << "{" << p.key << ", " << p.value << "}\n";
  }
  return pair;
}

parser::Tree *parse_tree(parser::Tree &t, std::vector<std::string> &v,
                         size_t i) {
  if (i >= v.size()) {
    return &t;
  }
  std::string f = parser::read_tag(v[i]);
  size_t f_end = 0;
  // end tag
  while (f[f_end++] != ' ' && f_end < f.length())
    ;

  if (!t.tag.empty() && t.tag == f) {
    return &t;
  }
  t.tag = f.substr(0, f_end);
  t.data = parser::map_args(f);

  for (parser::Pair p : t.data) {
    std::cout << t.tag << " " << p.key << ":" << p.value << std::endl;
  }

  Tree *child_tree = parse_tree(t, v);
  if (child_tree != nullptr) {
    t.children.push_back(*child_tree);
  }
  return &t;
}
}; // namespace parser
