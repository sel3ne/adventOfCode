#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

class Opera {
 public:
  Opera(int type, int value) {
    type_ = type;
    value_ = value;
    beenThere_ = false;
  }

  void print() { std::cout << type_ << " " << value_ << std::endl; }
  int type() { return type_; }
  int value() { return value_; }
  bool beenThere() { return beenThere_; }
  void haveBeenThere() { beenThere_ = true; }
  void changeType(int newType) { type_ = newType; }

 private:
  int type_;
  int value_;
  bool beenThere_;
};

void tokenize(std::string& str, char delim, std::vector<std::string>& out) {
  size_t start;
  size_t end = 0;

  while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
    end = str.find(delim, start);
    out.push_back(str.substr(start, end - start));
  }
}

std::vector<Opera> readInput() {
  std::string line;
  std::ifstream myFile("input.txt");
  std::vector<Opera> input = {};
  if (myFile.is_open()) {
    int type = 0;
    int value = 0;
    while (getline(myFile, line)) {
      std::vector<std::string> lineAsVector;
      tokenize(line, ' ', lineAsVector);
      int i = 0;
      for (auto element : lineAsVector) {
        if (i == 0) {
          if (element == "acc") {
            type = 0;
          } else if (element == "jmp") {
            type = 1;
          } else if (element == "nop") {
            type = 2;
          }
        }
        if (i == 1) {
          value = std::stoi(element);
        }
        i = i + 1;
      }
      input.push_back(Opera(type, value));
      type = 0;
      value = 0;
    }
  } else {
    std::cout << "Can not open file!" << std::endl;
  }
  return input;
}

int main() {
  std::vector<Opera> input = readInput();

  for (int bruteforce = 0; bruteforce < input.size(); bruteforce++) {
    int counter = 0;
    int index = 0;
    std::vector<Opera> changed_input = input;
    if (input[bruteforce].type() == 1) {
      changed_input[bruteforce].changeType(2);
    } else if (input[bruteforce].type() == 2) {
      changed_input[bruteforce].changeType(1);
    }

    while (true) {
      if (index >= changed_input.size()) {
        std::cout << "Final Counter " << counter << std::endl;
        break;
      }
      Opera& operation = changed_input[index];
      if (operation.beenThere()) {
        // std::cout << "Wrong Counter " << counter << std::endl;
        break;
      }
      if (operation.type() == 0) {
        counter = counter + operation.value();
        index = index + 1;
        operation.haveBeenThere();
      } else if (operation.type() == 1) {
        index = index + operation.value();
        operation.haveBeenThere();
      } else if (operation.type() == 2) {
        index = index + 1;
        operation.haveBeenThere();
      }
    }
  }
  // std::cout << "Counter " << counter << std::endl;
  return 0;
}
