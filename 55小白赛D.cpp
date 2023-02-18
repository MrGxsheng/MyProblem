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
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1 ; i <= n ; i++) cin >> a[i];

	int res = 0;
	for(int i = 1 ; i <= n ; i++)
		res += a[i] - i;
	if(res == 0) puts("SSZ");
	else if(res % 2 == 0) puts("SSZ");
	else cout << puts("ZZZ");
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}

