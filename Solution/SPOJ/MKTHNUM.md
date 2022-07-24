## 题意
给你 $n$ 个数，$m$ 个询问，每次询问给你 $l$、$r$ 和 $k$，求 $\left[l, r\right]$ 里第 $k$ 小的数。

## 解法 $1$
对于每次询问调用 `algorithm` 库里的 `nth_element` 函数，期望时间复杂度 $\mathcal O\left(nm\right)$，过不了。

## 解法 $2$
整体二分。