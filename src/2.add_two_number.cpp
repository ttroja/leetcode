#include "common.h"

/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single
digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

// too easy O(n)
static std::list<int> add_two_number(const std::list<int> &number1,
                                     const std::list<int> &number2) {
  auto iter1 = number1.cbegin();
  auto iter2 = number2.cbegin();

  auto length1 = number1.size();
  auto length2 = number2.size();

  auto length = std::max(length1, length2);

  std::list<int> ret_list = {};
  int left_value = 0;

  for (int i = 0; i < static_cast<int>(length); ++i) {
    auto val1 = (iter1 != number1.cend() ? *(iter1++) : 0);
    auto val2 = (iter2 != number2.cend() ? *(iter2++) : 0);
    auto cur_value = (left_value + val1 + val2) % 10;
    left_value = (left_value + val1 + val2) / 10;
    printf("cur_value: %d\n", cur_value);
    ret_list.push_back(cur_value);
  }
  return ret_list;
}

int main() {
  std::list<int> number1 = {9, 7, 4, 2, 5};    // 52479
  std::list<int> number2 = {1, 2, 3, 6, 8, 2}; // 286321

  int target = 286321 + 52479;

  auto ret_list = add_two_number(number1, number2);
  int ret_val = 0, i = 0;

  auto iter = ret_list.cbegin();
  while (iter != ret_list.cend()) {
    ret_val += (*(iter++) * pow(10, i++));
  }
  ASSERT(ret_val == target);

  return 0;
}