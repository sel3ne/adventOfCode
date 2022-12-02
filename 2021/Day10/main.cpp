#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

std::vector<std::string> readInput() {
  std::string line;
  std::ifstream myfile("input.txt");  // change
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

class KlammerLinie {
 public:
  KlammerLinie(string inputLine) {
    for (char element : inputLine) {
      klammer_.push_back(element);
    }
    validation_ = 0;
    validate();
  }

  int score() {
    if (validation_ == 2) {
      if (klammer_[illegalChar_] == ')') return 3;
      if (klammer_[illegalChar_] == ']') return 57;
      if (klammer_[illegalChar_] == '}') return 1197;
      if (klammer_[illegalChar_] == '>') return 25137;
    }
    return 0;
  }

  int getValidate() { return validation_; }

  long completion() {
    if (validation_ != 1) return 0;
    long sum = 0;
    while (stack.size() != 0) {
      if (stack.back() == '(') {
        sum = sum * 5 + 1;
        stack.pop_back();
      } else if (stack.back() == '[') {
        sum = sum * 5 + 2;
        stack.pop_back();
      } else if (stack.back() == '{') {
        sum = sum * 5 + 3;
        stack.pop_back();
      } else if (stack.back() == '<') {
        sum = sum * 5 + 4;
        stack.pop_back();
      }
    }
    return sum;
  }

 private:
  std::vector<char> klammer_;
  // 0 valide
  // 1 incomplete
  // 2 corrupted
  int validation_;
  int illegalChar_;
  std::vector<char> stack;

  void printVector(std::vector<char> v) {
    for (char element : v) {
      cout << element << " ";
    }
    cout << endl;
  }

  void validate() {
    // std::vector<char> stack;
    int indexOf = 0;
    for (char element : klammer_) {
      if (element == '<' || element == '(' || element == '[' || element == '{')
        stack.push_back(element);
      else {
        if (stack.size() == 0) {
          validation_ = 2;
        } else {
          char matching = stack.back();
          if (element == ')') {
            if (matching == '(')
              stack.pop_back();
            else {
              illegalChar_ = indexOf;
              validation_ = 2;
              break;
            }
          }
          if (element == '>') {
            if (matching == '<')
              stack.pop_back();
            else {
              illegalChar_ = indexOf;
              validation_ = 2;
              break;
            }
          }
          if (element == ']') {
            if (matching == '[')
              stack.pop_back();
            else {
              illegalChar_ = indexOf;
              validation_ = 2;
              break;
            }
          }
          if (element == '}') {
            if (matching == '{')
              stack.pop_back();
            else {
              illegalChar_ = indexOf;
              validation_ = 2;
              break;
            }
          }
        }
      }
      indexOf++;
    }
    if (validation_ != 2) {
      if (stack.size() == 0)
        validation_ = 0;
      else {
        validation_ = 1;
      }
    }
  }
};

int main() {
  std::vector<std::string> input = readInput();

  std::vector<KlammerLinie> klammern;
  for (string line : input) {
    klammern.push_back(KlammerLinie(line));
  }

  int sum = 0;
  for (KlammerLinie linie : klammern) {
    if (linie.getValidate() == 2) {
      sum = sum + linie.score();
    }
  }

  cout << "Part 1 " << sum << endl;

  std::vector<long> completionScore;

  for (KlammerLinie linie : klammern) {
    if (linie.getValidate() == 1) {
      completionScore.push_back(linie.completion());
    }
  }

  size_t n = completionScore.size() / 2;
  std::nth_element(completionScore.begin(), completionScore.begin() + n,
                   completionScore.end());

  long median = completionScore[n];

  cout << "Part 2 " << median << endl;

  return 0;
}
