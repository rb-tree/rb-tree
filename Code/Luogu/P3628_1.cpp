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

constexpr tp Hat_N = 1e6 + 3;

signed main() {
  tp n = ra, a = ra, b = ra, c = ra;
  array<tp, Hat_N> z, p, f;
  for_each(&z[1], &z[n] + 1, [](tp& v) { v = ra; });
  f.fill(-(-1ull >> 2));
  f[0] = p[0] = 0;
  for (tp i = 1; i <= n; ++i) {
    p[i] = p[i - 1] + z[i];
  }
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 0; j < i; ++j) {
      tp t = p[i] - p[j];
      f[i] = max(f[i], f[j] + a * t * t + b * t + c);
    }
  }
  printf("%lld\n", f[n]);
  return 0;
}

////////////////////////////////////////////////////////////////////////////////