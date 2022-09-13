// Please submit with C++14! It's best to use C++20 or higher version.
#ifndef LOCAL
#pragma region HEAD  // Spectre
#endif
#include <algorithm>  // By rbtree (https://rbtree.archi)
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

constexpr tp Hat_SqrtN = 17323;

tp calc(tp n) {
  array<bool, Hat_SqrtN> pc;
  array<tp, Hat_SqrtN> pl;
  array<tp, Hat_SqrtN << 1> w, g;
  tp s = sqrt(n), nc = 0, tot = 0;
  pc[1] = 1;
  for (tp i = 2; i <= s; ++i) {
    if (!pc[i]) {
      pl[++nc] = i;
      for (tp j = i << 1; j <= s; j += i) {
        pc[j] = 1;
      }
    }
  }
  for (tp l = 1; l <= n; l = (n / (n / l)) + 1) {
    w[++tot] = n / l;
    g[tot] = w[tot] - 1;
  }
  function<tp(tp)> gid = [&](tp x) -> tp {
    return x > s ? n / x : tot - x + 1;
  };
  for (tp i = 1; i <= nc; ++i) {
    for (tp j = 1; j <= tot && pl[i] * pl[i] <= w[j]; ++j) {
      g[j] -= g[gid(w[j] / pl[i])] - i + 1;
    }
  }
  return g[1];
}

signed main() {
  tp l = ra, r = ra;
  printf("%lld\n", calc(r) - calc(l - 1));
  return 0;
}

////////////////////////////////////////////////////////////////////////////////