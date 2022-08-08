#include <windows.h>

#include <iostream>
#include <thread>

using namespace std;
namespace _RANDOM_ {
unsigned long long seed, mul;
struct _PRE_ {
  _PRE_() {
    FILETIME t;
    GetSystemTimeAsFileTime(&t);
    seed = mul = (((uintmax_t)t.dwHighDateTime << 32ull) + t.dwLowDateTime);
  }
} __PRE__;

unsigned long long _rand() {
  return ++seed *= ++mul;
}
}  // namespace _RANDOM_
using _RANDOM_::_rand;
using tp = long long;

int main() {
  tp n = _rand() % 5, m = _rand() % 5;
  cout << ++n << ' ' << ++m << '\n';
  while (n--) {
    cout << (_rand() % 9) + 1 << '\n';
  }
  while (m--) {
    tp l = (_rand() % 9) + 1, r = (_rand() % 9) + 1;
    while (l > r) {
      l = (_rand() % 9) + 1, r = (_rand() % 9) + 1;
    }
    cout << l << ' ' << r << '\n';
  }
  return 0;
}