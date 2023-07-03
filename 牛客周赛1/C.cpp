#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
char s[N];
int q[N], q1[N];
int hh, tt, hh1, tt1;
int n = 0;

ll s1() {
    ll res = 0;
    hh = tt = 0;
    hh1 = tt1 = 0;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            if (s[i] == '0') {
                if(hh1 < tt1) {
                    res += i - q1[hh1++];
                }
                else q[tt++] = i;
            }
        }
        else {
            if (s[i] == '1') {
                if (hh < tt) {
                    res += i - q[hh++];
                }
                else q1[tt1++] = i;
            }
        }
    }
    return res;
}
ll s2() {
    ll res = 0;
    hh = tt = 0;
    hh1 = tt1 = 0;
    for (int i = 1; i <= n; i++) {
        if (~i & 1) {
            if (s[i] == '0') {
                if(hh1 < tt1) {
                    res += i - q1[hh1++];
                }
                else q[tt++] = i;
            }
        }
        else {
            if (s[i] == '1') {
                if (hh < tt) {
                    res += i - q[hh++];
                }
                else q1[tt1++] = i;
            }
        }
    }
    return res;
}

void solve(){
	int x = 0, y = 0;
    while (true) {
        s[++n] = getchar();
        if (s[n] == '\n')break;
        if (s[n] == '0')y++;
        else x++;
    }
    n--;
    if ((x + y) & 1) {
        if (x > y) {
            cout << s1();
        }
        else {
            cout << s2();
        }
    }
    else {
        cout << min(s1(), s2());
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}