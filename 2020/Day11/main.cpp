#include <algorithm>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
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

std::vector<int> add0Line(int size) {
  std::vector<int> result = {};
  for (int i = 0; i < size; i++) {
    result.push_back(0);
  }
  return result;
}

std::vector<std::vector<int>> readInput() {
  std::string line;
  std::ifstream myFile("input.txt");
  int size = 95;
  // int size = 12;
  std::vector<std::vector<int>> input = {};
  if (myFile.is_open()) {
    input.push_back(add0Line(size));
    while (getline(myFile, line)) {
      std::vector<int> lineAsVector = {};
      lineAsVector.push_back(0);
      line = replace_string(line, ".", "0", 1);
      line = replace_string(line, "L", "1", 1);
      for (char element : line) {
        std::string elementAsString(1, element);
        lineAsVector.push_back(std::stoi(elementAsString));
      }
      lineAsVector.push_back(0);
      input.push_back(lineAsVector);
    }
    input.push_back(add0Line(size));
  }

  else {
    std::cout << "Can not open file!" << std::endl;
  }
  return input;
}

void printVector(std::vector<std::vector<int>> nums) {
  for (int i = 0; i < nums.size(); i++) {
    std::vector<int> oneLine = nums[i];
    for (int j = 0; j < oneLine.size(); j++) {
      std::cout << oneLine[j] << " ";
    }
    std::cout << std::endl;
  }
}

int countOccupied(int i, int j, const std::vector<std::vector<int>>& input) {
  int counterOccupied = 0;
  int n = 1;

  while (true) {
    if (input[i][j - n] == 0) {
      // continue;
    }
    if (input[i][j - n] == 1) {
      break;
    }
    if (input[i][j - n] == 2) {
      counterOccupied++;
      break;
    }
    if (j - n == 0) {
      break;
    }
    n++;
  }
  n = 1;
  while (true) {
    if (input[i][j + n] == 0) {
      // continue;
    } else if (input[i][j + n] == 1) {
      break;
    } else if (input[i][j + n] == 2) {
      counterOccupied++;
      break;
    }
    if (j + n == input[i].size() - 1) {
      break;
    }
    n++;
  }
  n = 1;
  while (true) {
    if (input[i - n][j] == 0) {
      // continue;
    } else if (input[i - n][j] == 1) {
      break;
    } else if (input[i - n][j] == 2) {
      counterOccupied++;
      break;
    }
    if (i - n == 0) {
      break;
    }
    n++;
  }
  n = 1;
  while (true) {
    if (input[i + n][j] == 0) {
      // continue;
    } else if (input[i + n][j] == 1) {
      break;
    } else if (input[i + n][j] == 2) {
      counterOccupied++;
      break;
    }
    if (i + n == input.size() - 1) {
      break;
    }
    n++;
  }
  n = 1;
  while (true) {
    if (input[i + n][j + n] == 0) {
      // continue;
    } else if (input[i + n][j + n] == 1) {
      break;
    } else if (input[i + n][j + n] == 2) {
      counterOccupied++;
      break;
    }
    if (i + n == input.size() - 1) {
      break;
    }
    if (j + n == input[i].size() - 1) {
      break;
    }
    n++;
  }
  n = 1;
  while (true) {
    if (input[i - n][j + n] == 0) {
      // continue;
    } else if (input[i - n][j + n] == 1) {
      break;
    } else if (input[i - n][j + n] == 2) {
      counterOccupied++;
      break;
    }
    if (i - n == 0) {
      break;
    }
    if (j + n == input[i].size() - 1) {
      break;
    }
    n++;
  }
  n = 1;
  while (true) {
    if (input[i - n][j - n] == 0) {
      // continue;
    } else if (input[i - n][j - n] == 1) {
      break;
    } else if (input[i - n][j - n] == 2) {
      counterOccupied++;
      break;
    }
    if (i - n == 0) {
      break;
    }
    if (j - n == 0) {
      break;
    }
    n++;
  }
  n = 1;
  while (true) {
    if (input[i + n][j - n] == 0) {
      // continue;
    } else if (input[i + n][j - n] == 1) {
      break;
    } else if (input[i + n][j - n] == 2) {
      counterOccupied++;
      break;
    }
    if (i + n == input.size() - 1) {
      break;
    }
    if (j - n == 0) {
      break;
    }
    n++;
  }

  return counterOccupied;
}

int emptySeat(int i, int j, const std::vector<std::vector<int>>& input) {
  if (input[i][j] == 0) {
    return 0;
  }
  int occuipiedSeat = countOccupied(i, j, input);
  if (occuipiedSeat == 0 && input[i][j] == 1) {
    return 2;
  } else if (occuipiedSeat >= 5 && input[i][j] == 2) {
    return 1;
  }
  return input[i][j];
}

std::vector<std::vector<int>> roundOne(
    const std::vector<std::vector<int>>& input) {
  std::vector<std::vector<int>> temp = input;
  for (int i = 1; i < input.size() - 1; i++) {
    for (int j = 1; j < input[i].size() - 1; j++) {
      temp[i][j] = emptySeat(i, j, input);
    }
  }
  return temp;
}

int countOccupiedSeats(const std::vector<std::vector<int>>& input) {
  int counter = 0;
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[i].size(); j++) {
      if (input[i][j] == 2) {
        counter++;
      }
    }
  }
  return counter;
}

int main() {
  std::vector<std::vector<int>> input = readInput();
  std::vector<std::vector<int>> temp = input;
  int nrSeatOccupied = 0;
  while (true) {
    input = roundOne(input);
    int counter = countOccupiedSeats(input);

    if (counter == nrSeatOccupied) {
      break;
    } else {
      nrSeatOccupied = counter;
    }
  }

  std::cout << "Nr Seat occupied: " << nrSeatOccupied << std::endl;
  return 0;
}
