#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

std::list<std::unordered_map<char, int>> readInput() {
  std::string line;
  std::ifstream myFile("input.txt");
  std::list<std::unordered_map<char, int>> input;
  if (myFile.is_open()) {
    input.emplace_back();
    std::unordered_map<char, int>* onePerson = &input.back();
    while (getline(myFile, line)) {
      if (line.empty()) {
        input.emplace_back();
        onePerson = &input.back();
      } else {
        for (auto element : line) {
          (*onePerson)[element] += 1;
        }
      }
    }
  } else {
    std::cout << "Can not open file!" << std::endl;
  }
  return input;
}

std::vector<int> numberOfPersonPerScetor() {
  std::string line;
  std::ifstream myFile("input.txt");
  std::vector<int> input;
  if (myFile.is_open()) {
    int counter = 0;
    while (getline(myFile, line)) {
      if (line.empty()) {
        input.push_back(counter);
        counter = 0;
      } else {
        counter++;
      }
    }
    input.push_back(counter);
  } else {
    std::cout << "Can not open file!" << std::endl;
  }
  return input;
}

int main() {
  std::list<std::unordered_map<char, int>> input = readInput();
  std::vector<int> numberOfPerson = numberOfPersonPerScetor();

  int counter = 0;
  int index = 0;
  for (auto& oneSector : input) {
    int number = numberOfPerson[index];
    for (auto& [key, value] : oneSector) {
      if (value == number) {
        counter++;
      }
    }
    index++;
  }

  std::cout << "Counter " << counter << std::endl;
  return 0;
}
