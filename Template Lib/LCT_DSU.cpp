// Please submit with C++20!
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using tp = long long;

class Link_Cut_Tree {
  using _Ty = uint64_t;

  struct LCT_Node {
    bool color;
    _Ty f, ts, ch[2];
  };

  vector<LCT_Node> _lct;

  bool __Child(_Ty x) { return _lct[_lct[x].f].ch[1] == x; }

  bool __Root(_Ty x) {
    return _lct[_lct[x].f].ch[0] == x || _lct[_lct[x].f].ch[1] == x;
  }

  void _Rotate(_Ty x) {
    bool z = __Child(x);
    _Ty f = _lct[x].f, ff = _lct[f].f, y = _lct[x].ch[!z];
    if (__Root(f)) {
      _lct[ff].ch[__Child(f)] = x;
    }
    if (_lct[_lct[_lct[x].ch[!z] = f].f = x].f = ff; _lct[f].ch[z] = y) {
      _lct[y].f = f;
    }
  }

  void _Color(_Ty x) {
    if (x) {
      swap(_lct[x].ch[1], _lct[x].ch[0]);
      _lct[x].color ^= 1;
    }
  }

  void _Pushdown(_Ty x) {
    if (_lct[x].color) {
      _Color(_lct[x].ch[0]);
      _Color(_lct[x].ch[1]);
      _lct[x].color = 0;
    }
  }

  void _Splay(_Ty x) {
    _Ty top = -1, y = x;
    for (_lct[++top].ts = y; __Root(y); _lct[++top].ts = y = _lct[y].f) {
    }
    while (~top) {
      _Pushdown(_lct[top--].ts);
    }
    for (; __Root(x); _Rotate(x)) {
      if (__Root(y = _lct[x].f)) {
        _Rotate(__Child(x) != __Child(y) ? x : y);
      }
    }
  }

  void _Access(_Ty x) {
    for (_Ty y = 0; x; x = _lct[x].f) {
      _Splay(x);
      _lct[x].ch[1] = exchange(y, x);
    }
  }

 public:
  Link_Cut_Tree(_Ty n) { _lct.resize(n + 1); }

  _Ty find(_Ty x) {
    _Access(x);
    for (_Splay(x); _lct[x].ch[0]; x = _lct[x].ch[0]) {
      _Pushdown(x);
    }
    return x;
  }

  void link(_Ty x, _Ty y) {
    _Access(x);
    _Splay(x);
    if (_Color(x); find(y) != x) {
      _lct[x].f = y;
    }
  }

  void cut(_Ty x, _Ty y) {
    _Access(x);
    _Splay(x);
    if (_Color(x); find(y) == x && _lct[x].f == y && !_lct[x].ch[1]) {
      _lct[x].f = _lct[y].ch[0] = 0;
    }
  }
};

signed main() {
  return EXIT_SUCCESS;
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