#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

#include "absl/strings/str_split.h"

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

void printVector(std::vector<string> v) {
  for (string element : v) {
    cout << element << ", ";
  }
  cout << endl;
}

class Line {
 public:
  Line(std::string oneLine) {
    std::vector<string> v = absl::StrSplit(oneLine, absl::ByAnyChar("|"));
    input = absl::StrSplit(v[0], absl::ByAnyChar(" "));
    output = absl::StrSplit(v[1], absl::ByAnyChar(" "));
    oneLine_ = absl::StrSplit(oneLine, absl::ByAnyChar("| "));
  }

  void print() {
    for (string element : input) {
      cout << element << " ";
    }
    cout << " || ";
    for (string element : output) {
      cout << element << " ";
    }
    cout << endl;
  }

  int countEasyOutputs() {
    int counter = 0;
    for (string element : output) {
      if (element.size() == 2 || element.size() == 4 || element.size() == 3 ||
          element.size() == 7) {
        counter++;
      }
    }
    return counter;
  }

  void find() {
    findA();
    findF();
    findC();
    findB();
    findE();
    findD();
    findG();
  }

  char findNumber(string element) {
    if (isZero(element)) return '0';
    if (isOne(element)) return '1';
    if (isTwo(element)) return '2';
    if (isThree(element)) return '3';
    if (isFour(element)) return '4';
    if (isFive(element)) return '5';
    if (isSix(element)) return '6';
    if (isSeven(element)) return '7';
    if (isEigth(element)) return '8';
    if (isNine(element)) return '9';
    return 'a';
  }

  int outputAsNumber() {
    string result;
    for (string element : output) {
      result.push_back(findNumber(element));
    }
    return stoi(result);
  }

 private:
  std::vector<string> input;
  std::vector<string> output;
  std::vector<string> oneLine_;
  char a_;
  char b_;
  char c_;
  char d_;
  char e_;
  char f_;
  char g_;
  size_t foundA;
  size_t foundB;
  size_t foundC;
  size_t foundD;
  size_t foundE;
  size_t foundF;
  size_t foundG;

  void init(string element) {
    foundA = element.find(a_);
    foundB = element.find(b_);
    foundC = element.find(c_);
    foundD = element.find(d_);
    foundE = element.find(e_);
    foundF = element.find(f_);
    foundG = element.find(g_);
  }

  bool isZero(string element) {
    init(element);
    if (foundA != string::npos && foundB != string::npos &&
        foundC != string::npos && foundD == string::npos &&
        foundE != string::npos && foundF != string::npos &&
        foundG != string::npos) {
      return true;
    }
    return false;
  }

  bool isOne(string element) {
    if (element.size() == 2) return true;
    return false;
  }

  bool isTwo(string element) {
    init(element);
    if (foundA != string::npos && foundB == string::npos &&
        foundC != string::npos && foundD != string::npos &&
        foundE != string::npos && foundF == string::npos &&
        foundG != string::npos) {
      return true;
    }
    return false;
  }

  bool isThree(string element) {
    init(element);
    if (foundA != string::npos && foundB == string::npos &&
        foundC != string::npos && foundD != string::npos &&
        foundE == string::npos && foundF != string::npos &&
        foundG != string::npos) {
      return true;
    }
    return false;
  }

  bool isFour(string element) {
    if (element.size() == 4) return true;
    return false;
  }

  bool isFive(string element) {
    init(element);
    if (foundA != string::npos && foundB != string::npos &&
        foundC == string::npos && foundD != string::npos &&
        foundE == string::npos && foundF != string::npos &&
        foundG != string::npos) {
      return true;
    }
    return false;
  }

  bool isSix(string element) {
    init(element);
    ;
    if (foundA != string::npos && foundB != string::npos &&
        foundC == string::npos && foundD != string::npos &&
        foundE != string::npos && foundF != string::npos &&
        foundG != string::npos) {
      return true;
    }
    return false;
  }

  bool isSeven(string element) {
    if (element.size() == 3) return true;
    return false;
  }

  bool isEigth(string element) {
    if (element.size() == 7) return true;
    return false;
  }

  bool isNine(string element) {
    init(element);
    if (foundA != string::npos && foundB != string::npos &&
        foundC != string::npos && foundD != string::npos &&
        foundE == string::npos && foundF != string::npos &&
        foundG != string::npos) {
      return true;
    }
    return false;
  }

  void findG() {
    string eight;
    for (string element : input) {
      if (element.size() == 7) {
        eight = element;
      }
    }
    for (char character : eight) {
      if (character != a_ && character != b_ && character != c_ &&
          character != d_ && character != e_ && character != f_) {
        g_ = character;
      }
    }
    // cout << "g_ = " << g_ << endl;
  }

  void findD() {
    string four;
    for (string element : input) {
      if (element.size() == 4) {
        four = element;
      }
    }
    for (char character : four) {
      if (character != b_ && character != c_ && character != f_) {
        d_ = character;
      }
    }
    // cout << "d_ = " << d_ << endl;
  }

  void findE() {
    string eight;
    for (string element : input) {
      if (element.size() == 7) {
        eight = element;
      }
    }
    for (char character : eight) {
      int counter = 0;
      for (string number : input) {
        size_t found = number.find(character);
        if (found != string::npos) {
          counter++;
        }
      }
      if (counter == 4) {
        e_ = character;
      }
    }
    // cout << "e_ = " << e_ << endl;
  }

  void findB() {
    string eight;
    for (string element : input) {
      if (element.size() == 7) {
        eight = element;
      }
    }
    for (char character : eight) {
      int counter = 0;
      for (string number : input) {
        size_t found = number.find(character);
        if (found != string::npos) {
          counter++;
        }
      }
      if (counter == 6) {
        b_ = character;
      }
    }
    // cout << "b_ = " << b_ << endl;
  }

  void findC() {
    string one;
    for (string element : input) {
      if (element.size() == 2) {
        one = element;
      }
    }

    for (char character : one) {
      if (character != f_) {
        c_ = character;
      }
    }

    // cout << "c_ = " << c_ << endl;
  }

  void findF() {
    string eight;
    for (string element : input) {
      if (element.size() == 7) {
        eight = element;
      }
    }

    for (char character : eight) {
      int counter = 0;
      for (string number : input) {
        size_t found = number.find(character);
        if (found != string::npos) {
          counter++;
        }
      }
      if (counter == 9) {
        f_ = character;
      }
    }
    // cout << "f_ = " << f_ << endl;
  }

  void findA() {
    string one;
    string seven;
    for (string element : input) {
      if (element.size() == 2) {
        one = element;
      } else if (element.size() == 3) {
        seven = element;
      }
    }
    for (char element : seven) {
      size_t found = one.find(element);
      if (found == string::npos) {
        a_ = element;
      }
    }
    // cout << "a_ = " << a_ << endl;
  }
};

int main() {
  std::vector<std::string> input = readInput();

  std::vector<Line> lines;
  for (string inputLine : input) {
    lines.push_back(inputLine);
  }

  int totalCounter = 0;
  for (Line line : lines) {
    totalCounter = totalCounter + line.countEasyOutputs();
  }
  cout << totalCounter << endl;

  int total = 0;
  for (Line line : lines) {
    line.find();
    total = total + line.outputAsNumber();
  }
  cout << total << endl;

  return 0;
}
