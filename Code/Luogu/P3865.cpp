#pragma region HEAD
#include <algorithm>  // By rbtree (https://rbtree.archi)
#include <array>      // Please submit with C++14!
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
#define ddo  //
#endif
#define ra (scanf("%lld", &__TEMP_READ_VALUE), __TEMP_READ_VALUE)

typedef long long tp;
tp __TEMP_READ_VALUE;
using namespace std;
#pragma endregion HEAD

////////////////////////////////////////////////////////////////////////////////
constexpr tp Hat_N = 1e5 + 3;

tp ST[Hat_N][__lg(Hat_N) + 3 - (__lg(Hat_N) & 1)];

signed main() {
  tp n = ra, m = ra;
  function<tp(tp, tp)> op = [](tp x, tp y) { return max(x, y); };
  for (tp i = 1; i <= n; ++i) {
    ST[i][0] = ra;
  }
  for (tp i = 1; i <= __lg(n); ++i) {
    for (tp j = 1, endj = n - (1ll << i) + 1; j <= endj; ++j) {
      ST[j][i] = op(ST[j][i - 1], ST[j + (1ll << i - 1)][i - 1]);
    }
  }
  while (m--) {
    tp l = ra, r = ra, loc = __lg(r - l + 1);
    printf("%lld\n", op(ST[l][loc], ST[r - (1ll << loc) + 1][loc]));
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////