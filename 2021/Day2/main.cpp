#include <fstream>
#include <iostream>
#include <vector>

std::vector<std::string> readInput() {
  std::string line;
  std::ifstream myfile("input.txt");
  std::vector<std::string> input = {};
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      input.push_back(line);
    }
    myfile.close();
  }

  else
    std::cout << "Unable to open file";

  return input;
}

int main() {
  std::vector<std::string> input = readInput();
  int horizontal = 0;
  int depth = 0;
  int aim = 0;

  for (std::vector<std::string>::iterator it = input.begin(); it != input.end();
       ++it) {
    if (it->front() == 'f') {
      horizontal = horizontal + std::stoi(&it->back());
      depth = depth + aim * std::stoi(&it->back());

    } else if (it->front() == 'd') {
      aim = aim + std::stoi(&it->back());
    } else if (it->front() == 'u') {
      aim = aim - std::stoi(&it->back());
    }
  }
  std::cout << horizontal << " " << depth << std::endl;
  std::cout << horizontal * depth << std::endl;

  return 0;
}
