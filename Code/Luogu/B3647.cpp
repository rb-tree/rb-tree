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
constexpr tp Hat_N = 103;

signed main() {
  tp n = ra, m = ra;
  array<array<tp, Hat_N>, Hat_N> f;
  for (auto&& i : f) {
    i.fill(-1ull >> 3);
  }
  while (m--) {
    tp u = ra, v = ra;
    f[v][u] = f[u][v] = min(f[u][v], ra);
  }
  for (tp i = 1; i <= n; ++i) {
    f[i][i] = 0;
  }
  for (tp k = 1; k <= n; ++k) {
    for (tp i = 1; i <= n; ++i) {
      for (tp j = 1; j <= n; ++j) {
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
      }
    }
  }
  for (tp i = 1; i <= n; ++i) {
    for (tp j = 1; j <= n; ++j) {
      printf("%lld ", f[i][j]);
    }
    puts("");
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////