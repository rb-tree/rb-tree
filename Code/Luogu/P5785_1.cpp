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

signed main() {
  tp n = ra, s = ra;
  vector<tp> t(n + 1, 0), c(n + 1, 0), f(n + 1, -1ull >> 2);
  f[0] = 0;
  for (tp i = 1; i <= n; ++i) {
    t[i] = t[i - 1] + ra;
    c[i] = c[i - 1] + ra;
  }
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 0; j < i; ++j) {
      f[i] = min(f[i], f[j] + s * (c[n] - c[j]) + t[i] * (c[i] - c[j]));
    }
  }
  printf("%lld\n", f[n]);
  return 0;
}

////////////////////////////////////////////////////////////////////////////////