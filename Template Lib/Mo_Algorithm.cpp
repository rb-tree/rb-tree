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
constexpr tp Hat_N = 1e5 + 3, Hat_Q = 1e5 + 3;

struct Segment {
  tp l, r, id;

  bool operator<(const Segment&) const;
};

tp tar;
array<tp, Hat_N> a, cnt, b, ans;
array<Segment, Hat_Q> s;

bool Segment::operator<(const Segment& comp) const {
  if (b[l] != b[comp.l]) {
    return b[l] < b[comp.l];
  }
  return r < comp.r;
}

void modify(tp l, tp k) {
  if (k > 0) {
    tar += ++cnt[a[l]] == 2;
  } else {
    tar -= --cnt[a[l]] == 1;
  }
}

signed main() {
  tp n = ra, ql = 1, qr = 0, q = ra, bk = sqrt(n);
  cnt.fill(0);
  for (tp i = 1; i <= n; ++i) {
    a[i] = ra;
    b[i] = (i - 1 + bk) / bk;
  }
  for (tp i = 0; i < q; ++i) {
    s[i].l = ra;
    s[i].r = ra;
    s[i].id = i;
  }
  stable_sort(&s[0], &s[q]);
  for (tp i = 0; i < q; ++i) {
    for (; qr < s[i].r; modify(++qr, 1)) {
    }
    for (; qr > s[i].r; modify(qr--, -1)) {
    }
    for (; ql < s[i].l; modify(ql++, -1)) {
    }
    for (; ql > s[i].l; modify(--ql, 1)) {
    }
    ans[s[i].id] = tar;
  }
  for (tp i = 0; i < q; ++i) {
    puts(ans[i] ? "No" : "Yes");
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////