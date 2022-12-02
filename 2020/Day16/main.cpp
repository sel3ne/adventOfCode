#include <algorithm>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

class ValidField {
 public:
  ValidField(std::string name, int min1, int max1, int min2, int max2) {
    name_ = name;
    min1_ = min1;
    max1_ = max1;
    min2_ = min2;
    max2_ = max2;
  }

  std::string name() { return name_; }

  void print() {
    std::cout << name_ << ": " << min1_ << "-" << max1_ << " or " << min2_
              << "-" << max2_ << std::endl;
  }

  bool isInside(int element) {
    if (element >= min1_ && element <= max1_) {
      return true;
    }
    if (element >= min2_ && element <= max2_) {
      return true;
    }
    return false;
  }

 private:
  std::string name_;
  int min1_;
  int max1_;
  int min2_;
  int max2_;
};

std::string replace_string(std::string str, std::string substr_find,
                           std::string substr_replace, int index_size) {
  size_t index = 0;
  while (true) {
    index = str.find(substr_find, index);
    if (index == std::string::npos) break;

    str.replace(index, index_size, substr_replace);

    index += index_size;
  }

  return str;
}

void tokenize(std::string& str, char delim, std::vector<std::string>& out) {
  size_t start;
  size_t end = 0;

  while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
    end = str.find(delim, start);
    out.push_back(str.substr(start, end - start));
  }
}

std::list<std::vector<int>> readInput() {
  std::string line;
  std::ifstream myfile("ticket.txt");
  char d = ',';
  std::list<std::vector<int>> input = {};

  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      std::vector<std::string> lineAsVector;
      tokenize(line, d, lineAsVector);
      std::vector<int> lineAsInt = {};
      for (int i = 0; i < lineAsVector.size(); i++) {
        int element = std::stoi(lineAsVector[i]);
        lineAsInt.push_back(element);
      }
      input.push_back(lineAsInt);
    }
    myfile.close();
  }

  else
    std::cout << "Unable to open file!";

  return input;
}

std::vector<ValidField> readRange() {
  std::string line;
  std::ifstream myfile("range.txt");
  char d = ',';
  std::vector<ValidField> input = {};

  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      line = replace_string(line, ": ", ",", 2);
      line = replace_string(line, "-", ",", 1);
      line = replace_string(line, " or ", ",", 4);
      std::vector<std::string> lineAsVector;
      tokenize(line, d, lineAsVector);
      std::string name = lineAsVector[0];
      int min1 = std::stoi(lineAsVector[1]);
      int max1 = std::stoi(lineAsVector[2]);
      int min2 = std::stoi(lineAsVector[3]);
      int max2 = std::stoi(lineAsVector[4]);
      input.push_back(ValidField(name, min1, max1, min2, max2));
    }
    myfile.close();
  }

  else
    std::cout << "Unable to open file";

  return input;
}

void printVector(std::list<std::vector<int>> nums) {
  for (auto line : nums) {
    for (int j = 0; j < line.size(); j++) {
      std::cout << line[j] << " ";
    }
    std::cout << std::endl;
  }
}

void printVector(std::vector<ValidField> nums) {
  for (int i = 0; i < nums.size(); i++) {
    nums[i].print();
  }
}

void printVector(const std::vector<std::vector<std::string>>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < nums[i].size(); j++) {
      std::cout << nums[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void printVector(const std::vector<std::list<std::string>>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    for (auto element : nums[i]) {
      std::cout << element << " ";
    }
    std::cout << std::endl;
  }
}

void printVector(const std::vector<std::string>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << " : " << i;

    std::cout << std::endl;
  }
}

int findSizeOne(const std::vector<std::list<std::string>>& result) {
  for (int i = 0; i < result.size(); i++) {
    if (result[i].size() == 1) {
      return i;
    }
  }
  return -1;
}

void deleteStringInInput(std::vector<std::list<std::string>>& input,
                         std::string name,
                         std::vector<std::string>& oneElementResult) {
  std::string elementToRemove;
  for (int i = 0; i < input.size(); i++) {
    if (input[i].size() == 1) {
      elementToRemove = input[i].front();
      oneElementResult[i] = elementToRemove;
      break;
    }
  }
  for (int i = 0; i < input.size(); i++) {
    input[i].remove(elementToRemove);
  }
}

int main() {
  std::list<std::vector<int>> input = readInput();
  std::vector<ValidField> range = readRange();

  int counter = 0;
  // printVector(range);
  std::vector<int> wrongFields = {};
  std::vector<std::vector<int>> wrongLine = {};
  for (auto line : input) {
    for (int j = 0; j < line.size(); j++) {
      int element = line[j];
      bool neverInside = false;
      for (int k = 0; k < range.size(); k++) {
        neverInside = neverInside || range[k].isInside(element);
      }
      if (!neverInside) {
        wrongFields.push_back(element);
        wrongLine.push_back(line);
        counter = counter + element;
      }
    }
  }

  for (int i = 0; i < wrongLine.size(); i++) {
    input.remove(wrongLine[i]);
  }

  int fields = 20;
  // int fields = 3;
  // printVector(input);
  std::vector<std::list<std::string>> result(fields);

  for (int k = 0; k < range.size(); k++) {
    // std::cout << "----" << std::endl;
    // std::cout << range[k].name() << std::endl;

    for (int j = 0; j < fields; j++) {
      // std::cout << "checking column: " << j << std::endl;
      bool allInside = true;
      for (auto line : input) {
        allInside = allInside && range[k].isInside(line[j]);
      }
      if (allInside) {
        std::cout << range[k].name() << std::endl;
        result[j].push_back(range[k].name());
      }
    }
  }

  printVector(result);
  std::cout << "counter: " << counter << std::endl;
  std::vector<std::string> oneElementResult(fields);

  while (true) {
    std::cout << "---------" << std::endl;
    int sizeOneIndex = findSizeOne(result);
    if (sizeOneIndex == -1) {
      break;
    }
    std::string toDelet = result[sizeOneIndex].front();
    std::cout << "To delete: " << toDelet << std::endl;
    deleteStringInInput(result, toDelet, oneElementResult);
    // printVector(result);
    // std::cout << "========" << std::endl;
    // printVector(oneElementResult);
  }
  printVector(oneElementResult);

  std::vector<int> yourTicket = {131, 67,  137, 61,  149, 107, 109,
                                 79,  71,  127, 173, 157, 167, 139,
                                 151, 163, 59,  53,  113, 73};

  std::vector<int> departuer = {0, 1, 3, 7, 8, 14};

  int64_t resultCounter = 1;
  for (int i = 0; i < departuer.size(); i++) {
    resultCounter = resultCounter * yourTicket[departuer[i]];
  }
  std::cout << "resultCounter: " << resultCounter << std::endl;
  return 0;
}
