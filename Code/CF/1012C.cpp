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

////////////////////////////////////////////////////////////////////////////////
constexpr tp Hat_N = 5003;

signed main() {
  tp n = ra;
  array<tp, Hat_N> a;
  array<array<tp, 3>, Hat_N / 2> f;
  for (auto&& i : f) {
    i.fill(-1ull >> 2);
  }
  f[0][0] = f[1][1] = 0;
  for (tp i = 1; i <= n; ++i) {
    a[i] = ra;
  }
  for (tp i = 2; i <= n; ++i) {
    for (tp j = i + 1 >> 1; j; --j) {
      f[j][0] = min(f[j][0], f[j][2]);
      f[j][2] = f[j][1] + max(0ll, a[i] - a[i - 1] + 1);
      f[j][1] =
          min(f[j - 1][0] + max(0ll, a[i - 1] - a[i] + 1),
              f[j - 1][2] + max(0ll, min(a[i - 1], a[i - 2] - 1) - a[i] + 1));
    }
  }
  for (tp i = 1; i <= n + 1 >> 1; ++i) {
    printf("%lld ", min(f[i][0], min(f[i][1], f[i][2])));
  }
  return 0;
}