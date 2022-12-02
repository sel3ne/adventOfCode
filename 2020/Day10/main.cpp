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
  std::string line;
  std::ifstream myFile("input.txt");
  std::vector<int> input = {};
  if (myFile.is_open()) {
    while (getline(myFile, line)) {
      input.push_back(std::stoi(line));
    }
  } else {
    std::cout << "Can not open file!" << std::endl;
  }
  return input;
}

void printVector(std::vector<int> nums) {
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << std::endl;
  }
}

int main() {
  std::vector<int> input = readInput();
  std::sort(input.begin(), input.end());
  printVector(input);
  std::vector<int> result = {};
  int counterOne = 1;
  int counterThree = 0;
  result.push_back(1);
  for (int i = 0; i < input.size() - 1; i++) {
    int diff = input[i + 1] - input[i];

    result.push_back(diff);
    if (diff == 1) {
      counterOne++;
    } else if (diff == 3) {
      counterThree++;
    } else if (diff == 2) {
    }
  }
  result.push_back(3);
  counterThree++;
  std::vector<int> countOnes = {};
  int counter = 0;
  for (int i = 0; i < result.size(); i++) {
    if (result[i] == 1) {
      counter++;
    } else if (result[i] == 3) {
      countOnes.push_back(counter);
      counter = 0;
    }
  }
  countOnes.push_back(counter);
  std::cout << "____" << std::endl;
  printVector(countOnes);
  int64_t masterResult = 1;
  for (int i = 0; i < countOnes.size(); i++) {
    if (countOnes[i] == 0) {
      masterResult = masterResult * 1;
    } else if (countOnes[i] == 1) {
      masterResult = masterResult * 1;
    } else if (countOnes[i] == 2) {
      masterResult = masterResult * 2;
    } else if (countOnes[i] == 3) {
      masterResult = masterResult * 4;
    } else if (countOnes[i] == 4) {
      masterResult = masterResult * 7;
    }
  }

  std::cout << "Master Resul: " << masterResult << std::endl;
  // printVector(countOnes);
  // std::cout << "one * three = " << counterOne << " * " << counterThree << "
  // =
  // "
  //           << counterOne * counterThree;

  return 0;
}
