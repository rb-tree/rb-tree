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
using namespace std;
constexpr bool __MTCS__ = 1;
constexpr tp Hat_N = 303;
tp _Read();

namespace __SOL__ {
struct Alien {
  tp l, r, d;
};

signed main() {
  tp n = ra, m = 0;
  array<tp, Hat_N * 2> b;
  array<Alien, Hat_N> v;
  array<array<tp, Hat_N * 2>, Hat_N * 2> f;
  for (tp i = 1; i <= n; ++i) {
    b[++m] = v[i].l = ra;
    b[++m] = v[i].r = ra;
    v[i].d = ra;
  }
  stable_sort(b.begin() + 1, b.begin() + m + 1);
  m = unique(b.begin() + 1, b.begin() + m + 1) - b.begin() - 1;
  for (tp i = 1; i <= n; ++i) {
    v[i].l = lower_bound(b.begin() + 1, b.begin() + m + 1, v[i].l) - b.begin();
    v[i].r = lower_bound(b.begin() + 1, b.begin() + m + 1, v[i].r) - b.begin();
  }
  for (tp len = 0; len < m; ++len) {
    for (tp l = 1; l + len <= m; ++l) {
      tp r = l + len, id = -1;
      for (tp i = 1; i <= n; ++i) {
        if (l <= v[i].l && v[i].r <= r && (!~id || v[i].d > v[id].d)) {
          id = i;
        }
      }
      if (!~id) {
        f[l][r] = 0;
      } else {
        f[l][r] = -1ull >> 2;
        for (tp k = v[id].l; k <= v[id].r; ++k) {
          f[l][r] = min(f[l][r], f[l][k - 1] + f[k + 1][r]);
        }
        f[l][r] += v[id].d;
      }
    }
  }
  printf("%lld\n", f[1][m]);
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