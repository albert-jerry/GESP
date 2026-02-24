/*
# B4415 [GESP202509 四级] 排兵布阵

## 题目背景

对应的选择、判断题：<https://ti.luogu.com.cn/problemset/1192>

## 题目描述

作为将军，你自然需要合理地排兵布阵。地图可以视为 $n$ 行 $m$ 列的网格，适合排兵的网格以 1 标注，不适合排兵的网格以 0 标注。现在你需要在地图上选择一个矩形区域排兵，这个矩形区域内不能包含不适合排兵的网格。请问可选择的矩形区域最多能包含多少网格？

## 输入格式

第一行，两个正整数 $n, m$，分别表示地图网格的行数与列数。

接下来 $n$ 行，每行 $m$ 个整数 $a_{i,1}, a_{i,2}, \ldots, a_{i,m}$，表示各行中的网格是否适合排兵。

## 输出格式

一行，一个整数，表示适合排兵的矩形区域包含的最大网格数。

## 输入输出样例 #1

### 输入 #1

```
4 3
0 1 1
1 0 1
0 1 1
1 1 1
```

### 输出 #1

```
4
```

## 输入输出样例 #2

### 输入 #2

```
3 5
1 0 1 0 1
0 1 0 1 0
0 1 1 1 0
```

### 输出 #2

```
3
```

## 说明/提示

对于所有测试点，保证 $1 \leq n, m \leq 12$，$0 \leq a_{i,j} \leq 1$。
*/
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, m, a[12][12];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int ret = 0;
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < m; y1++) {
            for (int x2 = 0; x2 <= x1; x2++) {
                for (int y2 = 0; y2 <= y1; y2++) {
                    int r = 0, flag = 0;
                    for (int i = x2; i <= x1; i++) {
                        for (int j = y2; j <= y1; j++) {
                            if (a[i][j] == 0) {
                                flag++;
                                break;
                            }
                            r++;
                        }
                        if (flag) {
                            break;
                        }
                    }
                    if (!flag && r > ret) {
                        ret = r;
                    }
                }
            }
        }
    }
    cout << ret;
    return 0;
}