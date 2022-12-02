#include <algorithm>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

class Direction {
 public:
  Direction(int dir, int value) {
    dir_ = dir;
    value_ = value;
  }
  void print() {
    std::cout << "Direction: " << dir_ << " Value: " << value_ << std::endl;
  }

  int dir() { return dir_; }
  int value() { return value_; }

 private:
  int dir_;
  int value_;
};

std::vector<Direction> readInput() {
  std::string line;
  std::ifstream myFile("input.txt");
  std::vector<Direction> input = {};
  if (myFile.is_open()) {
    while (getline(myFile, line)) {
      int dir = 0;
      int value = 0;
      int index = 0;
      char element = line[0];
      if (element == 'N') {
        dir = 0;
      } else if (element == 'S') {
        dir = 1;
      } else if (element == 'E') {
        dir = 2;
      } else if (element == 'W') {
        dir = 3;
      } else if (element == 'L') {
        dir = 4;
      } else if (element == 'R') {
        dir = 5;
      } else if (element == 'F') {
        dir = 6;
      }

      std::string substr = line.substr(1, 100);

      value = std::stoi(substr);
      input.push_back(Direction(dir, value));
    }
  }

  else {
    std::cout << "Can not open file!" << std::endl;
  }
  return input;
}

void printVector(std::vector<Direction> nums) {
  for (int i = 0; i < nums.size(); i++) {
    nums[i].print();
  }
}

int main() {
  std::vector<Direction> input = readInput();
  printVector(input);
  // int facing = 0;
  int xShip = 0;
  int yShip = 0;
  int xWaypoint = 10;
  int yWaypoint = 1;
  for (Direction instruction : input) {
    if (instruction.dir() == 0) {
      yWaypoint = yWaypoint + instruction.value();
    } else if (instruction.dir() == 1) {
      yWaypoint = yWaypoint - instruction.value();
    } else if (instruction.dir() == 2) {
      xWaypoint = xWaypoint + instruction.value();
    } else if (instruction.dir() == 3) {
      xWaypoint = xWaypoint - instruction.value();
    } else if (instruction.dir() == 4) {
      int nrRotate = instruction.value() / 90;
      for (int i = 0; i < nrRotate; i++) {
        int xNew = -yWaypoint;
        int yNew = xWaypoint;
        xWaypoint = xNew;
        yWaypoint = yNew;
      }
    } else if (instruction.dir() == 5) {
      int nrRotate = instruction.value() / 90;
      for (int i = 0; i < nrRotate; i++) {
        int xNew = yWaypoint;
        int yNew = -xWaypoint;
        xWaypoint = xNew;
        yWaypoint = yNew;
      }
    } else if (instruction.dir() == 6) {
      xShip = xShip + xWaypoint * instruction.value();
      yShip = yShip + yWaypoint * instruction.value();
      // if (facing == 0) {
      //   x = x + instruction.value();
      // } else if (facing == 90) {
      //   y = y - instruction.value();
      // } else if (facing == 180) {
      //   x = x - instruction.value();
      // } else if (facing == 270) {
      //   y = y + instruction.value();
      // }
    }
    std::cout << "xShip = " << xShip << " | yShip = " << yShip << std::endl;
    std::cout << "xWaypoint = " << xWaypoint << " | yWaypoint = " << yWaypoint
              << std::endl;
  }
  std::cout << "xShip = " << xShip << " | yShip = " << yShip
            << " | distance = " << std::abs(xShip) + std::abs(yShip)
            << std::endl;

  return 0;
}
