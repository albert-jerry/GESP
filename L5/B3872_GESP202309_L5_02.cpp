/*
# B3872 [GESP202309 五级] 巧夺大奖

## 题目背景

对应的选择、判断题：<https://ti.luogu.com.cn/problemset/1131>

## 题目描述

小明参加了一个巧夺大奖的游戏节目。主持人宣布了游戏规则：

1. 游戏分为 $n$ 个时间段，参加者每个时间段可以选择一个小游戏。

2. 游戏中共有 $n$ 个小游戏可供选择。

3. 每个小游戏有规定的时限和奖励。对于第 $i$ 个小游戏，参加者必须在第 $T_i$ 个时间段结束前完成才能得到奖励 $R_i$。

小明发现，这些小游戏都很简单，不管选择哪个小游戏，他都能在一个时间段内完成。关键问题在于，如何安排每个时间段分别选择哪个小游戏，才能使得总奖励最高？

## 输入格式

输入第一行，包含一个正整数 $n$。$n$ 既是游戏时间段的个数，也是小游戏的个数。约定 $1\le n\le500$。

输入第二行，包含 $n$ 个正整数。第 $i$ 个正整数为 $T_i$，即第 $i$ 个小游戏的完成期限。约定 $1\le T_i\le n$。

输入第三行，包含 $n$ 个正整数。第 $i$ 个正整数为 $R_i$，即第 $i$ 个小游戏的完成奖励。约定 $1\le R_i\le 1000$。

## 输出格式

输出一行，包含一个正整数 $C$，为最高可获得的奖励。

## 输入输出样例 #1

### 输入 #1

```
7
4 2 4 3 1 4 6
70 60 50 40 30 20 10
```

### 输出 #1

```
230
```

## 说明/提示

**样例解释 1**

$7$ 个时间段可分别安排完成第 4、2、3、1、6、7、5 个小游戏，其中第 4、2、3、1、7 个小游戏在期限内完成。因此，可以获得总计 $40+60+50+70+10=230$ 的奖励。
*/
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
    int t, r;
};

int main() {
    int n;
    scanf("%d", &n);
    node a[500];
    int b[500];
    for (int i = 0; i < n; i++) {
        b[i] = -1;
        scanf("%d", &a[i].t);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].r);
    }
    for (int i = n; i > 0; i--) {
        int maxz = 0, wz = -1;
        for (int j = 0; j < n; j++) {
            int fl = 1;
            for (int k = 0; k < n; k++) {
                if (b[k] == j) {
                    fl--;
                    break;
                }
            }
            if (fl && a[j].t >= i && a[j].r > maxz) {
                wz = j;
                maxz = a[j].r;
            }
        }
        b[i - 1] = wz;
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            ret += a[b[i]].r;
        }
    }
    cout << ret;
    return 0;
}