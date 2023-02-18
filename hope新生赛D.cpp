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
	vector<int> a(n);
	LL s = 0;
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i];
		s += a[i];
	}

	if(s % 2 == 0) puts("lmsyyds");
	else puts("djhnb");
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
