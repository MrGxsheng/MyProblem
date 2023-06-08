#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const LL N = 1000010;
constexpr LL P = 998244353;
LL n,m;
void solve(){
	cin >> n;
	n %= P;
	if(n < 0) n += P;
	cout << n << endl;
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