#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
int f[N];
void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++){
		int x;
		cin >> x;
		for(int j = n ; j >= x ; j--)
			f[j] = max(f[j],f[j - x] + x);
	}

	cout << f[n] << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
