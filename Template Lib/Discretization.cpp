// Please submit with C++14!
#pragma region HEAD   // Spectre
#include <algorithm>  // By rbtree (https://rbtree.archi)
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
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
#define ra (scanf("%lld", &__TEMP_READ_VALUE), __TEMP_READ_VALUE)
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)

typedef long long tp;
tp __TEMP_READ_VALUE;
using namespace std;
#pragma endregion HEAD

////////////////////////////////////////////////////////////////////////////////
constexpr tp Hat_N = 1e5 + 3;

signed main() {
  tp n = ra;
  array<tp, Hat_N> a, t;
  for (tp i = 1; i <= n; ++i) {
    a[i] = t[i] = ra;
  }
  stable_sort(t.begin() + 1, t.begin() + n + 1);
  t[0] = unique(t.begin() + 1, t.begin() + n + 1) - t.begin();
  for (tp i = 1; i <= n; ++i) {
    a[i] = lower_bound(t.begin() + 1, t.begin() + t[0], a[i]) - t.begin();
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////