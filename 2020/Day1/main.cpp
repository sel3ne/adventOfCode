#include <fstream>
#include <iostream>
#include <list>

std::list<int> readInput() {
  std::string line;
  std::ifstream myfile("input.txt");
  char d = '_';
  std::list<int> input = {};
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      input.push_back(std::stoi(line));
    }
    myfile.close();
  }

  else
    std::cout << "Unable to open file";

  return input;
}

int main() {
  std::list<int> input = readInput();
  int index = 0;

  for (int& num : input) {
    for (int& num2 : input) {
      for (int& num3 : input) {
        if (num + num2 + num3 == 2020) {
          std::cout << num << " * " << num2 << " * " << num3 << " = "
                    << num * num2 * num3 << std::endl;
        }
      }
    }
  }

  return 0;
}
