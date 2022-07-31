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

using tp = long long;
tp _Read();
using namespace std;
constexpr bool __MTCS__ = 0;

namespace __SOL__ {
array<tp, 12> lim;
array<array<array<array<tp, 1ll << 4>, 11>, 11>, 11> f;

bool get(tp num, tp loc) {
  return (num >> loc) & 1;
}

tp _calc(bool num, tp loc) {
  return num << loc;
}

tp get(bool x, bool y, bool z, bool t) {
  return _calc(x, 0) | _calc(y, 1) | _calc(z, 2) | _calc(t, 3);
}

tp dfs(tp idx, tp l1, tp l2, tp s) {
  if (get(s, 0) && get(s, 1)) {
    return 0;
  } else if (!idx) {
    return get(s, 2);
  } else if (~f[idx][l1][l2][s]) {
    return f[idx][l1][l2][s];
  } else {
    tp sum = 0;
    for (tp i = 0; i <= (get(s, 3) ? 9 : lim[idx]); ++i) {
      sum += dfs(idx - 1, i, l1,
                 get(get(s, 0) || i == 4, get(s, 1) || i == 8,
                     get(s, 2) || (i == l1 && l1 == l2),
                     get(s, 3) || i < (get(s, 3) ? 9 : lim[idx])));
    }
    return f[idx][l1][l2][s] = sum;
  }
}

tp calc(tp x) {
  tp sum = 0;
  if (x < 10000000000) {
    return 0;
  }
  for (auto&& i : f) {
    for (auto&& j : i) {
      for (auto&& k : j) {
        for (auto&& l : k) {
          l = -1;
        }
      }
    }
  }
  for (tp loc = 0; x; x /= 10) {
    lim[++loc] = x % 10;
  }
  for (tp i = 1; i <= lim[11]; ++i) {
    sum += dfs(10, i, 0, get(i == 4, i == 8, 0, i != lim[11]));
  }
  return sum;
}

signed main() {
  tp l = ra;
  cout << calc(ra) - calc(l - 1) << '\n';
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