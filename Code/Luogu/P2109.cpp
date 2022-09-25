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

typedef long long tp;
tp la;
using namespace std;
#ifndef LOCAL
#pragma endregion HEAD
#endif

////////////////////////////////////////////////////////////////////////////////

constexpr tp MOD = 1e9 + 7;
constexpr tp Cmul[][10] = {
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1}};

struct Matrix : array<array<tp, 10>, 10> {
  Matrix() {
    for (auto&& i : *this) {
      for (auto&& j : i) {
        j = 0;
      }
    }
  }

  Matrix operator*=(const Matrix& __val) {
    Matrix __temp;
    for (tp i = 0; i < 10; ++i) {
      for (tp j = 0; j < 10; ++j) {
        for (tp k = 0; k < 10; ++k) {
          __temp[i][j] = (__temp[i][j] + at(i)[k] * __val[k][j]) % MOD;
        }
      }
    }
    return *this = __temp;
  }
};

signed main() {
  tp n = ra - 1;
  Matrix tar, mul;
  if (!n) {
    puts("10");
    return 0;
  }
  for (tp i = 0; i < 10; ++i) {
    tar[i][i] = 1;
    for (tp j = 0; j < 10; ++j) {
      mul[i][j] = Cmul[i][j];
    }
  }
  while (n) {
    if (n & 1) {
      tar *= mul;
    }
    mul *= mul;
    n >>= 1;
  }
  mul = tar;
  for (auto&& i : tar) {
    i.fill(0);
  }
  tar[0].fill(1);
  tar[0][0] = 0;
  tar *= mul;
  printf("%lld\n", accumulate(&tar[0][1], tar[0].end(), tar[0][0]) % MOD);
  return 0;
}

////////////////////////////////////////////////////////////////////////////////