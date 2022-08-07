# 设计哈希 与 制造哈希冲突

## 设计难卡的滚动哈希
### 滚动哈希
我们使用二元组 $\left(p, a\right)$ 来描述滚动哈希。其中 $p$ 是**模数（modulo）**， $a$ 是**基数（base）**。

对于长度为 $n$ 的字符串 $S$，它的滚动哈希函数为

$$H\left(S\right) = \sum\limits_{i = 1}^n S_i \cdot a^{n - 1} \mod p$$

对于等长的两个字符串 $S$ 和 $T$，若 $S \neq T$ 且 $H\left(S\right) = H\left(T\right)$，则称这是**等长冲突（equal-length collision）**。

### 随机基数
考虑我们固定一个**质数**模数 $p$，在 $\left[1,p\right)$ 中随机一个整数作为基数 $a$ 来做滚动哈希。

对于两个长度为 $n$ 的串 $S, T \left(S \neq T\right)$，考虑计算他们等长冲突的概率：

$$
\begin{align*}
& H\left(S\right) = H\left(T\right)
\newline
\iff & \sum\limits_{i = 1}^n S_i \cdot a^{n - 1} = \sum\limits_{i = 1}^n T_i \cdot a^{n - 1} \mod p
\newline
\iff & P\left(a\right) = \sum\limits_{i = 1}^n \left(S_i - T_i\right) \cdot a^{n - 1} = 0 \mod p
\end{align*}
$$

在这里 $P\left(a\right)$ 是一个关于 $a$ 的 $n − 1$ 度的多项式。那么 $H\left(S\right) = H\left(T\right)$ 的概率就是 $P\left(a\right) = 0 \pmod p$ 的概率，即 $a$ 是 $P$ 的根的概率。

由于 $p$ 是质数，因此这构成一个域。在域中，任何 $\leq n − 1$ 度的多项式最多有 $n − 1$ 个根。因此

$$\Pr\left[H\left(S\right) = H \left(T\right)\right] = \Pr\left[P\left(a\right) = 0\right] \leq \frac{n - 1}p$$

对于 $n = 10^5, p = 10^9 + 7$，这个概率是 $10^{-4}$ 次方级别的。

$\frac{n - 1}p$ 的范围其实比较紧的。如果 $\left(n - 1\right) \mid \left(p - 1\right)$。考虑 $S = \texttt{baa}\ldots\texttt a, T = \texttt{aa}\ldots\texttt{ab}$，则 $P\left(a\right) = A^{n - 1} - 1 \pmod p$。根据一些群论知识，这个方程有 $n − 1$ 个根。

### 随机模数
考虑固定基数 $a \left(\lvert\Sigma\rvert \leq a < N\right)$，然后在 $[N, 2N − 1]$ 的范围内随机选择一个整数作为模数 $p$。

同样地，对于两个长度为 $n$ 的串 $S,T \left(S \neq T\right)$，考虑计算他们等长冲突的概率：

$$
\begin{align*}
& H\left(S\right) = H\left(T\right) \newline
\iff & X = \sum\limits_{i = 1}^n \left(S_i - T_i\right) \cdot a^{n - i} = 0 \mod p
\end{align*}
$$

则可以通过一些数学知识可以得到

$$
\Pr\left[H\left(S\right) = H\left(T\right)\right] = \Pr\left[p \mid X\right] \leq \sim \frac{n \ln\left(a\right)}N
$$

对于 $n = 10^5, a = 26, N = 10^9$，这个概率是 $3 \times 10^{-4}$ 级别的。

### 如何随机
这里推荐用 `__builtin_ia32_rdtsc` 函数作为种子。

### 多重哈希
我们可以使用多重的随机滚动哈希。如果 $k$ 重哈希的冲突概率分别是 $\alpha_1, \alpha_2, \cdots, \alpha_k$，则使用 $k$ 重哈希冲突的概率就是 $\prod\limits_{i = 1}^k \alpha_i$。

### 更大的模数
哈希的模数越大，冲突的概率就越小。但是更大的模数在计算过程中会很吃力。使用 `__int128` 会降低计算速度。不过有一个质数例外，那就是梅森质数 $p = 2^{61} - 1$，我们可以通过位运算来计算 $a \times b \mod p$：

