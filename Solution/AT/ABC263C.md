## 题意
给定 $N$ 和 $M$，输出所以长度为 $N$ 且满足以下条件的数组 $a$。
* $1 \leq a_i \leq M \left(1 \leq i \leq N\right)$
* $a_i > a_{i - 1} \left(2 \leq i \leq N\right)$

$1 \leq N \leq M \leq 10$

## 题解
爆搜即可，时间复杂度 $\mathcal O\left(N! \times M\right)$。

## [代码](https://raw.verge.tk/rb-tree/rb-tree/main/Code/AT/AGC263C.cpp)