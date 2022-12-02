#include <fstream>
#include <iostream>
#include <vector>

std::vector<int> readInput() {
  std::string line;
  std::ifstream myfile("input.txt");
  std::vector<int> input = {};
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
  std::vector<int> input = readInput();
  int counter = 0;

  for (std::vector<int>::size_type i = 3; i != input.size(); i++) {
    int windowCounterOld = input[i - 1] + input[i - 2] + input[i - 3];
    int windowCounterNew = input[i] + input[i - 1] + input[i - 2];
    if (windowCounterNew > windowCounterOld) {
      counter++;
    }
  }

  std::cout << counter << std::endl;
  return 0;
}
