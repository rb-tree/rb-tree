// Please submit with C++14! It's best to use C++17 or higher version.
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
#pragma endregion HEAD

////////////////////////////////////////////////////////////////////////////////

constexpr tp Hat_N = 1e5 + 3, Hat_BS = 319;

array<tp, Hat_BS> bl, br;
array<tp, Hat_N> a, b;
array<unordered_map<tp, tp>, Hat_BS> app;

signed main() {
  tp n = ra, q = ra, bk = sqrt(n);
  b[0] = 0;
  for (tp i = 1; i <= n; ++i) {
    ++app[b[i] = (i - 1 + bk) / bk][a[i] = ra];
    bl[b[i]] = b[i] != b[i - 1] ? i : bl[b[i]];
    br[b[i]] = i;
  }
  while (q--) {
    char c;
    if (cin >> c; c == 'C') {
      tp l = ra;
      --app[b[l]][a[l]];
      ++app[b[l]][a[l] = ra];
    } else {
      tp l = ra, r = ra, k = ra, cnt = 0;
      if (b[r] - b[l] <= 3) {
        for (tp i = l; i <= r; ++i) {
          cnt += a[i] == k;
        }
        printf("%lld\n", cnt);
        continue;
      }
      for (tp i = l; i < bl[b[l] + 1]; ++i) {
        cnt += a[i] == k;
      }
      for (tp i = b[l] + 1; i < b[r]; ++i) {
        cnt += app[i][k];
      }
      for (tp i = bl[b[r]]; i <= r; ++i) {
        cnt += a[i] == k;
      }
      printf("%lld\n", cnt);
    }
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////