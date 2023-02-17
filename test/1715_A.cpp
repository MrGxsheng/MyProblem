#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	if(n == 1 && m == 1) cout << 0 << endl;
	else cout << max(n,m) + min(m,n) * 2 - 2 << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
