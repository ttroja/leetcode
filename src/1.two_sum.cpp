#include "common.h"

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have  exactly  one solution, and you may not use the  same  element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

struct RET
{
  int idx_first;
  int idx_second;

  bool operator == (const RET& b) const{
    return (idx_first == b.idx_first) && (idx_second == b.idx_second);
  }
};

// brute force O(n^2)
static RET two_sum_brute(const std::vector<int> & input, int target){
  int length = input.size();
  for(int i=0; i<length; ++i){
    for(int j=i+i; j<length; ++j){
      if(input[i]+input[j] == target){
        printf("%d, %d\n", i, j);
        return RET{.idx_first=i, .idx_second=j};
      }
    }
  }
}

// unordered_map O(n)
static RET two_sum_hash(const std::vector<int> & input, int target){
  std::unordered_map<int, int> value_map;
  int length = input.size();
  for(int i=0; i<length; ++i){
    value_map[input[i]] = i; // 用值作为键，索引作为值
  }
  for(int i=0; i<length; ++i){
    int another = target - input[i]; //遍历输入列表，用目标值减去当前值，得到另外一个数，然后判断这个数是否存在与map中即可，这个判断是O(1)的
    if(value_map.count(another) > 0){
      printf("%d, %d\n", i, value_map[another]);
      return RET{.idx_first=i, .idx_second=value_map[another]};
    }
  }
}

int main(){
  std::vector<int> input = {13, 9, 21, 2, 5, 7, 6, 17, 12, 3, 8, 11};

  int target1 = 13;
  RET ret1 = {3, 11};

  auto ret_brute1 = two_sum_brute(input, target1);
  assert(ret_brute1 == ret1);
  auto ret_hash1 = two_sum_hash(input, target1);
  assert(ret_hash1 == ret1);

  int target2 = 29;
  RET ret2 = {2, 10};

  auto ret_brute2 = two_sum_brute(input, target2);
  assert(ret_brute2 == ret2);
  auto ret_hash2 = two_sum_hash(input, target2);
  assert(ret_hash2 == ret2);
  
  return 0;
}