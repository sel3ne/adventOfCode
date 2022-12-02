#include <algorithm>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

class BusID {
 public:
  BusID(int ID, int time) {
    ID_ = ID;
    time_ = time;
  }
  void print() {
    std::cout << "ID: " << ID_ << " | time difference: " << time_ << std::endl;
  }

  int ID() { return ID_; }
  int time() { return time_; }

 private:
  int ID_;
  int time_;
};

void tokenize(std::string& str, char delim, std::vector<std::string>& out) {
  size_t start;
  size_t end = 0;

  while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
    end = str.find(delim, start);
    out.push_back(str.substr(start, end - start));
  }
}

std::vector<BusID> readInput() {
  std::vector<BusID> input = {};
  std::string line =
      "29,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,41,x,x,x,x,x,x,x,x,x,601,x,x,x,"
      "x,x,x,x,23,x,x,x,x,13,x,x,x,17,x,19,x,x,x,x,x,x,x,x,x,x,x,463,x,x,x,x,x,"
      "x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,37";
  // std::string line = "7,13,x,x,59,x,31,19";
  // std::string line = "17,x,13,19";
  // std::string line = "67,7,59,61";
  // std::string line = "1789,37,47,1889";
  // std::string line = "2,3,7";
  std::vector<std::string> lineAsVector = {};
  tokenize(line, ',', lineAsVector);
  int time = 0;
  for (std::string element : lineAsVector) {
    int ID = 0;
    if (element != "x") {
      ID = std::stoi(element);
      input.push_back(BusID(ID, time));
    }
    time++;
  }

  return input;
}

void printVector(std::vector<BusID> nums) {
  for (int i = 0; i < nums.size(); i++) {
    nums[i].print();
  }
}

int findClosesestDistance(int reihe, int result) {
  int timeSinceBusLeft = result % reihe;
  return reihe - timeSinceBusLeft;
}

int main() {
  std::vector<BusID> input = readInput();

  printVector(input);
  // int64_t result = 100000000000000;
  // int64_t result = 1200000000;
  int64_t result = 1;
  int64_t stepsize = 1;

  for (int i = 0; i < input.size(); i++) {
    while (true) {
      if ((result + input[i].time()) % input[i].ID() == 0) {
        stepsize = stepsize * input[i].ID();
        std::cout << stepsize << std::endl;
        break;
      }
      result = stepsize + result;
    }
  }
  std::cout << "Result " << result << std::endl;

  // int minDistance = timestamp;
  // int result = 0;
  // for (int i = 0; i < input.size(); i++) {
  //   int distance = findClosesestDistance(input[i], timestamp);
  //   std::cout << "distance " << distance << std::endl;
  //   if (minDistance > distance) {
  //     minDistance = distance;
  //     result = minDistance * input[i];
  //   }
  // }
  // std::cout << "Minimale Time to wait " << minDistance << std::endl;
  // std::cout << "Result " << result << std::endl;
  return 0;
}
