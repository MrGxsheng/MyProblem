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
	cout << n - m << ' ' << 2 * m << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
