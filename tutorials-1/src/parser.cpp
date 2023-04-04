#include "parser.hpp"

namespace parser {
inline std::string read_tag(std::string &s) {
  size_t f_i = s.find('<');
  size_t f_o = s.find('>');
  if (f_i < f_o) {
    return s.substr(f_i + 1, f_o - 1);
  }
  return "";
}

void remove_quotes(std::string &str) {
  str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
}

void trim(std::string &str) {
  bool is_quote = false;
  for (size_t i = 0; i < str.length(); i++) {
  }
  //TODO complete trim function
}

void map_args(std::string &s, std::vector<Pair> &v) {
  size_t pos = 0;
  while (pos < s.length()) {
    // find the next key-value pair
    size_t eq_pos = s.find('=', pos);
    if (eq_pos == std::string::npos) {
      break;
    }
    size_t key_start = s.rfind(' ', eq_pos) + 1;
    size_t key_end = eq_pos - 1;
    while (key_end > key_start && s[key_end] == ' ') {
      key_end--;
    }
    size_t value_start = s.find('"', eq_pos) + 1;
    size_t value_end = s.find('"', value_start);
    std::string key = s.substr(key_start, key_end - key_start + 1);
    std::string value = s.substr(value_start, value_end - value_start);
    remove_quotes(key);
    remove_quotes(value);
    Pair p = {key, value};
    v.push_back(p);
    pos = value_end + 1;
  }
}
Tree &parse_tree(Tree &t, std::vector<std::string> &s, int i = 0) {
  if (i >= s.size()) {
    return t;
  }
  std::string f = read_tag(s[i]);
  int f_end = 0;
  // end tag
  while (f[f_end++] != ' ' && f_end < f.length())
    ;

  if (!t.tag.empty() && t.tag == f) {
    return t;
  }
  t.tag = f.substr(0, f_end);
  map_args(f, t.data);
  return t;
  // TODO fix parse_tree recursive traversal
}
}; // namespace parser
