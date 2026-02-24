/*
# B3871 [GESP202309 五级] 因数分解

## 题目背景

对应的选择、判断题：<https://ti.luogu.com.cn/problemset/1131>

## 题目描述

每个正整数都可以分解成素数的乘积，例如： $6=2\times 3$，$20=2^2\times5$。

现在，给定一个正整数，请按要求输出它的因数分解式。

## 输入格式

输入第一行，包含一个正整数 $N$。约定 $2 \le N \le 10^{12}$。

## 输出格式

输出一行，为的因数分解式。要求按质因数由小到大排列，乘号用星号 `*` 表示，且左右各空一格。当且仅当一个素数出现多次时，将它们合并为指数形式，用上箭头 `^` 表示，且左右不空格。

## 输入输出样例 #1

### 输入 #1

```
6
```

### 输出 #1

```
2 * 3
```

## 输入输出样例 #2

### 输入 #2

```
20
```

### 输出 #2

```
2^2 * 5
```

## 输入输出样例 #3

### 输入 #3

```
23
```

### 输出 #3

```
23
```
*/
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);
    long long a[100000], l = 0, b[2][100000], c = 0;
    int fl = 0;
    a[0] = 1;
    while (n > 1) {
        // 找下一个质数
        fl = 0;
        while (!fl) {
            a[l]++;
            if (a[l]*a[l] > n) break;
            fl = 1;
            for (int i = 0; i < l && a[i]*a[i] <= a[l]; i++) {
                if (a[l]%a[i] == 0) {
                    fl = 0;
                    break;
                }
            }
        }
        if (fl == 0) break;
        // ******************
        b[1][c] = 0;
        while (n%a[l] == 0) {
            n /= a[l];
            b[1][c]++;
        }
        if (b[1][c]) {
            b[0][c] = a[l];
            c++;
        }
        // ********************
        l++;
        a[l] = a[l-1];
    }
    // 
    if (n > 1) {
        b[0][c] = n;
        b[1][c] = 1;
        c++;
    }
    for (int i = 0; i < c; i++) {
        if (i != 0) {
            cout << " * ";
        }
        cout << b[0][i];
        if (b[1][i] > 1) {
            cout << "^" << b[1][i];
        }
    }
    return 0;
}