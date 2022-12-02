#include <fstream>
#include <iostream>
#include <vector>

std::vector<std::string> readInput() {
  std::string line;
  std::ifstream myfile("input.txt");  // to change
  std::vector<std::string> input = {};
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      input.push_back(line);
    }
    myfile.close();

  } else
    std::cout << "Unable to open file";

  return input;
}

void print_vector(std::vector<int> v) {
  std::cout << "[ ";
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << " ]" << std::endl;
}

void print_vector(std::vector<std::string> v) {
  std::cout << "[ ";
  for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << " ]" << std::endl;
}

std::string co2() {
  std::vector<std::string> input = readInput();
  int length = 12;                       // to change
  std::vector<int> stillvalid(1000, 1);  // to change

  for (int i = 0; i < length; i++) {
    int ones = 0;
    int zeros = 0;
    int index = 0;
    int sum_of_elems = 0;
    for (auto& n : stillvalid) sum_of_elems += n;

    if (sum_of_elems == 1) {
      break;
    }

    for (std::vector<std::string>::iterator it = input.begin();
         it != input.end(); ++it) {
      if (stillvalid.at(index) == 0) {
        index++;
        continue;
      }
      index++;
      if (it->at(i) == '0') {
        zeros++;
      } else if (it->at(i) == '1') {
        ones++;
      }
    }
    if (ones < zeros) {
      int nr_row = 0;
      for (std::vector<std::string>::iterator it = input.begin();
           it != input.end(); ++it) {
        if (it->at(i) == '0') {
          stillvalid.at(nr_row) = 0;
        }
        nr_row++;
      }

    } else {
      int nr_row = 0;
      for (std::vector<std::string>::iterator it = input.begin();
           it != input.end(); ++it) {
        if (it->at(i) == '1') {
          stillvalid.at(nr_row) = 0;
        }
        nr_row++;
      }
    }
  }

  int nr_row = 0;
  for (auto& n : input) {
    if (stillvalid.at(nr_row) == 1) {
      std::cout << n << std::endl;
      return n;
    }
    nr_row++;
  }

  return 0;
}

std::string oxy() {
  std::vector<std::string> input = readInput();
  int length = 12;                       // to change
  std::vector<int> stillvalid(1000, 1);  // to change

  for (int i = 0; i < length; i++) {
    int ones = 0;
    int zeros = 0;
    int index = 0;
    for (std::vector<std::string>::iterator it = input.begin();
         it != input.end(); ++it) {
      int sum_of_elems = 0;
      for (auto& n : stillvalid) sum_of_elems += n;

      if (sum_of_elems == 1) {
        break;
      }

      if (stillvalid.at(index) == 0) {
        index++;
        continue;
      }
      index++;
      if (it->at(i) == '0') {
        zeros++;
      } else if (it->at(i) == '1') {
        ones++;
      }
    }
    if (ones >= zeros) {
      int nr_row = 0;
      for (std::vector<std::string>::iterator it = input.begin();
           it != input.end(); ++it) {
        if (it->at(i) == '0') {
          stillvalid.at(nr_row) = 0;
        }
        nr_row++;
      }

    } else {
      int nr_row = 0;
      for (std::vector<std::string>::iterator it = input.begin();
           it != input.end(); ++it) {
        if (it->at(i) == '1') {
          stillvalid.at(nr_row) = 0;
        }
        nr_row++;
      }
    }
  }

  int nr_row = 0;
  for (auto& n : input) {
    if (stillvalid.at(nr_row) == 1) {
      return n;
    }
    nr_row++;
  }

  return 0;
}

int main() {
  std::string oxy_string = oxy();
  std::string co2_string = co2();
  std::cout << oxy_string << std::endl;
  std::cout << co2_string << std::endl;
  int length = 12;  // to change
  int oxygen = 0;
  int carbo2 = 0;
  for (char& i : oxy_string) {
    oxygen = oxygen | ((i - '0') << (length - 1));
    length--;
  }
  length = 12;
  for (char& i : co2_string) {
    carbo2 = carbo2 | ((i - '0') << (length - 1));
    length--;
  }

  std::cout << oxygen << std::endl;
  std::cout << carbo2 << std::endl;

  std::cout << carbo2 * oxygen << std::endl;
  return 0;
}
