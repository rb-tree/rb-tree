// Please submit with C++20!
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <list>
#include <map>
#include <ranges>
#include <set>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
#define sc(n) sv::iota(1) | sv::take(n)
#ifdef ___RB_DEBUG___
std::map<uint64_t, uint64_t> __vis__;
#define dbg(...)                                                               \
  printf(                                                                      \
      ":>> At line '%llu', function '%s', come here in the %lluth time, '%s' " \
      "-> '",                                                                  \
      __LINE__, __FUNCTION__, ++__vis__[__LINE__], #__VA_ARGS__);              \
  _dbg(__VA_ARGS__)
#define dputs(...) printf(__VA_ARGS__)
template <typename _Type>
void _dbg(const _Type& _cur) {
  std::cout << _cur << "' <<:\n";
}
template <typename _Type, typename... _Other>
void _dbg(const _Type& _cur, const _Other&... _other) {
  std::cout << _cur << ", ";
  _dbg(_other...);
}
#else
#define dbg(...)
#define dputs(...)
#endif

using namespace std;
using tp = long long;
namespace sv = std::ranges::views;

vector<tp> dep;
vector<vector<tp>> e;
vector<array<tp, 22>> jmp;

tp lg(tp x) {
  return x ? __lg(x) + 1 : 0;
}

void dfs(tp x, tp f) {
  dep[x] = dep[f] + 1;
  jmp[x][0] = f;
  for (tp i = 1; i <= lg(dep[x]); ++i) {
    jmp[x][i] = jmp[jmp[x][i - 1]][i - 1];
  }
  for (auto&& i : e[x]) {
    if (i != f) {
      dfs(i, x);
    }
  }
}

tp LCA(tp x, tp y) {
  if (dep[x] < dep[y]) {
    swap(x, y);
  }
  while (dep[x] > dep[y]) {
    x = jmp[x][lg(dep[x] - dep[y]) - 1];
  }
  if (x == y) {
    return x;
  }
  for (tp p = lg(dep[x]) - 1; ~p; --p) {
    if (jmp[x][p] != jmp[y][p]) {
      x = jmp[x][p];
      y = jmp[y][p];
    }
  }
  return jmp[x][0];
}

signed main() {
  tp n, m, s;
  scanf("%lld%lld%lld", &n, &m, &s);
  dep.resize(n + 1);
  e.resize(n + 1);
  jmp.resize(n + 1);
  for (tp i = 1; i < n; ++i) {
    tp u, v;
    scanf("%lld%lld", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(s, 0);
  for (tp x, y; m--; printf("%lld\n", LCA(x, y))) {
    scanf("%lld%lld", &x, &y);
  }
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