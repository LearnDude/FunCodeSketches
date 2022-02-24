// #include <iostream>
// #include <vector>

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
// using namespace std;

// using uint = unsigned int;
// using cuint = const unsigned int;

// class Solution {
// public:
//   int maxArea(vector<int> &height) {

//     for (auto a : h) {
//       cout << a << " ";
//     }
//     cout << endl;

//     cuint vecLen = h.size();
//     uint fixed = vecLen - 1;
//     int fixedH = h[fixed];

//     uint A = 0;
//     uint newA = calcA(fixed, 0);

//     while (true) {
//       uint moving = 0;
//       //   int movingH = h[moving];
//       uint movingBest = 0;
//       // int movingBestH = 0;

//       while (moving < vecLen) {
//         // insert skipping calcA that can't be better
//         if (calcA(moving, fixed) > newA) {
//           newA = calcA(moving, fixed);
//           movingBest = moving;
//         }
//         cout << h[fixed] << " " << h[moving] << " " << calcA(fixed, moving)
//              << " " << newA << " " << A << endl;
//         moving++;
//       }
//       if (newA <= A)
//         break;
//       A = newA;
//       fixed = movingBest;
//     }
//     return A;
//   }

//   Solution(vector<int> &height) : h{height} {}

// private:
//   vector<int> &h;

//   unsigned int calcA(uint i, uint j) {
//     if (i > j)
//       return (i - j) * min(h[j], h[i]);
//     if (j > i)
//       return (j - i) * min(h[j], h[i]);
//     return 0;
//   }
// };

// int main() {
//   //   vector<int> input = {1, 8, 6, 2, 5, 4, 8, 3, 7};
//   vector<int> input{2, 3, 4, 5, 18, 17, 6};

//   Solution s(input);
//   auto output = s.maxArea(input);

//   cout << output;

//   //   for (auto a : output) {
//   //     cout << a << " ";
//   //   }
//   cout << endl;
// }

using namespace std::chrono;

int main() {
  constexpr size_t N = 1000 * 1000 * 100;
  std::vector<int64_t> x;
  x.reserve(N);
  for (size_t i = 0; i < N; i++)
    x.push_back(N - i);

  auto start = system_clock::now();
  std::sort(x.begin(), x.end());
  auto stop = system_clock::now();
  std::cout << duration_cast<milliseconds>(stop - start).count() << "\n";
  // std::cout << x[500 * 1000];
}