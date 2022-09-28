// Please submit with C++14! It's best to use C++20 or higher version.
#ifndef LOCAL        // Spectre
#pragma region HEAD  // By rbtree (https://rbtree.dev)
#endif
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
#ifdef ___RB_DEBUG___
#include "rb_debug.h"
#else
#define dbg(...)
#endif
#define ra (scanf("%lld", &la), la)
#define se(exp) exp.begin(), exp.end()
#define fe(arr, exp) for_each(se(arr), exp)
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)

typedef long long tp;
tp la;
using namespace std;
#ifndef LOCAL
#pragma endregion HEAD
#endif

constexpr bool __MTCS__ = 0;

////////////////////////////////////////////////////////////////////////////////

constexpr tp Hat_L = 1e6 + 3;

map<tp, tp> rec;

tp lowbit(tp x) {
  return x & -x;
}

void modify(tp x, tp delta) {
  for (; x < Hat_L; x += lowbit(x)) {
    rec[x] += delta;
  }
}

tp query(tp x) {
  tp tar = 0;
  for (; x; x -= lowbit(x)) {
    tar += rec[x];
  }
  return tar;
}

void __Cored__([[maybe_unused]] tp __TID__) {
  tp n = ra;
  vector<list<pair<tp, tp>>> q(Hat_L), ad(Hat_L), mi(Hat_L);
  vector<bool> g(n, 1);
  for (tp i = 0; i < n; ++i) {
    tp x1 = ra, y1 = ra + 1, x2 = ra, y2 = ra + 1;
    ad[x1].emplace_back(y1, y2);
    mi[x2].emplace_back(y1, y2);
    q[x1].emplace_back(y1, i);
  }
  for (tp i = 0; i < Hat_L; ++i) {
    for (auto&& [i, j] : ad[i]) {
      modify(i, 1);
      modify(j + 1, -1);
    }
    for (auto&& [i, j] : q[i]) {
      g[j] = g[j] && query(i) == 1;
    }
    for (auto&& [i, j] : mi[i]) {
      modify(i, -1);
      modify(j + 1, 1);
    }
  }
  printf("%d\n", accumulate(g.begin(), g.end(), 0));
}

////////////////////////////////////////////////////////////////////////////////

signed main() {
  static tp __TCS__ = __MTCS__ ? ra : 1, __NOW__ = 0;
  while (__NOW__ < __TCS__) {
    __Cored__(++__NOW__);
  }
  return 0;
}