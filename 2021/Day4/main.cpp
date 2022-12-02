#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

std::vector<std::string> readInput(std::string filename) {
  std::string line;
  std::ifstream myfile(filename);
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

void print_vector(std::vector<std::string> v) {
  std::cout << "[ ";
  for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << " ]" << std::endl;
}

void print_vector(std::vector<int> v) {
  std::cout << "[ ";
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << " ]" << std::endl;
}

void SplitString(string s, vector<int> &v, char delimiter) {
  string temp = "";
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == delimiter) {
      if (i == 0) continue;
      v.push_back(stoi(temp));
      temp = "";
    } else {
      temp.push_back(s[i]);
    }
  }
  v.push_back(stoi(temp));
}

class board {
 public:
  board(std::vector<std::string> board_in_string)
      : marked0(5, 0),
        marked1(5, 0),
        marked2(5, 0),
        marked3(5, 0),
        marked4(5, 0),
        sum_row(5, 0),
        sum_column(5, 0) {
    SplitString(board_in_string[0], row0, ' ');
    SplitString(board_in_string[1], row1, ' ');
    SplitString(board_in_string[2], row2, ' ');
    SplitString(board_in_string[3], row3, ' ');
    SplitString(board_in_string[4], row4, ' ');
    hasAleardyWon = false;
  }

  bool hasWon() {
    for (int i : sum_row)
      if (i == 5) return true;
    for (int i : sum_column)
      if (i == 5) return true;
    return false;
  }

  void addNumber(int i) {
    checkInRow(i, row0, 0);
    checkInRow(i, row1, 1);
    checkInRow(i, row2, 2);
    checkInRow(i, row3, 3);
    checkInRow(i, row4, 4);
    addMarked(i, row0, marked0);
    addMarked(i, row1, marked1);
    addMarked(i, row2, marked2);
    addMarked(i, row3, marked3);
    addMarked(i, row4, marked4);
    if (this->hasWon()) hasAleardyWon = true;
  }

  void print() {
    cout << " ---------------- " << endl;
    print_vector(row0);
    print_vector(row1);
    print_vector(row2);
    print_vector(row3);
    print_vector(row4);
    cout << " --- " << endl;
    print_vector(marked0);
    print_vector(marked1);
    print_vector(marked2);
    print_vector(marked3);
    print_vector(marked4);
    cout << " ---------------- " << endl;
  }

  int sum_one_row(std::vector<int> row, std::vector<int> marked) {
    int sum = 0;
    int indexOf = 0;
    for (int i : row) {
      if (marked[indexOf] == 0) {
        sum = sum + i;
      }
      indexOf++;
    }
    return sum;
  }

  int sum_unmarked() {
    int sum = 0;
    sum = sum + sum_one_row(row0, marked0);
    sum = sum + sum_one_row(row1, marked1);
    sum = sum + sum_one_row(row2, marked2);
    sum = sum + sum_one_row(row3, marked3);
    sum = sum + sum_one_row(row4, marked4);
    return sum;
  }

  bool getHasAleardyWon() { return hasAleardyWon; }

 private:
  std::vector<int> row0;
  std::vector<int> row1;
  std::vector<int> row2;
  std::vector<int> row3;
  std::vector<int> row4;
  std::vector<int> sum_row;
  std::vector<int> sum_column;
  std::vector<int> marked0;
  std::vector<int> marked1;
  std::vector<int> marked2;
  std::vector<int> marked3;
  std::vector<int> marked4;
  bool hasAleardyWon;

  void checkInRow(int i, std::vector<int> &row, int nr_of_row) {
    int indexOf = 0;
    for (int index : row) {
      if (index == i) {
        sum_row[nr_of_row]++;
        sum_column[indexOf]++;
      }
      indexOf++;
    }
  }

  void addMarked(int i, std::vector<int> &row, std::vector<int> &marked) {
    int indexOf = 0;
    for (int index : row) {
      if (index == i) marked[indexOf] = 1;
      indexOf++;
    }
  }
};

int main() {
  // std::vector<std::string> boards = readInput("input_small.txt");
  // std::vector<std::string> numbers = readInput("numers_small.txt");
  std::vector<std::string> boards = readInput("input.txt");
  std::vector<std::string> numbers = readInput("numbers.txt");

  std::vector<int> numbers_num;
  print_vector(numbers_num);

  SplitString(numbers[0], numbers_num, ',');

  int rowcounter = 0;
  std::vector<board> boards_board;
  for (int i = 0; i < boards.size(); i = i + 6) {
    boards_board.push_back(board({boards.begin() + i, boards.begin() + i + 5}));
    std::cout << "board created" << std::endl;
  }

  int winningBoardCounter = 0;

  for (int i : numbers_num) {
    for (board &one_board : boards_board) {
      if (one_board.getHasAleardyWon()) continue;
      one_board.addNumber(i);
      if (one_board.hasWon() == true) {
        cout << winningBoardCounter << " have already won" << endl;
        winningBoardCounter++;
        if (winningBoardCounter == boards_board.size()) {
          one_board.print();
          cout << one_board.sum_unmarked() << " * " << i << " = "
               << one_board.sum_unmarked() * i << endl;
        }
      }
    }
  }

  return 0;
}
