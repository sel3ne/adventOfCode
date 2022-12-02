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

class Bag {
 public:
  Bag(std::string name, std::vector<std::string> contains,
      std::vector<int> containsNr) {
    name_ = name;
    contains_ = contains;
    containsNr_ = containsNr;
  }
  Bag(std::string name) {
    name_ = name;
    contains_ = {};
    containsNr_ = {};
  }

  void print() {
    std::cout << "Name: " << name_ << std::endl;
    for (int i = 0; i < contains_.size(); i++) {
      std::cout << "  | Contains: " << contains_[i] << std::endl;
    }
  }
  std::vector<std::string> contains() { return contains_; }
  std::string name() { return name_; }
  std::vector<int> numbers() { return containsNr_; }

 private:
  std::string name_;
  std::vector<std::string> contains_;
  std::vector<int> containsNr_;
};

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

void tokenize(std::string& str, char delim, std::vector<std::string>& out) {
  size_t start;
  size_t end = 0;

  while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
    end = str.find(delim, start);
    out.push_back(str.substr(start, end - start));
  }
}

std::vector<Bag> readInput() {
  std::string line;
  std::ifstream myfile("input.txt");
  char d = ',';
  std::vector<Bag> input = {};
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      line = replace_string(line, " contain", ",", 8);
      line = replace_string(line, "bags", "bag", 4);
      line = replace_string(line, ", ", ",", 2);
      line = replace_string(line, "no other bag.", "", 13);
      line = replace_string(line, ".", "", 1);
      // std::cout << line << std::endl;
      std::vector<std::string> lineAsVector;
      tokenize(line, d, lineAsVector);
      std::string name = lineAsVector[0];

      std::vector<std::string> contains = {};
      std::vector<int> numbers = {};
      for (int i = 1; i < lineAsVector.size(); i++) {
        std::string bagItem = lineAsVector[i];
        std::string NrAsString(1, bagItem[0]);
        int nr = std::stoi(NrAsString);
        std::string name = bagItem.substr(2, 100000000);
        contains.push_back(name);
        numbers.push_back(nr);
      }
      input.push_back(Bag(name, contains, numbers));
    }
    myfile.close();
  }

  else
    std::cout << "Unable to open file";

  return input;
}

bool containsShinyGold(std::vector<Bag> input, std::string bag_name) {
  if (bag_name == "shiny gold bag") {
    return true;
  }

  Bag* b = nullptr;
  for (int i = 0; i < input.size(); i++) {
    if (input[i].name() == bag_name) {
      b = &input[i];
    }
  }
  if (!b) {
    std::cout << bag_name << std::endl;
    exit(1);
  }

  std::vector<std::string> containgBags = b->contains();
  for (int j = 0; j < containgBags.size(); j++) {
    bool result = containsShinyGold(input, containgBags[j]);
    if (result == true) {
      return true;
    }
  }

  return false;
}

int inShineyGold(std::vector<Bag> input, std::string bag_name) {
  Bag* b = nullptr;
  for (int i = 0; i < input.size(); i++) {
    if (input[i].name() == bag_name) {
      b = &input[i];
    }
  }
  if (!b) {
    std::cout << bag_name << std::endl;
    exit(1);
  }
  std::vector<std::string> containgBags = b->contains();
  std::vector<int> nr = b->numbers();
  if (containgBags.size() == 0) {
    return 1;
  }
  int result = 1;
  for (int j = 0; j < containgBags.size(); j++) {
    result = result + nr[j] * inShineyGold(input, containgBags[j]);
  }
  return result;
}

int main() {
  std::vector<Bag> input = readInput();
  // for (int i = 0; i < input.size(); i++) {
  //   input[i].print();
  // }
  // int counter = 0;
  // for (int i = 0; i < input.size(); i++) {
  //   if (containsShinyGold(input, input[i].name())) {
  //     std::cout << input[i].name() << std::endl;
  //     counter++;
  //   }
  // }
  int counter = 0;
  counter = inShineyGold(input, "shiny gold bag");
  std::cout << "Result: " << counter << std::endl;

  return 0;
}
