#include <iostream>
using namespace std;

struct zd {
    string a, b;
} a[100];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].a >> a[i].b;
    }
    string s;
    cin >> s;
    int sl = s.size();
    string s1 = "";
    for (int i = 0; i < sl; i++) {
        if (!(s[i] >= 'a' && s[i] <= 'z')) {
            cout << s[i];
        } else {
            s1 = "";
            s1 = s1 + s[i];
            i++;
            while (s[i] >= 'a' && s[i] <= 'z' && i < sl) {
                s1 += s[i];
                i++;
            }
            i--;
            int f = -1;
            for (int j = 0; j < n; j++) {
                if (s1 == a[j].a) {
                    f = j;
                    break;
                }
            }
            if (f >= 0) {
                cout << a[f].b;
            } else {
                cout << "UNK";
            }
        }
    }
    return 0;
}