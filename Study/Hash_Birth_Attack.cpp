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
char _Get_IO_Top();
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
class _RANDOM_ {
  unsigned long long __seed, __mul;

  unsigned long long __get() { return ++__seed *= ++__mul; }

 public:
  _RANDOM_() {
    __seed = __builtin_ia32_rdtsc();
    __mul = clock();
  }

  unsigned long long operator()(long long __l, long long __r) {
    return __get() % (__r - __l + 1) + __l;
  }
} rd;

unsigned long long hsh(vector<unsigned long long>& __s,
                       unsigned long long __base,
                       unsigned long long __mod) {
  unsigned long long __tar = 0;
  for (auto&& __c : __s) {
    __tar = (__tar * __base + __c) % __mod;
  }
  return __tar;
}

vector<unsigned long long> __random_vector(
    unsigned long long __len,
    const vector<unsigned long long> __sigma) {
  vector<unsigned long long> __tar;
  for (__tar.reserve(__len); __len--;
       __tar.push_back(__sigma[rd(0, __sigma.size() - 1)])) {
  }
  return __tar;
}

vector<vector<unsigned long long>> birth(
    unsigned long long __len,
    unsigned long long __mod,
    const vector<unsigned long long> __sigma) {
  vector<vector<unsigned long long>> __tar;
  for (unsigned long long k = 1 + sqrt(1.3862943 * __mod); k--;
       __tar.push_back(__random_vector(__len, __sigma))) {
  }
  return __tar;
}

template <typename _Type>
pair<vector<unsigned long long>, vector<unsigned long long>> birth_attack(
    unsigned long long __max_size,
    unsigned long long __base,
    unsigned long long __mod,
    const vector<unsigned long long>& __sigma,
    _Type __hash_func) {
  constexpr unsigned long long __times = 5;
  for (unsigned long long __len = 1; __len <= __max_size; ++__len) {
    for (unsigned long long ___ = 0; ___ < __times; ++___) {
      map<unsigned long long, vector<unsigned long long>> __col;
      for (auto&& __s : birth(__len, __mod, __sigma)) {
        unsigned long long __hv = __hash_func(__s, __base, __mod);
        if (__col.count(__hv)) {
          for (unsigned long long __i = 0; __i < __s.size(); ++__i) {
            if (__col[__hv][__i] != __s[__i]) {
              return make_pair(__col[__hv], __s);
            }
          }
        } else {
          __col[__hv] = __s;
        }
      }
    }
  }
  return make_pair(vector<unsigned long long>(),
                   vector<unsigned long long>());  // Failed
}

void main([[maybe_unused]] size_t __CASE__) {  // :/
  vector<unsigned long long> sigma;
  for (char i = 'a'; i <= 'z'; ++i) {
    sigma.push_back(i);
  }
  auto x = birth_attack(20, 13331, 998244353, sigma, hsh);
  for (auto&& i : x.first) {
    putchar(i);
  }
  puts("");
  for (auto&& i : x.second) {
    putchar(i);
  }
  puts("");
  printf("%lld\n%lld\n", hsh(x.first, 13331, 998244353),
         hsh(x.second, 13331, 998244353));
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
#.#.#.#G#R#A#S#__col#.#.#......#.#.#.#.................#.#.#..........#
#.###################......#.#.#.#.................#.#.#..........#
#...........................#.#.#...................#.#...........#
#.................................................................#
#################################################################*/