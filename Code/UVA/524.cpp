// By rbtree (https://rbtree.archi)
// Please submit with C++14!
#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
#define ra _Read_Int()
#define rc _Read_Char()
#define rs _Read_String()
#define iotop _Get_IO_Top()
#ifdef ___RB_DEBUG___
#include "rb_debug.h"
#else
#define dbg(...)
#define dputs(...)
#endif

using tp = long long;
tp _Read_Int();
char _Read_Char();
bool _Get_IO_Top();
std::string _Read_String();
using namespace std;
constexpr bool __MTCS__ = 0;
constexpr tp _BUF_SIZE_ = 2172179;

namespace __SOL__ {
constexpr tp Hat_N = 16;

signed main([[maybe_unused]] size_t __CASE__) {
  while (iotop) {
    tp n = ra;
    if (__CASE__ != 1) {
      puts("");
    }
    printf("Case %llu:\n", __CASE__++);
    array<bool, Hat_N + 1> used;
    array<bool, Hat_N * 2> prime;
    array<tp, Hat_N> a;
    prime.fill(1);
    used.fill(0);
    for (tp i = 3; i < Hat_N * 2; ++i) {
      if (prime[i]) {
        for (tp j = i * 2; j < Hat_N * 2; j += i) {
          prime[j] = 0;
        }
      }
    }
    function<void(tp)> dfs = [&](tp idx) -> void {
      if (idx > n) {
        if (prime[a[1] + a[n]]) {
          printf("%lld", a[1]);
          for (tp i = 2; i <= n; ++i) {
            printf(" %lld", a[i]);
          }
          puts("");
        }
        return;
      }
      for (tp i = 1; i <= n; ++i) {
        if (!used[i] && prime[a[idx - 1] + i]) {
          a[idx] = i;
          used[i] = 1;
          dfs(idx + 1);
          used[i] = 0;
        }
      }
    };
    a[1] = 1;
    used[1] = 1;
    dfs(2);
  }
  return 0;
}
}  // namespace __SOL__

signed main() {
  tp __MTCS__ = ::__MTCS__ ? ra : 1;
  for (tp __i = 1; __i <= __MTCS__; ++__i) {
    __SOL__::main(__i);
  }
  return EXIT_SUCCESS;
}

namespace _READ_RAW_ {
array<char, _BUF_SIZE_> _BUF_;
array<char, _BUF_SIZE_>::iterator __Cur, __End = __Cur + 1;

char _Rd() {
  if (++__Cur == __End) {
    __Cur = _BUF_.begin();
    __End = __Cur + fread(_BUF_.begin(), 1, _BUF_SIZE_, stdin);
  }
  return *__Cur;
}
}  // namespace _READ_RAW_

bool _Get_IO_Top() {
  if (_READ_RAW_::__Cur + 1 == _READ_RAW_::__End) {
    _READ_RAW_::__Cur = _READ_RAW_::_BUF_.begin();
    _READ_RAW_::__End = _READ_RAW_::__Cur +
                        fread(_READ_RAW_::_BUF_.begin(), 1, _BUF_SIZE_, stdin);
    return _READ_RAW_::__Cur-- != _READ_RAW_::__End;
  }
  return 1;
}
tp _Read_Int() {
  bool __neg(0);
  char __c(_READ_RAW_::_Rd());
  tp __val(0);
  for (; __c < 48 || __c > 57; __c = _READ_RAW_::_Rd()) {
    __neg = __c == 45;
  }
  __val = __c & 15;
  for (__c = _READ_RAW_::_Rd(); __c > 47 && __c < 58; __c = _READ_RAW_::_Rd()) {
    __val = __val * 10 + (__c & 15);
  }
  return __neg ? ~__val + 1 : __val;
}
char _Read_Char() {
  char __c = _READ_RAW_::_Rd();
  while (__c == 32 || __c == 10 || __c == 13) {
    __c = _READ_RAW_::_Rd();
  }
  return __c;
}
std::string _Read_String() {
  char __c = _READ_RAW_::_Rd();
  string __val;
  while (__c == 32 || __c == 10 || __c == 13) {
    __c = _READ_RAW_::_Rd();
  }
  do {
    __val.push_back(__c);
    __c = _READ_RAW_::_Rd();
  } while (__c != 32 && __c != 10 && __c != 13);
  return __val;
}

/*#################################################################
#.................................................................#
#............................This.Code.Was.Created.By.RBTree......#
#.............#......#...............Limiting-Factor..............#
#............#.#....#.#.................Soul-Code.................#
#.............########............................................#
#............#........#..##############################...........#
#...........#..V....V......#..#........................#..#...#...#
#............#........#....#..........###..###..........#..#.#.#..#
#............#..X##X..#..#............#....#.#...........#..#...#.#
#...........#...N##N...#..#...........###..###..........#.........#
#.......MOE..#..@.....#....#.#.#.#...................#.#..........#
#.............########.....#.#.#.##############.#.#..#.#..........#
#..........................#.#.#.#.............#.#.#.#.#..........#
#......#########...........#.#.#.#.................#.#.#..........#
#.....#.........#..........#.#.#.#.................#.#.#..........#
#.#.#.#G#R#A#S#S#.#.#......#.#.#.#.................#.#.#..........#
#.###################......#.#.#.#.................#.#.#..........#
#...........................#.#.#...................#.#...........#
#.................................................................#
#################################################################*/