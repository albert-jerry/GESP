/*
# B3958 [GESP202403 四级] 相似字符串

## 题目背景

对应的选择、判断题：<https://ti.luogu.com.cn/problemset/1144>

## 题目描述

对于两个字符串 $A$ 和 $B$，如果 $A$ 可以通过删除一个字符，**或**插入一个字符，**或**修改一个字符变成 $B$，那么我们说 $A$ 和 $B$ 是相似的。

比如 apple 可以通过插入一个字符变成 applee，可以通过删除一个字符变成 appe，也可以通过修改一个字符变成 bpple。因此 apple 和 applee、appe、bpple 都是相似的。但 applee 并不能 通过任意一个操作变成 bpple，因此它们并不相似。

特别地，两个完全相同的字符串也是相似的。

给定 $T$ 组 $A,B$，请你分别判断它们是否相似。

## 输入格式

第一行一个正整数 $T$。  
接下来 $T$ 行，每行两个用空格隔开的字符串 $A$ 和 $B$。

## 输出格式

对组 $A,B$，如果他们相似，输出 ``similar``，否则输出 ``not similar``。

## 输入输出样例 #1

### 输入 #1

```
5
apple applee
apple appe
apple bpple
applee bpple
apple apple
```

### 输出 #1

```
similar
similar
similar
not similar
similar
```

## 说明/提示

对全部的测试数据，保证 $1 \leq T \leq 100$，$A$ 和 $B$ 的长度不超过 $50$，仅含小写字母。
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i1 = 0; i1 < t; i1++) {
        string s1, s2;
        cin >> s1 >> s2;
        int sl1 = s1.size(), sl2 = s2.size();
        if (abs(sl1 - sl2) < 2) {
            int flag = 0,fc =  -1;
            for (int i = 0; i < sl1; i++) {
                if (s1[i] != s2[i]) {
                    fc = i;
                }
            }
            if (fc != -1) {
                string s11 = s1.substr(0, fc + 1) + s2[fc] + s1.substr(fc, sl1 - fc - 1);
                string s12 = s1.substr(0, fc) + s1.substr(fc, sl1 - fc - 1);
                string s13 = s1.substr(0, fc) + s2[fc] + s1.substr(fc, sl1 - fc - 1);
                if (s11 == s2 || s12 == s2 || s13 == s2) {
                    cout << "similar\n";
                } else {
                    cout << "not similar\n";
                }
            } else {
                cout << "similar\n";
            }
        } else {
            cout << "not similar\n";
        }
    }
    return 0;
}