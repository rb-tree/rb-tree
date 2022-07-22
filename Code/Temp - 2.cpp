#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;
using tp = long long;
const tp MAXN = 2100000;

struct LCT_Node {
  bool color;
  tp f, ts, ch[2];
} tr[MAXN + 1];

bool chd(tp x) {
  return tr[tr[x].f].ch[1] == x;
}

bool nroot(tp x) {
  return tr[tr[x].f].ch[0] == x || tr[tr[x].f].ch[1] == x;
}

void rotate(tp x) {
  bool z = chd(x);
  tp f = tr[x].f, ff = tr[f].f, y = tr[x].ch[!z];
  if (nroot(f)) {
    tr[ff].ch[chd(f)] = x;
  }
  if (tr[tr[tr[x].ch[!z] = f].f = x].f = ff; tr[f].ch[z] = y) {
    tr[y].f = f;
  }
}

void Colorf(tp x) {
  if (x) {
    swap(tr[x].ch[1], tr[x].ch[0]);
    tr[x].color ^= 1;
  }
}

void pushdown(tp x) {
  if (tr[x].color) {
    Colorf(tr[x].ch[0]);
    Colorf(tr[x].ch[1]);
    tr[x].color = 0;
  }
}

void Splay(tp x) {
  tp top = -1, y = x;
  for (tr[++top].ts = y; nroot(y); tr[++top].ts = y = tr[y].f) {
  }
  while (top) {
    pushdown(tr[top--].ts);
  }
  for (pushdown(tr->ts); nroot(x); rotate(x)) {
    if (nroot(y = tr[x].f)) {
      rotate(chd(x) != chd(y) ? x : y);
    }
  }
}

void access(tp x) {
  for (tp y = 0; x; x = tr[x].f) {
    Splay(x);
    tr[x].ch[1] = exchange(y, x);
  }
}

tp findroot(tp x) {
  access(x);
  for (Splay(x); tr[x].ch[0]; x = tr[x].ch[0]) {
    pushdown(x);
  }
  return x;
}

void link(tp x, tp y) {
  access(x);
  Splay(x);
  if (Colorf(x); findroot(y) != x) {
    tr[x].f = y;
  }
}

void cut(tp x, tp y) {
  access(x);
  Splay(x);
  if (Colorf(x); findroot(y) == x && tr[x].f == y && !tr[x].ch[1]) {
    tr[x].f = tr[y].ch[0] = 0;
  }
}

signed main() {
  tp N, M;
  scanf("%lld%lld", &N, &M);
  while (M--) {
    tp opr, x, y;
    scanf("%lld%lld%lld", &opr, &x, &y);
    switch (opr) {
      case 1:
        link(x, y);
        break;
      case 2:
        cout << (findroot(x) == findroot(y) ? "Y\n" : "N\n");
    }
  }
  return 0;
}