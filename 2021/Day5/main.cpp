#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#include "absl/strings/str_join.h"
#include "absl/strings/str_split.h"

std::vector<std::string> readInput() {
  std::string line;
  std::ifstream myfile("input.txt");  // to change
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

class Line {
 public:
  Line(std::string oneLine) {
    std::vector<string> v = absl::StrSplit(oneLine, absl::ByAnyChar(",-"));
    x1 = stoi(v[0]);
    y1 = stoi(v[1]);
    x2 = stoi(v[2]);
    y2 = stoi(v[3]);
  }

  void print() { cout << x1 << "," << y1 << " -> " << x2 << "," << y2 << endl; }

  int X1() { return x1; }
  int X2() { return x2; }
  int Y1() { return y1; }
  int Y2() { return y2; }

 private:
  int x1;
  int y1;
  int x2;
  int y2;
};

class Board {
 public:
  Board() : board(1000, std::vector<int>(1000, 0)) {}  // to change

  void addLine(Line line) {
    if (line.X1() == line.X2()) {
      addLineVertical(line);
    } else if (line.Y1() == line.Y2()) {
      addLineHorizonatal(line);
    } else if (line.Y1() < line.Y2() && line.X1() < line.X2()) {
      addLineDiagnoalDown(line);
    } else if (line.Y1() > line.Y2() && line.X1() > line.X2()) {
      addLineDiagnoalDown(line);
    } else {
      cout << "here" << endl;
      addLineDiagnoalUp(line);
    }
  }

  void print() {
    int indexOf = 0;
    cout << " ----------------- " << endl;

    for (auto lineX : board) {
      for (auto elementInLineX : board[indexOf]) {
        std::cout << elementInLineX << " ";
      }
      cout << endl;
      indexOf++;
    }
    cout << " ----------------- " << endl;
  }

  int counter() {
    int indexOf = 0;
    int counter = 0;
    for (auto linex : board) {
      for (auto elementInLineX : board[indexOf]) {
        if (elementInLineX > 1) counter++;
      }
      indexOf++;
    }
    return counter;
  }

 private:
  std::vector<std::vector<int>> board;

  void addLineHorizonatal(Line line) {
    // same y
    int smaller = min(line.X1(), line.X2());
    int larger = max(line.X1(), line.X2());
    for (int i = smaller; i <= larger; i++) {
      board[line.Y1()][i]++;
    }
  }

  void addLineVertical(Line line) {
    // same x
    int smaller = min(line.Y1(), line.Y2());
    int larger = max(line.Y1(), line.Y2());
    for (int i = smaller; i <= larger; i++) {
      board[i][line.X1()]++;
    }
  }

  void addLineDiagnoalDown(Line line) {
    int smallerY = min(line.Y1(), line.Y2());
    int largerY = max(line.Y1(), line.Y2());
    int smallerX = min(line.X1(), line.X2());
    int largerX = max(line.X1(), line.X2());
    int counterY = 0;
    for (int y = smallerY; y <= largerY; y++) {
      board[y][smallerX + counterY]++;
      counterY++;
    }
  }

  void addLineDiagnoalUp(Line line) {
    int lowerY = max(line.Y1(), line.Y2());
    int upperY = min(line.Y1(), line.Y2());
    int lowerX = min(line.X1(), line.X2());
    int upperX = max(line.X1(), line.X2());
    int counterY = 0;
    for (int y = lowerY; y >= upperY; y--) {
      cout << "y " << y << endl;
      cout << "x " << lowerX + counterY << endl;
      board[y][lowerX + counterY]++;
      counterY++;
    }
  }
};

int main() {
  std::vector<std::string> input = readInput();

  std::vector<Line> lines;
  for (auto oneLine : input) {
    lines.push_back(Line(oneLine));
  }

  Board board;

  for (auto line : lines) {
    // cout << " ---> ";
    // line.print();
    board.addLine(line);
    // board.print();
  }

  cout << board.counter() << endl;

  return 0;
}

// to run: g++ main.cpp -l absl_strings && ./a.out
