#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

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

class Board {
 public:
  Board(std::vector<string> input)
      : board_(10, std::vector<int>(10, 0)),
        flashed_(10, std::vector<int>(10, 0)) {
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

  void print() {
    int y = 0;
    for (std::vector<int> line : board_) {
      int x = 0;
      int xFlash = 0;
      for (int number : line) {
        cout << board_[y][x] << " ";
        x++;
      }
      cout << " | ";
      for (int number : line) {
        cout << flashed_[y][xFlash] << " ";
        xFlash++;
      }

      cout << endl;
      y++;
    }
  }

  void check(int x, int y) {
    if (board_[y][x] < 9) {
      board_[y][x]++;
    } else
      flash(x, y);
  }

  int flash(int x, int y) {
    board_[y][x] = 0;
    flashed_[y][x] = 1;
    if (x > 0) {
      if (y > 0) {
        check(x - 1, y - 1);
      }
      if (y < 9) {
        check(x - 1, y + 1);
      }
      check(x - 1, y);
    }

    if (x < 9) {
      if (y > 0) {
        check(x + 1, y - 1);
      }
      if (y < 9) {
        check(x + 1, y + 1);
      }
      check(x + 1, y);
    }

    if (y > 0) {
      check(x, y - 1);
    }

    if (y < 9) {
      check(x, y + 1);
    }
    return 0;
  }

  int step() {
    resetflashed();
    int y = 0;
    for (std::vector<int> line : board_) {
      int x = 0;
      for (int number : line) {
        if (board_[y][x] < 9)
          board_[y][x]++;
        else {
          flash(x, y);
        }

        x++;
      }
      y++;
    }
    int counter = resetBoardWithFlashed();
    return counter;
  }

  void resetflashed() {
    int y = 0;
    for (std::vector<int> line : flashed_) {
      int x = 0;
      for (int number : line) {
        flashed_[y][x] = 0;
        x++;
      }
      y++;
    }
  }

  int resetBoardWithFlashed() {
    int y = 0;
    int counter = 0;
    for (std::vector<int> line : board_) {
      int x = 0;
      for (int number : line) {
        if (flashed_[y][x] == 1) {
          board_[y][x] = 0;
          counter++;
        }
        x++;
      }
      y++;
    }

    return counter;
  }

 private:
  std::vector<std::vector<int>> board_;
  std::vector<std::vector<int>> flashed_;
};

int main() {
  std::vector<std::string> input = readInput();

  Board board(input);

  int counter = 0;
  for (int i = 0; i < 10000; i++) {
    int increment = board.step();
    counter = counter + increment;
    if (i == 100) {
      cout << "Part 1: " << counter << endl;
    }
    if (increment == 100) {
      cout << "Part 2: " << i + 1 << endl;
      break;
    }
  }
  return 0;
}
