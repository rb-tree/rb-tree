// By rbtree (https://rbtree.archi)
// Please submit with C++14!
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
#define ra _Read()
#ifdef ___RB_DEBUG___
#include "rb_debug.h"
#else
#define dbg(...)
#define dputs(...)
#endif

using tp = long long;
tp _Read();
using namespace std;
constexpr bool __MTCS__ = 1;
constexpr tp _MOD_ = 1e9 + 7;

namespace __SOL__ {
struct Matrix : array<array<tp, 3>, 3> {
  Matrix() {
    for (auto&& i : *this) {
      for (auto&& j : i) {
        j = 0;
      }
    }
  }

  Matrix operator*=(const Matrix& __val) {
    Matrix __temp;
    for (tp i = 0; i < 3; ++i) {
      for (tp j = 0; j < 3; ++j) {
        for (tp k = 0; k < 3; ++k) {
          __temp[i][j] = (__temp[i][j] + at(i)[k] * __val[k][j]) % _MOD_;
        }
      }
    }
    return *this = __temp;
  }
};

signed main() {
  tp n = ra;
  Matrix tar, mul;
  if (n <= 3) {
    puts("1");
    return 0;
  }
  for (tp i = 0; i < 3; ++i) {
    tar[i][i] = 1;
  }
  mul[0][0] = mul[0][2] = mul[1][0] = mul[2][1] = 1;
  while (n) {
    if (n & 1) {
      tar *= mul;
    }
    mul *= mul;
    n >>= 1;
  }
  printf("%lld\n", tar[1][0]);
  return 0;
}
}  // namespace __SOL__

signed main() {
  tp __MTCS__ = ::__MTCS__ ? ra : 1;
  while (__MTCS__--) {
    __SOL__::main();
  }
  return EXIT_SUCCESS;
}

tp _Read() {
  bool __neg(0);
  char __c(getchar());
  tp __val(0);
  for (; __c < 48 || __c > 57; __c = getchar()) {
    __neg = __c == 45;
  }
  for (; __c > 47 && __c < 58; __c = getchar()) {
    __val = __val * 10 + (__c & 15);
  }
  return __neg ? ~__val + 1 : __val;
}

/*#################################################################
#.................................................................#
#............................This.Code.Was.Created.By.RBTree......#
#.............#......#...............Limiting-Factor..............#
#............#.#....#.#.................Soul-Code.................#
#.............########............................................#
#............#........#..##############################...........#
#...........#..V....V......#..#........................#..#...#...#
#............#........#....#..........###..###..........#..#.#.#..#
#............#..X##X..#..#............#....#.#...........#..#...#.#
#...........#...N##N...#..#...........###..###..........#.........#
#.......MOE..#..@.....#....#.#.#.#...................#.#..........#
#.............########.....#.#.#.##############.#.#..#.#..........#
#..........................#.#.#.#.............#.#.#.#.#..........#
#......#########...........#.#.#.#.................#.#.#..........#
#.....#.........#..........#.#.#.#.................#.#.#..........#
#.#.#.#G#R#A#S#S#.#.#......#.#.#.#.................#.#.#..........#
#.###################......#.#.#.#.................#.#.#..........#
#...........................#.#.#...................#.#...........#
#.................................................................#
#################################################################*/