#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
int v[N];
int w[N];
int f[N];
void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> v[i] >> w[i];

	for(int i = 1;  i <= n ; i++)
		for(int j  = m ; j >= v[i] ; j--)
			f[j] = max(f[j],f[j - v[i]] + w[i]);
	cout << f[m] << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
