#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#include <chrono>

using namespace std::chrono;

class Fishis {
 public:
  Fishis(vector<int> fishisVector) {
    old0_ = 0;
    old1_ = 0;
    old2_ = 0;
    old3_ = 0;
    old4_ = 0;
    old5_ = 0;
    old6_ = 0;
    old7_ = 0;
    old8_ = 0;
    for (int fish : fishisVector) {
      if (fish == 0) {
        old0_++;
      } else if (fish == 1) {
        old1_++;
      } else if (fish == 2) {
        old2_++;
      } else if (fish == 3) {
        old3_++;
      } else if (fish == 4) {
        old4_++;
      } else if (fish == 5) {
        old5_++;
      } else if (fish == 6) {
        old6_++;
      } else if (fish == 7) {
        old7_++;
      } else if (fish == 8) {
        old8_++;
      }
    }
  }

  void addDay() {
    long tmp = old0_;
    old0_ = old1_;
    old1_ = old2_;
    old2_ = old3_;
    old3_ = old4_;
    old4_ = old5_;
    old5_ = old6_;
    old6_ = old7_ + tmp;
    old7_ = old8_;
    old8_ = tmp;
  }

  long count() {
    return old0_ + old1_ + old2_ + old3_ + old4_ + old5_ + old6_ + old7_ +
           old8_;
  }

 private:
  long old0_;
  long old1_;
  long old2_;
  long old3_;
  long old4_;
  long old5_;
  long old6_;
  long old7_;
  long old8_;
};

int main() {
  // auto start = high_resolution_clock::now();
  std::vector<int> fishisVector = {
      5, 4, 3, 5, 1, 1, 2, 1, 2, 1, 3, 2, 3, 4, 5, 1, 2, 4, 3, 2, 5, 1, 4, 2,
      1, 1, 2, 5, 4, 4, 4, 1, 5, 4, 5, 2, 1, 2, 5, 5, 4, 1, 3, 1, 4, 2, 4, 2,
      5, 1, 3, 5, 3, 2, 3, 1, 1, 4, 5, 2, 4, 3, 1, 5, 5, 1, 3, 1, 3, 2, 2, 4,
      1, 3, 4, 3, 3, 4, 1, 3, 4, 3, 4, 5, 2, 1, 1, 1, 4, 5, 5, 1, 1, 3, 2, 4,
      1, 2, 2, 2, 4, 1, 2, 5, 5, 1, 4, 5, 2, 4, 2, 1, 5, 4, 1, 3, 4, 1, 2, 3,
      1, 5, 1, 3, 4, 5, 4, 1, 4, 3, 3, 3, 5, 5, 1, 1, 5, 1, 5, 5, 1, 5, 2, 1,
      5, 1, 2, 3, 5, 5, 1, 3, 3, 1, 5, 3, 4, 3, 4, 3, 2, 5, 2, 1, 2, 5, 1, 1,
      1, 1, 5, 1, 1, 4, 3, 3, 5, 1, 1, 1, 4, 4, 1, 3, 3, 5, 5, 4, 3, 2, 1, 2,
      2, 3, 4, 1, 5, 4, 3, 1, 1, 5, 1, 4, 2, 3, 2, 2, 3, 4, 1, 3, 4, 1, 4, 3,
      4, 3, 1, 3, 3, 1, 1, 4, 1, 1, 1, 4, 5, 3, 1, 1, 2, 5, 2, 5, 1, 5, 3, 3,
      1, 3, 5, 5, 1, 5, 4, 3, 1, 5, 1, 1, 5, 5, 1, 1, 2, 5, 5, 5, 1, 1, 3, 2,
      2, 3, 4, 5, 5, 2, 5, 4, 2, 1, 5, 1, 4, 4, 5, 4, 4, 1, 2, 1, 1, 2, 3, 5,
      5, 1, 3, 1, 4, 2, 3, 3, 1, 4, 1, 1};
  Fishis fishis(fishisVector);

  auto start = high_resolution_clock::now();
  int days = 256;
  for (int day = 0; day < days; day++) {
    fishis.addDay();
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop - start);

  cout << fishis.count() << endl;
  cout << duration.count() << endl;

  return 0;
}
