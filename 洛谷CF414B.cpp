#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010 , mod = 1000000007;
int n,m,k;
int f[2010][2010];
void solve(){
	cin >> n >> k;
	for(int i = 0 ; i <= n ; i++) f[1][i] =1;
		for(int i =2 ; i <= k ; i ++)
			for(int j = 1 ; j <= n ; j++)
				for(int k = 1 ; k * j <= n ; k++)
				f[i][j] = (f[i][j] + f[i - 1][j * k]) % mod;
	LL res = 0;
	for(int i = 1 ; i <= n ; i ++) res = (res + f[k][i]) % mod;

	cout << res % mod<< endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
