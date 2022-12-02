#include <algorithm>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

class DockingData {
 public:
  DockingData(std::string mask, std::vector<int64_t> memoryAdresses,
              std::vector<int64_t> numbers) {
    mask_ = mask;
    memoryAdresses_ = memoryAdresses;
    numbers_ = numbers;
    numbersBin_ = numbersToBin(numbers);
    memoryAdressesBin_ = numbersToBin(memoryAdresses);
  }
  void print() {
    std::cout << "Mask: " << mask_ << std::endl;
    for (int i = 0; i < memoryAdresses_.size(); i++) {
      std::cout << "Memory Adress: " << memoryAdresses_[i]
                << " | Number: " << numbers_[i]
                << " | Bin Adress: " << memoryAdressesBin_[i] << std::endl;
    }
  }

  std::string mask() { return mask_; }
  std::vector<int64_t> numbers() { return numbers_; }
  std::vector<int64_t> memoryAdresses() { return memoryAdresses_; }
  std::vector<std::string> numbersBin() { return numbersBin_; }
  std::vector<std::string> memoryAdressesBin() { return memoryAdressesBin_; }

  std::string numerDecToBin(int num) {
    std::string result = {};
    int bin = 0;
    while (num > 0) {
      bin = num % 2;
      result.insert(0, std::to_string(bin));
      num /= 2;
    }
    while (result.size() < mask_.size()) {
      result.insert(0, "0");
    }
    return result;
  }

  std::vector<std::string> numbersToBin(std::vector<int64_t> nums) {
    std::vector<std::string> result;
    for (int i = 0; i < nums.size(); i++) {
      result.push_back(numerDecToBin(nums[i]));
    }
    return result;
  }

 private:
  std::string mask_;
  std::vector<int64_t> memoryAdresses_;
  std::vector<int64_t> numbers_;
  std::vector<std::string> numbersBin_;
  std::vector<std::string> memoryAdressesBin_;
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

void tokenize(std::string& str, char delim, std::vector<std::string>& out) {
  size_t start;
  size_t end = 0;

  while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
    end = str.find(delim, start);
    out.push_back(str.substr(start, end - start));
  }
}

std::vector<DockingData> readInput() {
  std::string line;
  std::ifstream myfile("input.txt");
  char d = '-';
  std::vector<DockingData> input = {};
  std::string mask = "";
  std::vector<int64_t> memoryAdresses = {};
  std::vector<int64_t> numbers = {};
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      line = replace_string(line, "[", "-", 1);
      line = replace_string(line, "] = ", "-", 4);
      line = replace_string(line, " = ", "-", 3);
      std::cout << line << std::endl;
      std::vector<std::string> lineAsVector;
      tokenize(line, d, lineAsVector);
      if (lineAsVector[0] == "mask") {
        input.push_back(DockingData(mask, memoryAdresses, numbers));
        mask = lineAsVector[1];
        numbers = {};
        memoryAdresses = {};
      } else if (lineAsVector[0] == "mem") {
        int64_t memoryAdresse = std::strtoll(lineAsVector[1].c_str(), NULL, 10);
        // std::strtoll(line.c_str(), NULL, 10)
        memoryAdresses.push_back(memoryAdresse);
        int64_t number = std::strtoll(lineAsVector[2].c_str(), NULL, 10);
        numbers.push_back(number);
      }
    }
    myfile.close();
  }

  else
    std::cout << "Unable to open file";

  input.push_back(DockingData(mask, memoryAdresses, numbers));
  return input;
}

void printVector(std::vector<DockingData> nums) {
  for (int i = 0; i < nums.size(); i++) {
    nums[i].print();
  }
}

void printVector(std::vector<std::string> nums) {
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << std::endl;
  }
}

std::string applyMask(const std::string& num, const std::string& mask) {
  std::string result;
  for (int i = 0; i < num.size(); i++) {
    if (mask[i] == 'X') {
      result.push_back(num[i]);
    } else {
      result.push_back(mask[i]);
    }
  }
  return result;
}

std::vector<std::string> applyMaskTask2(const std::string& adress,
                                        const std::string& mask) {
  std::vector<std::string> result = {adress};
  int index = 0;
  for (int i = 0; i < adress.size(); i++) {
    if (mask[i] == '1') {
      for (int j = 0; j < result.size(); j++) {
        result[j][i] = '1';
      }
    } else if (mask[i] == 'X') {
      std::vector<std::string> newResults = {};
      for (int j = 0; j < result.size(); j++) {
        result[j][i] = '0';
        newResults.push_back(result[j]);
        result[j][i] = '1';
        newResults.push_back(result[j]);
      }
      result = newResults;
    }
  }
  return result;
}

int64_t convertBinaryToDecimal(std::string n) {
  int64_t result = 0;
  int power = 0;
  for (int i = n.size() - 1; i >= 0; i--) {
    std::string elementAsString(1, n[i]);
    int element = std::stoi(elementAsString);
    result = result + element * pow(2, power);
    power++;
  }
  return result;
}

// int main2() {
//   // std::string test = "000000000000000000000000000000001011";
//   // convertBinaryToDecimal(test);
//   std::vector<DockingData> input = readInput();
//   std::unordered_map<int, std::string> memory;

//   printVector(input);
//   for (int i = 1; i < input.size(); i++) {
//     DockingData element = input[i];
//     std::string mask = element.mask();
//     for (int instructions = 0; instructions <
//     element.memoryAdresses().size();
//          instructions++) {
//       int memoryAdress = element.memoryAdresses()[instructions];
//       std::string number = element.numbersBin()[instructions];
//       std::string changedNumber = applyMask(number, mask);
//       memory[memoryAdress] = changedNumber;
//     }
//   }

//   int64_t counter = 0;
//   std::string sum = "000000000000000000000000000000000000";
//   for (auto it : memory) {
//     std::cout << it.first << " : " << it.second << std::endl;

//     counter = counter + convertBinaryToDecimal(it.second);
//   }
//   std::cout << "Counter : " << counter << std::endl;
//   return 0;
// }

int main() {
  // std::string test = "000000000000000000000000000000001011";
  // convertBinaryToDecimal(test);
  std::vector<DockingData> input = readInput();
  std::unordered_map<std::string, int64_t> memory;

  printVector(input);
  for (int i = 1; i < input.size(); i++) {
    DockingData element = input[i];
    std::string mask = element.mask();
    for (int instructions = 0; instructions < element.memoryAdresses().size();
         instructions++) {
      std::string memoryAdress = element.memoryAdressesBin()[instructions];
      int64_t number = element.numbers()[instructions];
      std::vector<std::string> changedAdresses =
          applyMaskTask2(memoryAdress, mask);
      // printVector(changedAdresses);
      for (int j = 0; j < changedAdresses.size(); j++) {
        std::cout << "Adress " << changedAdresses[j] << std::endl;
        int memoryAdressDec = convertBinaryToDecimal(changedAdresses[j]);
        std::cout << " Adress as dez " << memoryAdressDec << std::endl;
        std::cout << "num " << number << std::endl;
        memory[changedAdresses[j]] = number;
      }
    }
  }

  int64_t counter = 0;
  for (auto it : memory) {
    // std::cout << it.first << " : " << it.second << std::endl;

    counter = counter + it.second;
  }
  std::cout << "Counter : " << counter << std::endl;
  return 0;
}
