#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

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

class Board {
 public:
  Board(std::vector<string> input)
      : board_(100, std::vector<int>(100, 0)),  // change
        minimum_(100, std::vector<int>(100, 0)),
        bassin_(100, std::vector<int>(100, 0)) {  // change
    int y = 0;
    for (string line : input) {
      int x = 0;
      for (char number : line) {
        board_[y][x] = number - '0';
        x++;
      }
      y++;
    }
  };

  void printBoard() {
    for (std::vector<int> line : board_) {
      for (int number : line) {
        cout << number << " ";
      }
      cout << endl;
    }
  }

  void printMinimum() {
    for (std::vector<int> line : minimum_) {
      for (int number : line) {
        cout << number << " ";
      }
      cout << endl;
    }
  }
  void printBassin() {
    for (std::vector<int> line : bassin_) {
      for (int number : line) {
        cout << number << " ";
      }
      cout << endl;
    }
  }

  void findMinimum() {
    int y = 0;
    for (std::vector<int> line : board_) {
      int x = 0;
      for (int number : line) {
        std::vector<int> neighbours = findNeigbours(x, y);
        int counter = 0;
        for (int element : neighbours) {
          if (board_[y][x] < element) {
            counter++;
          }
        }
        if (counter == neighbours.size()) {
          minimum_[y][x] = 1;
        }
        x++;
      }
      y++;
    }
  }

  int findBassin(int x, int y) {
    int counter = 1;
    bassin_[y][x] = 1;
    if (x > 0) {
      if (board_[y][x - 1] > board_[y][x] && bassin_[y][x - 1] != 1 &&
          board_[y][x - 1] < 9) {
        counter = counter + findBassin(x - 1, y);
      }
    }
    if (x < xMax) {
      if (board_[y][x + 1] > board_[y][x] && bassin_[y][x + 1] != 1 &&
          board_[y][x + 1] < 9) {
        counter = counter + findBassin(x + 1, y);
      }
    }
    if (y > 0) {
      if (board_[y - 1][x] > board_[y][x] && bassin_[y - 1][x] != 1 &&
          board_[y - 1][x] < 9) {
        counter = counter + findBassin(x, y - 1);
      }
    }
    if (y < yMax) {
      if (board_[y + 1][x] > board_[y][x] && bassin_[y + 1][x] != 1 &&
          board_[y + 1][x] < 9) {
        counter = counter + findBassin(x, y + 1);
      }
    }

    return counter;
  }

  void findAllBassin() {
    int y = 0;
    std::vector<int> sizeBassin;
    for (std::vector<int> line : minimum_) {
      int x = 0;
      for (int number : line) {
        if (number == 1) {
          int counter = findBassin(x, y);
          sizeBassin.push_back(counter);
        }
        x++;
      }
      y++;
    }
    sort(sizeBassin.begin(), sizeBassin.end());
    cout << sizeBassin[sizeBassin.size() - 1] *
                sizeBassin[sizeBassin.size() - 2] *
                sizeBassin[sizeBassin.size() - 3]
         << " = " << sizeBassin[sizeBassin.size() - 1] << " * "
         << sizeBassin[sizeBassin.size() - 2] << " * "
         << sizeBassin[sizeBassin.size() - 3] << endl;
  }

  int countMinimas() {
    int counter = 0;
    for (std::vector<int> line : minimum_) {
      for (int number : line) {
        if (number == 1) {
          counter++;
        }
      }
    }
    return counter;
  }

  int countHightMinimas() {
    int counter = 0;
    int y = 0;
    for (std::vector<int> line : minimum_) {
      int x = 0;
      for (int number : line) {
        if (number == 1) {
          counter = counter + board_[y][x] + 1;
        }
        x++;
      }
      y++;
    }
    return counter;
  }

 private:
  std::vector<std::vector<int>> board_;
  std::vector<std::vector<int>> minimum_;
  std::vector<std::vector<int>> bassin_;
  int xMax = 99;  // change
  int yMax = 99;  // change

  std::vector<int> findNeigbours(int x, int y) {
    std::vector<int> result;
    if (x > 0) {
      result.push_back(board_[y][x - 1]);
    }
    if (x < xMax) {
      result.push_back(board_[y][x + 1]);
    }
    if (y > 0) {
      result.push_back(board_[y - 1][x]);
    }
    if (y < yMax) {
      result.push_back(board_[y + 1][x]);
    }
    return result;
  }

  void print_vector(std::vector<int> v) {
    for (int e : v) {
      cout << e << " ";
    }
    cout << endl;
  }
};

int main() {
  std::vector<std::string> input = readInput();
  Board board(input);
  board.findMinimum();
  cout << board.countHightMinimas() << endl;
  // board.printBoard();
  // board.printMinimum();
  board.findAllBassin();
  // board.printBassin();
  return 0;
}
