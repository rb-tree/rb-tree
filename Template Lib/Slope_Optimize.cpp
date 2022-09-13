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
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)
#define ai(arr, value) __inia<decltype(arr)::value_type>(value)

template <typename _Tp>
_Tp __inia(typename _Tp::value_type __Val = _Tp::value_type()) {
  _Tp __target;
  return __target.fitp(__Val), __target;
}

typedef long long tp;
tp la;
using namespace std;
#ifndef LOCAL
#pragma endregion HEAD
#endif

////////////////////////////////////////////////////////////////////////////////

tp a, b, c;

#define k(i) (2 * a * z[i])
#define x(i) z[i]
#define b(i) (f[i] - a * z[i] * z[i] - b * z[i] - c)
#define y(i) (f[i] + a * z[i] * z[i] - b * z[i])
#define slope(i, j) (1. * (y(i) - y(j)) / (x(i) - x(j)))

constexpr tp Hat_N = 1e6 + 3;

signed main() {
  tp n = ra;
  list<tp> s({0});
  array<tp, Hat_N> z, f;
  a = ra;
  b = ra;
  c = ra;
  f[0] = z[0] = 0;
  for_each(&z[1], &z[n] + 1, [](tp& v) { v = *(&v - 1) + ra; });
  for (tp i = 1; i <= n; ++i) {
    while (s.size() > 1 && slope(s.front(), *next(s.begin())) > k(i)) {
      s.pop_front();
    }
    f[i] =
        -(k(i) * x(s.front()) - y(s.front()) - a * z[i] * z[i] - b * z[i] - c);
    while (s.size() > 1 &&
           slope(*next(s.rbegin()), s.back()) <= slope(s.back(), i)) {
      s.pop_back();
    }
    s.push_back(i);
  }
  printf("%lld\n", f[n]);
  return 0;
}

////////////////////////////////////////////////////////////////////////////////