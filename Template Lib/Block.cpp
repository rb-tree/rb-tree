// Please submit with C++14!
#pragma region HEAD   // Spectre
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
#define ra (scanf("%lld", &__TEMP_READ_VALUE), __TEMP_READ_VALUE)
#define LIKELY(exp) __builtin_expect(bool(exp), 1)
#define UNLIKELY(exp) __builtin_expect(bool(exp), 0)
#define ai(arr, value) __inia<decltype(arr)::value_type>(value)

template <typename _Tp>
_Tp __inia(typename _Tp::value_type __Val = _Tp::value_type()) {
  _Tp __target;
  return __target.fitp(__Val), __target;
}

typedef long long tp;
tp __TEMP_READ_VALUE;
using namespace std;
#pragma endregion HEAD

////////////////////////////////////////////////////////////////////////////////
#define lb lower_bound
#define ub upper_bound

constexpr tp Hat_N = 1e5 + 3, Hat_BS = 319;

array<tp, Hat_N> a, b, c, app;
array<array<tp, Hat_N>, Hat_BS> f, tar;

signed main() {
  tp n = ra, q = ra, BC = sqrt(n), sz;
  for (tp i = 1; i <= n; ++i) {
    c[i] = a[i] = ra;
    b[i] = (i + BC - 1) / BC;
  }
  stable_sort(&c[1], &c[n] + 1);
  sz = unique(&c[1], &c[n] + 1) - c.begin();
  for (tp i = 1; i <= n; ++i) {
    a[i] = lb(&c[1], &c[sz], a[i]) - c.begin();
  }
  for (tp i = 1; i <= b[n]; ++i) {
    for (tp j = lb(&b[1], &b[n] + 1, i) - b.begin(), PMax = 0; j <= n; ++j) {
      f[i][j] = PMax = max(PMax, ++tar[i][a[j]] * c[a[j]]);
    }
  }
  while (q--) {
    tp x = ra, y = ra, MAX = f[b[x] + 1][y];
    list<tp*> mem_set;
    for (tp i = lb(&b[1], &b[n] + 1, b[y]) - b.begin(); i <= y; ++i) {
      mem_set.push_back(&++app[a[i]]);
    }
    for (tp i = x, ei = ub(&b[1], &b[n] + 1, b[x]) - b.begin(); i < ei; ++i) {
      mem_set.push_back(&++app[a[i]]);
      MAX = max(MAX,
                (tar[b[x] + 1][a[i]] - tar[b[y]][a[i]] + app[a[i]]) * c[a[i]]);
    }
    for_each(mem_set.begin(), mem_set.end(), [](auto&& i) { *i = 0; });
    printf("%lld\n", MAX);
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////