```cpp
constexpr unsigned long long mod = (1ull << 61) - 1;
unsigned long long mul(unsigned long long a, unsigned long long b) {
  unsigned long long l1 = (unsigned)a, l2 = (unsigned)b,
                     m = l1 * (b >> 32) + l2 * (a >> 32),
                     ret = (l1 * l2 & mod) + (l1 * l2 >> 61) +
                           ((a >> 32) * (b >> 32) << 3) + (m >> 29) +
                           (m << 35 >> 3) + 1;
  ret = (ret & mod) + (ret >> 61);
  ret = (ret & mod) + (ret >> 61);
  return ret - 1;
}
```

## 制造哈希冲突

### 单哈希
#### Thue - Morse 序列攻击：`unsigned long long` 自然溢出
考虑 $P = 2^{64}$， $a$ 任意的情况。我们可以使用 Thue - Morse 序列来卡。它的生成方式如下：

```cpp
constexpr unsigned long long _Pow = 10, N = 1ull << _Pow;

std::string S, T;
S.reverse(N);
T.reserve(N);
for (unsigned long long i = 0; i < N; ++i) {
  S.push_back('A' + (__builtin_popcount(i) & 1));
  T.push_back('B' - (__builtin_popcount(i) & 1));
}
```

这时 $S$ 和 $T$ 就发生了等长冲突（不论 $a$ 的值）。具体参见[这里](https://codeforces.com/blog/entry/4898)。

#### 生日攻击：32 位模数，固定模数和基数
固定长度 $l$，令 $k = 1 + \sqrt{p \cdot (2 \ln2)}$，**等概率随机（uniformly at random）** 生成 $k$ 个长度为 $l$ 的字符串。

如果 $l$ 的值不是特别小，则这 $k$ 个串的哈希值可以近似看作等概率随机分布，使用生日悖论，则这 $k$ 个数全部两两不同的概率是

$$\prod\limits_{i = 0}^{k - 1} \left(1 - \frac ip\right) < \prod\limits_{i = 0}^{k - 1} e^{-\frac ip} < e^{-\ln2} = \frac12$$

因此我们重复这个过程，可以在 $\mathcal O\left(p\right)$ 的时间内找到等长冲突。

生日攻击不依赖于哈希函数（异或哈希也可以）。但它不能卡回文串。

[代码](https://raw.verge.tk/rb-tree/rb-tree/main/Code/Study/Hash_Birth_Attack.cpp)

#### 树攻击：更大模数，固定模数和基数
对于更大的模数，生日攻击将会变得很慢。

考虑**树攻击（tree-attack）**。

对于两个长度为 $n$ 的的字符串 $S, T$，我们知道

$$
\begin{align*}
& H\left(S\right) = H\left(T\right) \newline
\iff & \sum\limits_{i = 1}^n \left(S_i - T_i\right) \cdot \left(a^{n - i} \bmod p\right) = 0 \mod p
\end{align*}
$$

不妨设 $A_i = S_i - T_i$，显然 $-\lvert\Sigma\rvert \leq A_i \leq \lvert\Sigma\rvert$。树攻击会尝试寻找一个 $A_i \in \{-1, 0, 1\}$ 的序列使得

$$\sum\limits_{i = 1}^n A_i \left(a^{n - i} \bmod p\right) = 0$$

考虑维护 $k$ 个集合 $C_1, C_2, \cdots, C_k$。定义 $S\left(C\right) = \sum\limits_{i \in C} A_i \left(a^{n - i} \bmod p\right)$。

如果我们合并两个集合 $C_1, C_2$ 到 $C_3$，则我们可以：
1. 直接合并，则 $S\left(C_3\right) = S\left(C_1\right) + S\left(C_2\right)$
2. 把 $\forall i \in C_1$， $A_i$ 都乘 $-1$ 再合并，则 $S\left(C_3\right) = S\left(C_2\right) - S\left(C_1\right)$
3. 类似 2，则 $S\left(C_3\right) = S\left(C_1\right) - S\left(C_2\right)$
4. 把 $\forall i \in C_1$， $A_i$ 都变成 $0$，则 $S\left(C_3\right) = S\left(C_2\right)$
5. 类似 4，则 $S\left(C_3\right) = S\left(C_1\right)$

一开始我们有 $n$ 个集合，设每个集合的 $A_i$ 都是 $1$。不妨设 $n = 2^k$。则我们每个阶段，都把集合按 $S\left(C\right)$ 排序，然后使用 2 或者 3 方法来合并相邻两个集合（要保证合并完后 $S\left(C\right)$ 非负）。一轮完成后，集合数量减半。如果出现了一个 $S\left(C\right) = 0$ 的集合，那么我们把其他集合的 $A_i$ 都置为 $0$ 即可。这样会最多做 $k$ 轮。如果没有找到，那么就对更大的 $k$ 继续这个过程。

如果一开始 $n$ 个集合的 $S\left(C\right)$ 是等概率随机分布于 $\left[0, p - 1\right]$ 的，则 $k$ 期望为 $\sqrt{2 \lg p} + 1$ 时可以找到。那么我们就可以 $\Theta\left(n\right)$ 构造长度为 $n = 2^{\sqrt{2 \lg p} + 1}$ 的等长冲突的串了。

注意，树攻击是依赖于哈希函数的，即你的哈希函数必须是多项式函数。

##### 卡回文串
树攻击可以卡回文串。以偶回文串为例，具体地说，我们要构造一个**长度为偶数**的串 $S$，使得 $S \neq S^R, H\left(S\right) = H\left(S^R\right)$（ $S^R$ 表示反串）。

那么这等价于

$$
\begin{align*}
& H\left(S\right) = H\left(S^R\right) \newline
\iff & \sum\limits_{i = 1}^n \left(S_i - S_{n - i + 1}\right) \cdot \left(a^{n - i} \bmod p\right) = 0 \mod p
\newline
\iff & \sum\limits_{i = 1}^{\frac n2} \left(S_i - S_{n - i + 1}\right) \left[\left(a^{n - i} - a^{i - 1}\right) \bmod p\right] = 0
\end{align*}
$$

因此我们设 $A_i = S_i - S_{n - i + 1}$，得到

$$\sum\limits_{i = 1}^{\frac n2} A_i \left[\left(a^{n - i} - a^{i - 1}\right) \bmod p\right] = 0$$

那么我们对这个做一次正常的树攻击，就可以构造出一组 $S_i - S_{n - i + 1}$ 的值。

那么用字符 $\texttt a$ 和 $\texttt b$ 来构造串 $S$ 即可。

代码，有点难码，正在努力中......

### 多重树攻击
尽管树攻击速度很快，生成的字符串可能会过长（对于 $p = 2^{64} - 1$，通常 $n = 2048$）。实际上我们可以花更多的计算时间来生成一个尽量短的等长冲突。对于每个集合，我们可以维护 $m$ 个最小的可能的和（单树攻击是 $m = 1$ 的情况）。合并两个集合可以使用堆在 $\mathcal O\left(m \log_2 m\right)$ 的时间内完成。

一通操作猛如虎，分析得到 $k = \sqrt{2 \frac{\lg p}{\lg m}} + \log_2 \left(m\right)$。

## 制造多重哈希冲突

### 逐个击破
以双哈希为例，考虑 $\left(a_1, p_1\right), \left(a_2, p_2\right)$ 的双哈希。首先我们使用生日攻击或者树攻击找到 $\left(a_1, p_1\right)$ 的一个等长冲突 $S, T$ 。然后我们以 $\{S, T\}$ 作为字符集对 $\left(a_2^{\lvert S \rvert}, p_2\right)$ 求出等长冲突（以 $\{S, T\}$ 作为字符集的意思是，我们用 $S$ 和 $T$ 拼接出一个更大的串）。这样就可以把两个哈希都冲突掉。

使用这个方法，时间复杂度是每次攻击的复杂度之和。但生成的串长会随着哈希的重数而指数级增长。

不过这个方法不用考虑模数的大小。

### 中国剩余定理（CRT）
对于树攻击，我们可以使用中国剩余定理来卡哈希。本质上，我们要求

$$
\begin{cases}
\sum\limits_{i = 1}^n A_i \left({a_1}^{n - i} \bmod p_1\right) = 0
\newline
\sum\limits_{i = 1}^n A_i \left({a_2}^{n - i} \bmod p_2\right) = 0
\end{cases}
$$

设 $x_i = a_1^{n - i}, y_i = a_2^{n - i}$，然后我们使用 CRT 求出一个 $z_i \left(0 \leq z_i < [p_1, p_2]\right)$，使得

$$
\begin{cases}
z_i = x_i \mod p_1
\newline
z_i = y_i \mod p_2
\end{cases}
$$

那么我们就只需要

$$\sum\limits_{i = 1}^n A_i \left(z_i \bmod [p_1, p_2]\right) = 0$$

即可。 那么我们对此做一次树攻击即可。

这个方法的要求模数的 $\operatorname{lcm}$ 不能太大。不过它的优点是，双哈希的回文串它也能卡。

---
Reference：
<https://codeforces.com/blog/entry/60442>
