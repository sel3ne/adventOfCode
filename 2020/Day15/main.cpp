#include <algorithm>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

void tokenize(std::string& str, char delim, std::vector<std::string>& out) {
  size_t start;
  size_t end = 0;

  while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
    end = str.find(delim, start);
    out.push_back(str.substr(start, end - start));
  }
}

std::vector<int> readInput() {
  std::vector<int> input = {};
  std::string line = "11,18,0,20,1,7,16";
  // std::string line = "0,3,6";
  // std::string line = "1,3,2";
  // std::string line = "2,1,3";
  // std::string line = "0,3,6";

  std::vector<std::string> lineAsVector = {};
  tokenize(line, ',', lineAsVector);
  int time = 0;
  for (std::string element : lineAsVector) {
    int num = std::stoi(element);
    input.push_back(num);
  }

  return input;
}

void printVector(std::vector<int> nums) {
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
}

void printMap(std::unordered_map<int, int> map) {
  for (auto it : map) {
    std::cout << it.first << " : " << it.second << std::endl;
  }
}

int main() {
  std::vector<int> input = readInput();
  std::unordered_map<int, int> numbersAndTurns;
  // numbersAndTurns[0] = 1;
  // numbersAndTurns[3] = 2;
  // numbersAndTurns[1] = 1;
  // numbersAndTurns[3] = 2;

  numbersAndTurns[11] = 1;
  numbersAndTurns[18] = 2;
  numbersAndTurns[0] = 3;
  numbersAndTurns[20] = 4;
  numbersAndTurns[1] = 5;
  numbersAndTurns[7] = 6;

  int counter = 1 + input.size() - 1;
  int counterEnd = 30000000;
  // input.reserve(counterEnd);
  for (int i = input.size() - 1; i < 30000030; i++) {
    // std::cout << "----" << std::endl;
    // printMap(numbersAndTurns);
    // printVector(currentInput);
    // std::cout << "Turn " << counter << std::endl;
    // std::cout << "Element: " << input[i] << std::endl;
    std::unordered_map<int, int>::iterator position;

    position = numbersAndTurns.find(input[i]);
    if (position != numbersAndTurns.end()) {
      int changingIndex = numbersAndTurns[input[i]];
      // std::cout << "last occured " << numbersAndTurns[input[i]] << std::endl;
      int age = counter - changingIndex;
      // std::cout << "Found, next element is: " << age << std::endl;
      input.push_back(age);
      numbersAndTurns[input[i]] = counter;
    } else {
      // std::cout << "Not found, next element is: " << 0 << std::endl;
      input.push_back(0);
      numbersAndTurns[input[i]] = counter;
    }
    if (counter % 100000 == 0) {
      std::cout << counter << std::endl;
    }
    if (counter == counterEnd) {
      break;
    }
    counter++;
  }

  // printVector(input);
  std::cout << input[counterEnd - 1] << std::endl;
  // std::vector<int>::iterator position =
  //     std::find(input.begin(), input.end(), 436);
  // if (position != input.end()) {
  //   std::cout << "found" << std::endl;
  // }
  // std::cout << "max size " << input.max_size() << std::endl;
  // std::cout << "size " << input.size() << std::endl;
  return 0;
}
