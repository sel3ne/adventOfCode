#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

class Passport {
 public:
  Passport(std::string byr, std::string iyr, std::string eyr, std::string hgt,
           std::string hcl, std::string ecl, std::string pid, std::string cid) {
    byr_ = byr;
    iyr_ = iyr;
    eyr_ = eyr;
    hgt_ = hgt;
    hcl_ = hcl;
    ecl_ = ecl;
    pid_ = pid;
    cid_ = cid;
  }

  void print() {
    std::cout << "byr " << byr_ << std::endl;
    std::cout << "iyr " << iyr_ << std::endl;
    std::cout << "eyr " << eyr_ << std::endl;
    std::cout << "hgt " << hgt_ << std::endl;
  }

  bool invalid_byr() {
    int x;
    try {
      x = std::stoi(byr_);
    } catch (...) {
      return true;
    }
    if (x < 1920 || x > 2002) {
      return true;
    }
    return false;
  }

  bool invalid_iyr() {
    int x;
    try {
      x = std::stoi(iyr_);
    } catch (...) {
      return true;
    }
    if (x < 2010 || x > 2020) {
      return true;
    }
    return false;
  }

  bool invalid_eyr() {
    int x;
    try {
      x = std::stoi(eyr_);
    } catch (...) {
      return true;
    }
    if (x < 2020 || x > 2030) {
      return true;
    }
    return false;
  }

  bool invalid_hgt() {
    if (hgt_.find("cm") != std::string::npos) {
      hgt_.erase(hgt_.end() - 2, hgt_.end());
      int x;
      try {
        x = std::stoi(hgt_);
      } catch (...) {
        return true;
      }
      if (x < 150 || x > 193) {
        return true;
      }
      return false;

    } else if (hgt_.find("in") != std::string::npos) {
      hgt_.erase(hgt_.end() - 2, hgt_.end());
      int x;
      try {
        x = std::stoi(hgt_);
      } catch (...) {
        return true;
      }
      if (x < 59 || x > 76) {
        return true;
      }
      return false;
    }
    return true;
  }

  bool invalid_hcl() {
    if (hcl_.find("#") != std::string::npos) {
      hcl_.erase(0, 1);
      if (hcl_.size() != 6) {
        return true;
      }
      bool invalid_word = false;
      for (auto element : hcl_) {
        if (element == '1' || element == '2' || element == '3' ||
            element == '4' || element == '5' || element == '6' ||
            element == '7' || element == '8' || element == '9' ||
            element == 'a' || element == 'b' || element == 'c' ||
            element == 'd' || element == 'e' || element == 'f' ||
            element == '0') {
          invalid_word = invalid_word || false;
        } else {
          invalid_word = invalid_word || true;
        }
      }
      if (invalid_word) {
        std::cout << hcl_ << std::endl;
      }
      return invalid_word;
    }
    return true;
  }

  bool invalid_ecl() {
    if (ecl_ == "amb" || ecl_ == "blu" || ecl_ == "brn" || ecl_ == "gry" ||
        ecl_ == "grn" || ecl_ == "hzl" || ecl_ == "oth") {
      return false;
    } else {
      return true;
    }
  }

  bool invalid_pid() {
    if (pid_.size() != 9) {
      return true;
    }
    int x;
    try {
      x = std::stoi(eyr_);
    } catch (...) {
      return true;
    }

    return false;
  }

  int invalid() {
    if (invalid_byr()) {
      return 0;
    }
    if (invalid_iyr()) {
      return 0;
    }
    if (invalid_eyr()) {
      return 0;
    }
    if (invalid_hgt()) {
      return 0;
    }
    if (invalid_hcl()) {
      return 0;
    }
    if (invalid_ecl()) {
      return 0;
    }
    if (invalid_pid()) {
      return 0;
    }
    return 1;
  }

 private:
  std::string byr_;
  std::string iyr_;
  std::string eyr_;
  std::string hgt_;
  std::string hcl_;
  std::string ecl_;
  std::string pid_;
  std::string cid_;
};

void tokenize(std::string& str, char delim, std::vector<std::string>& out) {
  size_t start;
  size_t end = 0;

  while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
    end = str.find(delim, start);
    out.push_back(str.substr(start, end - start));
  }
}

std::list<Passport> readInput() {
  std::string line;
  std::ifstream myfile("input.txt");
  // char d = '-';
  std::list<Passport> input = {};
  if (myfile.is_open()) {
    bool person_finished = false;
    std::string byr = "";
    std::string iyr = "";
    std::string eyr = "";
    std::string hgt = "";
    std::string hcl = "";
    std::string ecl = "";
    std::string pid = "";
    std::string cid = "";
    while (getline(myfile, line)) {
      if (line.empty()) {
        input.push_back(Passport(byr, iyr, eyr, hgt, hcl, ecl, pid, cid));
        byr = "";
        iyr = "";
        eyr = "";
        hgt = "";
        hcl = "";
        ecl = "";
        pid = "";
        cid = "";
      } else {
        std::vector<std::string> lineAsVector;
        tokenize(line, ' ', lineAsVector);
        for (auto element : lineAsVector) {
          std::vector<std::string> passportEntry;
          tokenize(element, ':', passportEntry);
          for (auto it = passportEntry.begin(); it != passportEntry.end();
               it++) {
            if (*it == "byr") {
              std::advance(it, 1);
              byr = *it;
            } else if (*it == "iyr") {
              std::advance(it, 1);
              iyr = *it;
            } else if (*it == "eyr") {
              std::advance(it, 1);
              eyr = *it;
            } else if (*it == "hgt") {
              std::advance(it, 1);
              hgt = *it;
            } else if (*it == "hcl") {
              std::advance(it, 1);
              hcl = *it;
            } else if (*it == "ecl") {
              std::advance(it, 1);
              ecl = *it;
            } else if (*it == "pid") {
              std::advance(it, 1);
              pid = *it;
            } else if (*it == "cid") {
              std::advance(it, 1);
              cid = *it;
            }
          }
        }
      }
    }
    input.push_back(Passport(byr, iyr, eyr, hgt, hcl, ecl, pid, cid));
    myfile.close();
  } else
    std::cout << "Unable to open file";

  return input;
}

int main() {
  std::list<Passport> input = readInput();
  int count = 0;
  for (auto entry : input) {
    // entry.print();
    count = count + entry.invalid();
  }
  std::cout << "count: " << count << std::endl;
  return 0;
}
