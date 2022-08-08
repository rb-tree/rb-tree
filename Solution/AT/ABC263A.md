## 题意
判断是否有三张写有相同的数，另外两张写有另一个相同的数。

输入的所有数都小于等于 $13$。

## 题解
开一个 `std::set`，判断有几个相同的数。

再开一个 `std::multiset`，判断每个数出现了几次。

## [代码](https://raw.verge.tk/rb-tree/rb-tree/main/Code/AT/AGC263A.cpp)