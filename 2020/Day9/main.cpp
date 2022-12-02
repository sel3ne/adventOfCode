#include <algorithm>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<int64_t> readInput() {
  std::string line;
  std::ifstream myFile("input.txt");
  std::vector<int64_t> input = {};
  if (myFile.is_open()) {
    while (getline(myFile, line)) {
      input.push_back(std::strtoll(line.c_str(), NULL, 10));
    }
  } else {
    std::cout << "Can not open file!" << std::endl;
  }
  return input;
}

bool validNumber(std::vector<int64_t> nums, int64_t result) {
  for (int i = 0; i < nums.size() - 1; i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      std::cout << "i: " << i << "  j: " << j << std::endl;

      if (nums[i] + nums[j] == result) {
        return true;
      }
    }
  }
  return false;
}

int64_t sumInVector(std::vector<int64_t> nums, int begin, int end) {
  int64_t counter = 0;
  for (int i = begin; i < end; i++) {
    counter = counter + nums[i];
  }
  return counter;
}
bool validNumber2(std::vector<int64_t> nums, int64_t result) {
  for (int end = 1; end < nums.size(); end++) {
    for (int begin = 0; begin < end; begin++) {
      if (sumInVector(nums, begin, end) == result) {
        std::vector<int64_t> result(nums.begin() + begin, nums.begin() + end);
        std::sort(result.begin(), result.end());
        std::cout << "min: " << result[0]
                  << "  max: " << result[result.size() - 1] << std::endl;
        std::cout << "min + max = " << result[0] + result[result.size() - 1]
                  << std::endl;
        return true;
      }
    }
  }
  return false;
}

void printVector(std::vector<int64_t> nums) {
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << std::endl;
  }
}

int main() {
  std::vector<int64_t> input = readInput();
  int64_t preamble = 26134589;
  // int64_t preamble = 127;
  for (int i = 1; i < input.size(); i++) {
    std::vector<int64_t> nums(input.begin(), input.begin() + i);

    if (validNumber2(nums, preamble)) {
      break;
    }
  }
  return 0;
}

// int main1() {
//   std::vector<int64_t> input = readInput();
//   int preamble = 25;

//   for (int i = preamble + 1; i < input.size(); i++) {
//     std::vector<int64_t> nums(input.begin() + i - preamble, input.begin() +
//     i); std::cout << nums.size() << std::endl; int64_t nextElement =
//     input[i]; if (!validNumber(nums, nextElement)) {
//       std::cout << "not valid " << input[i] << std::endl;
//       break;
//     }
//   }

//   return 0;
// }
