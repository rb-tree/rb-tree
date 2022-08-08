#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define rtp(__VALUE__) scanf("%lld", &__VALUE__)

using namespace std;
using tp = long long;
constexpr bool __MTCS__ = 0;

namespace {
template <typename _Typex>
string tpt(_Typex __value = 1, const string& __type = "%lld") {
  size_t __count = static_cast<size_t>(__value);
  string __target;
  __target.reserve(__count << 2ll);
  while (__count--) {
    __target += __type;
  }
  return __target;
}

template <typename... _Typey>
signed sf(const string& __input, _Typey&... __value) {
  return ::scanf(__input.c_str(), &__value...);
}
}  // namespace

namespace __SOL__ {
struct compare {
  template <typename Typex>
  bool operator()(const Typex& _1, const Typex& _2) const {
    if (_1.first != _2.first) {
      return _1.first < _2.first;
    }
    return _1.second > _2.second;
  }
};

signed main() {
  tp n, m, cnt = 0;
  sf(tpt(2), n, m);
  vector<tp> t(n);
  multiset<pair<tp, tp>, compare> c;
  for (auto&& i : t) {
    rtp(i);
  }
  for (tp i = 0; i < m; ++i) {
    tp x, y;
    sf(tpt(2), x, y);
    c.emplace(y, x);
  }
  stable_sort(t.begin(), t.end());
  for (tp i = 0; i < n && c.size(); c.erase(c.begin())) {
    while (i < n && t[i] < c.begin()->second) {
      ++i;
    }
    if (i < n && t[i] <= c.begin()->first) {
      ++cnt;
      ++i;
    }
  }
  cout << cnt;
  return 0;
}

signed PRE() {
  return 0;
}
}  // namespace __SOL__

signed main() {
  static tp __P__ = __SOL__::PRE(), __T__ = 1, __R__ = sf(tpt(__MTCS__), __T__);
  return __T__-- && (main() || __SOL__::main()) ? -1 : __P__;
}

//                                                               \
╭─────────────────────────────────────────────────────────────╮  \
│   This Code Was Created By RBTree (https://rbtree.archi/)   │  \
╰─────────────────────────────────────────────────────────────╯
//
