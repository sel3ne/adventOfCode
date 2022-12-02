#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

int convertBinaryToDecimal(int n) {
  int decimalNumber = 0, i = 0, remainder;
  while (n != 0) {
    remainder = n % 10;
    n /= 10;
    decimalNumber += remainder * pow(2, i);
    ++i;
  }
  return decimalNumber;
}

class Seat {
 public:
  Seat(std::string column, std::string row) {
    column_ = column;
    row_ = row;
    columnBin_ = std::stoi(column_);
    rowBin_ = std::stoi(row_);
    columnDec_ = convertBinaryToDecimal(columnBin_);
    rowDec_ = convertBinaryToDecimal(rowBin_);
  }
  int id() { return columnDec_ * 8 + rowDec_; }
  void print() {
    std::cout << "column " + column_ << " :" << columnBin_ << " " << columnDec_
              << std::endl;
    std::cout << "row " + row_ << " :" << rowBin_ << " " << rowDec_
              << std::endl;
  }

 private:
  std::string column_;
  std::string row_;
  int columnBin_;
  int columnDec_;
  int rowBin_;
  int rowDec_;
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

std::list<Seat> readInput() {
  std::string line;
  std::ifstream myfile("input.txt");
  // char d = '-';
  std::list<Seat> input = {};
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      std::string column = line.substr(0, 7);
      std::string row = line.substr(7, 9);
      column = replace_string(column, "F", "0", 1);
      column = replace_string(column, "B", "1", 1);
      row = replace_string(row, "L", "0", 1);
      row = replace_string(row, "R", "1", 1);
      Seat seat(column, row);

      input.push_back(seat);
    }
    myfile.close();
  } else
    std::cout << "Unable to open file";

  return input;
}

int main() {
  std::list<Seat> input = readInput();
  int maxId = 0;
  std::vector<int> seatId = {};
  for (auto seat : input) {
    seatId.push_back(seat.id());
    if (maxId < seat.id()) {
      maxId = seat.id();
    }
  }
  std::sort(seatId.begin(), seatId.end());

  for (std::vector<int>::iterator it = seatId.begin() + 1; it != seatId.end();
       it++) {
    if (*(it) - *(it - 1) != 1) {
      std::cout << "----" << std::endl;
      std::cout << "pre " << *(it - 1) << std::endl;
      std::cout << "post " << *(it) << std::endl;
    }
  }
  std::cout << "max ID " << maxId << std::endl;

  return 0;
}
