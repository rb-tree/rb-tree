// Please submit with C++14!
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
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
tp _Read() {
  bool __neg = 0;
  char __c = getchar();
  tp __val = 0;
  for (; __c < 48 || __c > 57; __c = getchar()) {
    __neg = __c == 45;
  }
  for (; __c > 47 && __c < 58; __c = getchar()) {
    __val = __val * 10 + (__c & 15);
  }
  return __neg ? ~__val + 1 : __val;
}
using namespace std;
constexpr tp Hat_N = 2.5e5 + 3;

struct Loc {
  tp x, y;
};

tp k, root;
array<Loc, Hat_N> p;
array<tp, Hat_N> ls, rs, lx, rx, ly, ry;

bool Lcomp_x(const Loc& x, const Loc& y) {
  if (x.x != y.x) {
    return x.x < y.x;
  }
  return x.y < y.y;
}

bool Lcomp_y(const Loc& x, const Loc& y) {
  if (x.y != y.y) {
    return x.y < y.y;
  }
  return x.x < y.x;
}

void maintain(tp x, tp y) {
  lx[x] = min(lx[x], lx[y]);
  rx[x] = max(rx[x], rx[y]);
  ly[x] = min(ly[x], ly[y]);
  ry[x] = max(ry[x], ry[y]);
}

tp build(tp l, tp r, bool xy = 1) {
  if (l > r) {
    return 0;
  } else {
    tp c = l + r >> 1;
    nth_element(&p[l], &p[c], &p[r + 1], xy ? Lcomp_x : Lcomp_y);
    lx[c] = rx[c] = p[c].x;
    ly[c] = ry[c] = p[c].y;
    if (ls[c] = build(l, c - 1, !xy)) {
      maintain(c, ls[c]);
    }
    if (rs[c] = build(c + 1, r, !xy)) {
      maintain(c, rs[c]);
    }
    return c;
  }
}

tp dist(tp x, tp y) {
  tp dx, dy;
  dx = p[x].x < lx[y] ? lx[y] - p[x].x : p[x].x > rx[y] ? p[x].x - rx[y] : 0;
  dy = p[x].y < ly[y] ? ly[y] - p[x].y : p[x].y > ry[y] ? p[x].y - ry[y] : 0;
  return dx + dy;
}

struct K_heap {
  priority_queue<tp> mink;

  void push(tp x, tp y) {
    tp dist = abs(p[x].x - p[y].x) + abs(p[x].y - p[y].y);
    if (mink.size() == k) {
      if (mink.top() > dist) {
        mink.pop();
        mink.push(dist);
      }
    } else {
      mink.push(dist);
    }
  }

  bool abandon(tp d) { return mink.size() == k && mink.top() <= d; }

  void print() {
    list<tp> r;
    while (mink.size()) {
      r.push_front(mink.top());
      mink.pop();
    }
    for (auto&& i : r) {
      printf("%lld\n", i);
    }
  }
} khp;

void calc(tp x, tp y) {
  if (y && !khp.abandon(dist(x, y))) {
    if (x < y) {
      khp.push(x, y);
    }
    calc(x, ls[y]);
    calc(x, rs[y]);
  }
}

void dfs(tp x) {
  if (x) {
    calc(x, root);
    dfs(ls[x]);
    dfs(rs[x]);
  }
}

signed main() {
  tp n = ra;
  k = ra;
  for (tp i = 1; i <= n; ++i) {
    p[i].x = ra;
    p[i].y = ra;
  }
  dfs(root = build(1, n));
  khp.print();
  return EXIT_SUCCESS;
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