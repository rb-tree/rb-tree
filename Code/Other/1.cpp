// Please submit with C++17!
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

class RANDOM {
  unsigned long long __seed, __coefficient;

 public:
  RANDOM() : __seed(217), __coefficient(17) {}

  unsigned long long operator()(unsigned long long l, unsigned long long r) {
    return rand() % (r - l + 1) + l;
  }
} rd;

signed main() {
  tp n = ra;
  array<bool, 1003> a, diff;
  function<tp()> q = [&]() -> tp {
    for (tp i = 1; i <= n; ++i) {
      printf("%lld", (tp)a[i]);
    }
    puts("");
    fflush(stdout);
    return ra;
  };
  while (1) {
    for (tp i = 1; i <= n; ++i) {
      a[i] = rd(0, 1);
    }
    if (tp x = q(); x == n) {
      return 0;
    } else if (x == n / 2) {
      break;
    }
  }
  a[1] ^= 1;
  for (tp i = 2; i <= n; ++i) {
    a[i] ^= 1;
    diff[i] = q() == n / 2;
    a[i] ^= 1;
  }
  a[1] ^= 1;
  for (tp i = 2; i <= n; ++i) {
    a[i] ^= diff[i];
  }
  if (q() != n) {
    for (tp i = 1; i <= n; ++i) {
      a[i] ^= 1;
    }
    q();
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////