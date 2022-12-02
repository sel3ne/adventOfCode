#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

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

std::list<std::list<int>> readInput() {
  std::string line;
  std::ifstream myfile("input.txt");
  // char d = '-';
  std::list<std::list<int>> input = {};
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      line = replace_string(line, "#", "1", 1);
      line = replace_string(line, ".", "0", 1);

      std::list<int> lineAsList = {};
      int elmenet = 0;
      std::string letter = "";
      for (char& c : line) {
        std::string letter(1, c);
        elmenet = std::stoi(letter);
        lineAsList.push_back(elmenet);
      }
      input.push_back(lineAsList);
    }
    myfile.close();
  } else
    std::cout << "Unable to open file";

  return input;
}

int trees_hit(int right, int down) {
  std::list<std::list<int>> input = readInput();
  int counter = 0;
  int column = 0;
  bool toggle = true;
  for (std::list<std::list<int>>::iterator it = input.begin();
       it != input.end(); it++) {
    if (toggle == true) {
      std::list<int> line = *it;
      // for (int& i : line) {
      //   std::cout << i;
      // }
      // std::cout << std::endl;

      std::list<int>::iterator it2 = line.begin();
      std::advance(it2, column);
      counter = counter + *it2;
      // std::cout << *it2 << std::endl;
      // std::cout << column << std::endl;
      column = column + right;
      column = column % line.size();
      if (down == 2) {
        toggle = false;
      }
    } else {
      toggle = true;
    }
  }
  std::cout << "counter: " << counter << std::endl;
  return counter;
}

int main() {
  int one = trees_hit(1, 1);
  int two = trees_hit(3, 1);
  int three = trees_hit(5, 1);
  int four = trees_hit(7, 1);
  int five = trees_hit(1, 2);
  std::cout << "Multiplied counter: " << one * two * three * four * five
            << std::endl;

  // std::list<std::list<int>> input = readInput();
  // int counter = 0;
  // int column = 0;
  // for (std::list<std::list<int>>::iterator it = input.begin();
  //      it != input.end(); it++) {
  //   std::list<int> line = *it;
  //   // for (int& i : line) {
  //   //   std::cout << i;
  //   // }
  //   // std::cout << std::endl;

  //   std::list<int>::iterator it2 = line.begin();
  //   std::advance(it2, column);
  //   counter = counter + *it2;
  //   // std::cout << *it2 << std::endl;
  //   // std::cout << column << std::endl;
  //   column = column + 3;
  //   column = column % line.size();
  // }
  // std::cout << "counter: " << counter << std::endl;
  return 0;
}
