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
  return __target.fill(__Val), __target;
}

typedef long long tp;
tp la;
using namespace std;
#ifndef LOCAL
#pragma endregion HEAD
#endif

////////////////////////////////////////////////////////////////////////////////

#define x(i) c[i]
#define y(i) f[i]
#define k(i) (s + t[i])
#define yc(i, j) (y(j) - y(i))
#define xc(i, j) (x(j) - x(i))

tp s;

vector<tp> t, c, f;
deque<tp> ch({0});

tp fd(double s) {
  tp l = 0, r = ch.size() - 2, tar = -1;
  while (l <= r) {
    tp mid = l + r >> 1;
    if (tp mid = l + r >> 1;
        yc(ch[mid], ch[mid + 1]) >= s * xc(ch[mid], ch[mid + 1])) {
      r = mid - 1;
      tar = mid;
    } else {
      l = mid + 1;
    }
  }
  return ~tar ? ch[tar] : ch.back();
}

signed main() {
  tp n = ra;
  s = ra;
  t = c = vector<tp>(n + 1, 0);
  f.resize(n + 1, -1ull >> 2);
  f[0] = 0;
  for (tp i = 1; i <= n; ++i) {
    t[i] = t[i - 1] + ra;
    c[i] = c[i - 1] + ra;
  }
  for (tp i = 1; i <= n; ++i) {
    tp j = fd(k(i));
    f[i] = f[j] + s * (c[n] - c[j]) + t[i] * (c[i] - c[j]);
    while (ch.size() >= 2 &&
           yc(*next(ch.rbegin()), ch.back()) * xc(ch.back(), i) >=
               yc(ch.back(), i) * xc(*next(ch.rbegin()), ch.back())) {
      ch.pop_back();
    }
    ch.push_back(i);
  }
  printf("%lld\n", f[n]);
  return 0;
}

////////////////////////////////////////////////////////////////////////////////