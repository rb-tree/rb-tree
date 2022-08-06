// By rbtree (https://rbtree.archi) :\
// Please submit with C++14!
#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <map>
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
template <typename Typex>
class RHeap {
  Typex* ele;
  unsigned long long Size, MSize;

 public:
  RHeap() : Size(0), MSize(1) { ele = new Typex[1]; }

  void push(const Typex& _Val) {
    if (++Size == MSize) {
      Typex* Rele = new Typex[MSize <<= 1];
      for (unsigned long long i = 1; i < Size; ++i) {
        Rele[i] = ele[i];
      }
      delete[] ele;
      ele = Rele;
    }
    ele[Size] = _Val;
    for (unsigned long long x = Size; x > 1 && ele[x] < ele[x >> 1]; x >>= 1) {
      swap(ele[x], ele[x >> 1]);
    }
  }

  void pop() {
    swap(ele[1], ele[Size--]);
    for (unsigned long long x = 1, y = 1;; x = y) {
      if (x << 1 <= Size && ele[x << 1] < ele[y]) {
        y = x << 1;
      }
      if (x << 1 < Size && ele[x << 1 | 1] < ele[y]) {
        y = x << 1 | 1;
      }
      if (y == x) {
        return;
      }
      swap(ele[x], ele[y]);
    }
  }

  const Typex& top() { return ele[1]; }

  unsigned long long size() { return Size; }

  ~RHeap() { delete[] ele; }
};

template <typename Typex>
class Removable_Heap {
  RHeap<Typex> ele, removed;

 public:
  void push(const Typex& _Val) { ele.push(_Val); }

  const Typex& top() {
    while (removed.size() && !(removed.top() < ele.top()) &&
           !(ele.top() < removed.top())) {
      ele.pop();
      removed.pop();
    }
    return ele.top();
  }

  void remove(const Typex& _Val) { removed.push(_Val); }

  void pop() { ele.pop(); }
};

void main([[maybe_unused]] size_t __CASE__) {  // :/
  tp n = ra;
  Removable_Heap<tp> h;
  while (n--) {
    string op = rs;
    if (op == "push") {
      h.push(ra);
    } else if (op == "top") {
      printf("%lld\n", h.top());
    } else if (op == "pop") {
      h.pop();
    } else if (op == "remove") {
      h.remove(ra);
    }
  }
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