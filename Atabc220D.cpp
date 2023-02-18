#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
LL mod = 998244353;
int n,m;
LL f[N][10];
void solve(){
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n ; i++) 
		cin >> a[i];
	
	f[1][a[1] % 10] = 1;
	for(int i = 2; i <= n ; i++)
		for(int j = 0 ; j < 10 ; j++)
			if(f[i - 1][j]){
				f[i][(j + a[i]) % 10] = f[i - 1][j] % mod + f[i][(j + a[i]) % 10] % mod;
				f[i][(j * a[i]) % 10] = f[i - 1][j] % mod + f[i][(j * a[i]) % 10] % mod;
			}
			

	for(int i = 0 ; i < 10 ; i++) cout << f[n][i] % mod << endl;

}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
