// Please submit with C++20!
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <list>
#include <map>
#include <ranges>
#include <set>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
#define sc(n) sv::iota(1) | sv::take(n)

using namespace std;
using tp = long long;
namespace sv = std::ranges::views;
constexpr tp Hat_N = 100003;

array<tp, Hat_N * 4> a, b, c, d, delay;

tp ap(tp l, tp r) {
  return (l + r) * (r - l + 1) >> 1;
}

tp ss(tp l, tp r) {
  return (r * (r + 1) * (r * 2 + 1) - (l - 1) * l * (l * 2 - 1)) / 6;
}

void recalc(tp x) {
  a[x] = a[x << 1] + a[x << 1 | 1];
  b[x] = b[x << 1] + b[x << 1 | 1];
  c[x] = c[x << 1] + c[x << 1 | 1];
}

void pushdown(tp x, tp l, tp r) {
  tp mid = l + r >> 1;
  delay[x << 1] += delay[x];
  delay[x << 1 | 1] += delay[x];
  a[x << 1] += (mid - l + 1) * delay[x];
  a[x << 1 | 1] += (r - mid) * delay[x];
  b[x << 1] += ap(l, mid) * delay[x];
  b[x << 1 | 1] += ap(mid + 1, r) * delay[x];
  c[x << 1] += ss(l, mid) * delay[x];
  c[x << 1 | 1] += ss(mid + 1, r) * delay[x];
  delay[x] = 0;
}

void modify(tp x, tp ml, tp mr, tp l, tp r, tp delta) {
  if (ml <= l && r <= mr) {
    a[x] += (r - l + 1) * delta;
    b[x] += ap(l, r) * delta;
    c[x] += ss(l, r) * delta;
    delay[x] += delta;
  } else {
    tp mid = l + r >> 1;
    pushdown(x, l, r);
    if (ml <= mid) {
      modify(x << 1, ml, mr, l, mid, delta);
    }
    if (mid < mr) {
      modify(x << 1 | 1, ml, mr, mid + 1, r, delta);
    }
    recalc(x);
  }
}

tp query(tp x, tp ml, tp mr, tp l, tp r, tp type) {
  if (ml <= l && r <= mr) {
    return type == 1 ? a[x] : type == 2 ? b[x] : c[x];
  } else {
    tp mid = l + r >> 1, sum = 0;
    pushdown(x, l, r);
    if (ml <= mid) {
      sum += query(x << 1, ml, mr, l, mid, type);
    }
    if (mid < mr) {
      sum += query(x << 1 | 1, ml, mr, mid + 1, r, type);
    }
    return sum;
  }
}

signed main() {
  tp n, m;
  scanf("%lld%lld", &n, &m);
  while (m--) {
    char op;
    tp l, r;
    cin >> op;
    scanf("%lld%lld", &l, &r);
    if (op == 'C') {
      tp delta;
      scanf("%lld", &delta);
      modify(1, l, r - 1, 1, n - 1, delta);
    } else {
      tp a = (r - l * r) * query(1, l, r - 1, 1, n - 1, 1) +
             (r + l - 1) * query(1, l, r - 1, 1, n - 1, 2) -
             query(1, l, r - 1, 1, n - 1, 3),
         b = (r - l + 1) * (r - l) >> 1;
      printf("%lld/%lld\n", a / __gcd(a, b), b / __gcd(a, b));
    }
  }
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