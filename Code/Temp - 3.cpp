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
namespace _READ_RAW_ {
char _Rd();
}  // namespace _READ_RAW_
using namespace std;
constexpr bool __MTCS__ = 0;
constexpr tp _BUF_SIZE_ = 2179217;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

namespace __SOL__ {
constexpr tp base_table[] = {131, 233, 13331, 1333331, 565447777, 1145147777},
             mod_table[] = {32327, 1145141, 1145143, 2179217, 2172179, 3534547};

void main([[maybe_unused]] size_t __CASE__) {  // :/
  constexpr tp Hat_N = 1.1e7 + 3;
  srand(time(0));
  tp base1 = base_table[rand() % 6], mod1 = mod_table[rand() % 6],
     base2 = base_table[rand() % 6], mod2 = mod_table[rand() % 6];
  string s = '#' + rs;
  tp n = s.size() - 1, tar = 0;
  array<tp, Hat_N> hashl1, hashl2, hashr1, hashr2, bp1, bp2;
  hashl1[0] = hashl2[0] = hashr1[0] = hashr2[0];
  bp1[0] = bp2[0] = 1;
  for (tp i = 1; i <= n; ++i) {
    bp1[i] = (bp1[i - 1] * base1) % mod1;
    bp2[i] = (bp2[i - 1] * base2) % mod2;
    hashl1[i] = (hashl1[i - 1] * base1 + s[i]) % mod1;
    hashl2[i] = (hashl2[i - 1] * base2 + s[i]) % mod2;
    hashr1[i] = (hashr1[i - 1] * base1 + s[n - i + 1]) % mod1;
    hashr2[i] = (hashr2[i - 1] * base2 + s[n - i + 1]) % mod2;
  }
  function<tp(bool, tp, tp)> hget[2] = {
      [&](bool type, tp l, tp r) -> tp {
        tp v = type ? (hashl2[r] - hashl2[l - 1] * bp2[r - l + 1])
                    : (hashl1[r] - hashl1[l - 1] * bp1[r - l + 1]),
           mod = type ? mod2 : mod1;
        return ((v % mod) + mod) % mod;
      },
      [&](bool type, tp l, tp r) -> tp {
        r = n - exchange(l, n - r + 1) + 1;
        tp v = type ? (hashr2[r] - hashr2[l - 1] * bp2[r - l + 1])
                    : (hashr1[r] - hashr1[l - 1] * bp1[r - l + 1]),
           mod = type ? mod2 : mod1;
        return ((v % mod) + mod) % mod;
      }};
  for (tp i = 1; i <= n; ++i) {
    tp qlen = 0;
    for (tp offset = n; offset; offset >>= 1) {
      tp len = qlen + offset;  // [i - len, i + len]
      if (i - len < 1 || i + len > n) {
        continue;
      } else if (hget[0](0, i - len, i + len) ==
                 hget[1](0, i - len, i + len)) {  // using hash1
        if (hget[0](1, i - len, i + len) ==
            hget[1](1, i - len, i + len)) {  // using hash2
          qlen = len;
        }
      }
    }
    qlen = qlen * 2 + 1;
  }
  printf("%lld\n", tar);
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
std::array<char, _BUF_SIZE_> _BUF_;
std::array<char, _BUF_SIZE_>::iterator __Cur, __End = __Cur + 1;

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