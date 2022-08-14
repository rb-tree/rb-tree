// By rbtree (https://rbtree.archi) :\
// Please submit with C++14!
#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <valarray>
#include <vector>
#define ra _Read_Int()
#define rc _Read_Char()
#define rs _Read_String()
#define rr _READ_RAW_::_Rd()
#define iotop _Get_IO_Top()
#define __FAST__ 1
#ifdef ___RB_DEBUG___
#include "rb_debug.h"
#else
#define dbg(...)
#define dputs(...)
#endif

using tp = long long;
tp _Read_Int();
char _Read_Char();
char _Get_IO_Top();
std::string _Read_String();
namespace _READ_RAW_ {
char _Rd();
}  // namespace _READ_RAW_
using namespace std;
constexpr bool __MTCS__ = 0;
constexpr tp _BUF_SIZE_ = 217'217'21;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

namespace __SOL__ {
tp tar = -1ull >> 2;

bool check(tp idx, tp v, tp h, tp r) {
  tp r1 = 0, r2 = 0;
  for (tp i = idx; i; --i, --r, --h) {
    r1 += i * i * i;
    r2 += r * r * h;
  }
  return r1 <= v && r2 >= v;
}

void dfs(tp idx, tp v, tp s, tp r, tp h) {
  if (s + (tp(sqrt(v)) << 1) >= tar || v < 0 || !check(idx, v, h, r)) {
    return;
  }
  if (!idx) {
    if (!v) {
      tar = s;
    }
    return;
  }
  for (tp i = min(r - 1, (tp)sqrt(v)); i >= idx; --i) {
    for (tp j = min(h - 1, v / i / i); j >= idx; --j) {
      dfs(idx - 1, v - i * i * j, s + (i * j << 1), i, j);
    }
  }
}

void main([[maybe_unused]] size_t __CASE__) {  // :/
  tp n = ra, m = ra;
  for (tp i = sqrt(n); i; --i) {
    for (tp h = n / i / i; h; --h) {
      dfs(m - 1, n - i * i * h, i * i + (i * h << 1), i, h);
    }
  }
  cout << (tar % (-1ull >> 2));
}  // :)
}  // namespace __SOL__

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

signed main() {
  tp __MTCS__ = ::__MTCS__ ? ra : 1;
  for (tp __i = 1; __i <= __MTCS__; ++__i) {
    __SOL__::main(__i);
  }
  return EXIT_SUCCESS;
}

namespace _READ_RAW_ {
#if __FAST__
std::array<char, _BUF_SIZE_ + 1> _BUF_;
std::array<char, _BUF_SIZE_>::iterator __Cur = _BUF_.begin(), __End = __Cur + 1;

char _Rd() {
  if (++__Cur == __End) {
    __Cur = _BUF_.begin();
    __End = __Cur + fread(_BUF_.begin(), 1, _BUF_SIZE_, stdin);
    *__End++ = 10;
  }
  return *__Cur;
}
}  // namespace _READ_RAW_

char _Get_IO_Top() {
  if (_READ_RAW_::__Cur + 1 == _READ_RAW_::__End) {
    _READ_RAW_::__Cur = _READ_RAW_::_BUF_.begin();
    _READ_RAW_::__End = _READ_RAW_::__Cur +
                        fread(_READ_RAW_::_BUF_.begin(), 1, _BUF_SIZE_, stdin);
    if (_READ_RAW_::__Cur == _READ_RAW_::__End) {
      return --_READ_RAW_::__Cur, -1;
    } else {
      return *_READ_RAW_::__Cur--;
    }
  }
  return *(_READ_RAW_::__Cur + 1);
#else
char _Rd() {
  return getchar();
}
#endif
}  // namespace _READ_RAW_

tp _Read_Int() {
  bool __neg(0);
  char __c(_READ_RAW_::_Rd());
  tp __val;
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
  char __c(_READ_RAW_::_Rd());
  for (; __c == 32 || __c == 10 || __c == 13; __c = _READ_RAW_::_Rd()) {
  }
  return __c;
}
std::string _Read_String() {
  char __c(_READ_RAW_::_Rd());
  std::string __val;
  for (; __c == 32 || __c == 10 || __c == 13; __c = _READ_RAW_::_Rd()) {
  }
  do {
    __val.push_back(__c);
    __c = _READ_RAW_::_Rd();
  } while (__c != 32 && __c != 10 && __c != 13);
  return __val;
}

//\
 ___       ___         ___________     \
|\  \     |\  \       |\    ___   \
\ \  \    \ \  \      \ \   \|_\   \
 \ \  \  __\ \  \      \ \    ___   \
  \ \  \|\__\_\  \      \ \   \  \   \
   \ \____________\      \ \___\  \___\
    \|____________|       \|___|  |___|

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