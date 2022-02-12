#include "common.h"

/*
Given a string, find the length of the longest substring without repeating
characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a _subsequence_
and not a substring.
*/

// O(n)
static int length_substring(const std::string &input) {
  int max_length = 0,
      left =
          -1; // left指向的是上一个之前出现的重复字符的索引，则最右边字符索引减去该索引就是不重复的长度
  auto length = input.size();
  std::unordered_map<int, int> map_string;
  for (int i = 0; i < static_cast<int>(length); ++i) {
    if (map_string.count(input[i]) && map_string[input[i]] > left) {
      left = map_string[input[i]];
    }
    map_string[input[i]] =
        i; // 这里，如果有重复字符的话，会只记录最后一个索引，非常棒
    max_length = std::max(max_length, i - left);
  }
  printf("%d\n", max_length);
  return max_length;
}

static std::string longest_substring(const std::string &input) {
  int cur_left = -1, idx_left = -1, idx_right = -1;
  int max_length = 0;
  auto length = input.size();
  std::unordered_map<int, int> map_string;
  for (int i = 0; i < static_cast<int>(length); ++i) {
    if (map_string.count(input[i]) && map_string[input[i]] > cur_left) {
      cur_left = map_string[input[i]];
    }
    map_string[input[i]] = i;
    if (i - cur_left > max_length) {
      max_length = i - cur_left;
      idx_left = cur_left;
      idx_right = i;
    }
  }
  std::string ret_string = input.substr(
      idx_left + 1, idx_right - idx_left); // idx_left是上一个重复字符，要排除掉
  printf("%s\n", ret_string.c_str());
  return ret_string;
}

int main() {
  std::string input1 = "abcbadeacbd";
  std::string target1 = "cbade";
  int length1 = 5;

  std::string input2 = "pwwkew";
  std::string target2 = "wke";
  int length2 = 3;

  auto ret_len1 = length_substring(input1);
  ASSERT(ret_len1 == length1);

  auto ret_len2 = length_substring(input2);
  ASSERT(ret_len2 == length2);

  auto ret_str1 = longest_substring(input1);
  ASSERT(ret_str1 == target1);

  auto ret_str2 = longest_substring(input2);
  ASSERT(ret_str2 == target2);

  return 0;
}