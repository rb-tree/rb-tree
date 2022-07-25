// By rbtree - Koi Carp
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

using tp = long long;
tp _Read();
using namespace std;
constexpr bool __MTCS__ = 0;
constexpr tp Hat_N = 1e6, pow3[] = {3, 30, 300, 3000, 30000, 300000};

array<tp, Hat_N + 3> f;

void update(tp c, tp v) {
  for (tp i = Hat_N; i >= c; --i) {
    f[i] = max(f[i], f[i - c] + v);
  }
}

namespace __SOL__ {
signed main() {
  tp n = ra * 3 - 3;
  array<tp, 6> a;
  for (tp i : {0, 1, 2, 3, 4, 5}) {
    a[i] = ra;
  }
  for (tp i = 0; i < Hat_N; ++i) {
    for (tp j = -1, k = i; k; k /= 10) {
      f[i] += (!(k % 10 % 3)) * (k % 10) / 3 * a[++j];
    }
  }
  for (tp i : {0, 1, 2, 3, 4, 5}) {
    tp hat = min(n, Hat_N / pow3[i]);
    for (tp j = 1; j < hat; j <<= 1) {
      hat -= j;
      update(pow3[i] * j, a[i] * j);
    }
    update(pow3[i] * hat, a[i] * hat);
  }
  for (n = ra; n--; printf("%lld\n", f[ra])) {
  }
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