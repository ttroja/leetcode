#include "common.h"

/*
You are given a string s, and an array of pairs of indices in the string pairs
where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number
of times.

Return the lexicographically smallest string that s can be changed to after
using the swaps.

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination:
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.
*/

std::string swap(const std::string &str,
                 const std::vector<std::pair<int, int>> &indices) {
  std::string buf_str = str;
  while (true) {
    bool b_continue = false;
    std::pair<int, int> min_indice{INT32_MAX, INT32_MAX};
    for (const auto &indice : indices) {
      if (buf_str[indice.first] > buf_str[indice.second]) {
        if (indice.first < min_indice.first) {
          min_indice = indice;
        }
        b_continue = true;
      }
    }
    if (!b_continue) {
      break;
    } else {
      auto temp = buf_str;
      auto c = buf_str[min_indice.first];
      buf_str[min_indice.first] = buf_str[min_indice.second];
      buf_str[min_indice.second] = c;
      printf("'%s' [%d, %d] -> '%s'\n", temp.c_str(), min_indice.first,
             min_indice.second, buf_str.c_str());
    }
  }
  printf("result: %s\n", buf_str.c_str());
  return buf_str;
}

int main() {
  {
    std::vector<std::pair<int, int>> indices = {{0, 3}, {1, 2}};
    ASSERT(swap("dcab", indices) == "bacd");
  }
  {
    std::vector<std::pair<int, int>> indices = {{0, 3}, {1, 2}, {0, 2}};
    ASSERT(swap("dcab", indices) == "abcd");
  }
  {
    std::vector<std::pair<int, int>> indices = {{0, 1}, {1, 2}};
    ASSERT(swap("cba", indices) == "abc");
  }
  return 0;
}