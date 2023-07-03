#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010,mod = 1e9 + 7;
int n,m;
int f[N][10];
void solve(){
	string s;
	cin >> s;
	n = s.size();
	s = "?" + s;
	f[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 9; ++j) f[i][j] = f[i - 1][j];
        for(int j = 0; j < 9; ++j) f[i][(j + s[i] - '0') % 9]=(f[i][(j + s[i] - '0') % 9]+f[i - 1][j]) % mod;
    }
   	cout << (f[n][0] - 1 + mod) % mod;
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