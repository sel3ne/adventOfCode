#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

class Password {
 public:
  Password(int num1, int num2, std::string letter, std::string password) {
    num1_ = num1;
    num2_ = num2;
    letter_ = letter;
    password_ = password;
  }

  int num1() { return num1_; }
  int num2() { return num2_; }
  std::string letter() { return letter_; }
  std::string password() { return password_; }

 private:
  int num1_;
  int num2_;
  std::string letter_;
  std::string password_;
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

int find_substring_in_string(std::string substr, std::string str) {
  size_t index = 0;
  int index_size = 1;
  int counter = 0;
  while (true) {
    index = str.find(substr, index);
    if (index == std::string::npos) break;
    counter = counter + 1;
    // str.replace(index, index_size, substr_replace);

    index += index_size;
  }
  return counter;
}

int substring_at_pos_a_b(int a, int b, std::string substr, std::string str) {
  char at_a = str.std::string::at(a - 1);
  std::string at_a_str(1, at_a);
  char at_b = str.std::string::at(b - 1);
  std::string at_b_str(1, at_b);
  if (at_a_str == substr && at_b_str != substr) {
    return 1;
  } else if (at_a_str != substr && at_b_str == substr) {
    return 1;
  }
  return 0;
}

void tokenize(std::string& str, char delim, std::vector<std::string>& out) {
  size_t start;
  size_t end = 0;

  while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
    end = str.find(delim, start);
    out.push_back(str.substr(start, end - start));
  }
}

std::list<Password> readInput() {
  std::string line;
  std::ifstream myfile("input.txt");
  char d = '-';
  std::list<Password> input = {};
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      line = replace_string(line, " ", "-", 1);
      line = replace_string(line, ":-", "-", 2);

      std::vector<std::string> lineAsVector;
      tokenize(line, d, lineAsVector);

      int min = 0;
      int max = 0;
      std::string letter = "";
      std::string password = "";
      int i = 0;
      for (auto element : lineAsVector) {
        if (i == 0) {
          min = std::stoi(element);
        }
        if (i == 1) {
          max = std::stoi(element);
        }
        if (i == 2) {
          letter = element;
        }
        if (i == 3) {
          password = element;
        }
        i = i + 1;
      }
      input.push_back(Password(min, max, letter, password));
    }
    myfile.close();
  }

  else
    std::cout << "Unable to open file";

  return input;
}

int main() {
  std::list<Password> input = readInput();
  int main_counter = 0;
  for (Password& pass : input) {
    // std::cout << pass.letter() << " " << pass.password() << std::endl;
    int counter = substring_at_pos_a_b(pass.num1(), pass.num2(), pass.letter(),
                                       pass.password());
    main_counter = main_counter + counter;
  }
  std::cout << "Main counter: " << main_counter << std::endl;

  return 0;
}
