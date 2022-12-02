#include <algorithm>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<int> readInput() {
  std::vector<int> input = {};
  // std::string line = "326519478";
  std::string line = "389125467";

  for (auto element : line) {
    std::string elementString(1, element);
    int ID = 0;

    ID = std::stoi(elementString);
    input.push_back(ID);
  }

  return input;
}

void printVector(std::vector<int> nums) {
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
}

int findClosesestDistance(int reihe, int result) {
  int timeSinceBusLeft = result % reihe;
  return reihe - timeSinceBusLeft;
}

int findNextElement(std::vector<int> input, int element) {
  int index = 0;
  while (true) {
    for (int i = 0; i < input.size(); i++) {
      if (element - input[i] == 1 + index) {
        return i;
      }
    }
    index++;
  }
}

std::vector<std::vector<int>> splitVector(std::vector<int> input, int index) {
  std::vector<std::vector<int>> result;
  std::vector<int> one(input.begin(), input.begin() + index + 1);
  std::vector<int> two(input.begin() + index + 1, input.end());
  result.push_back(one);
  result.push_back(two);
  printVector(one);
  printVector(two);
  return result;
}

int main() {
  std::vector<int> input = readInput();

  printVector(input);
  for (int i = 0; i < 100; i++) {
    int elementOne = input[0];
    std::vector<int> elementToMove(input.begin() + 1, input.begin() + 4);
    std::vector<int> elementRest(input.begin() + 4, input.begin() + 9);
    printVector(elementRest);
    int index = findNextElement(elementRest, elementOne);
    std::vector<std::vector<int>> splits = splitVector(elementRest, index);
    break;
  }
  return 0;
}
