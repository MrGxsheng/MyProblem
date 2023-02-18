#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010,mod = 100003;
int n,m;
bool st[1010][1010];
int f[1010][1010];
void solve(){
	cin >> n >> m;
	while(m--){
		int x,y;
		cin >> x >> y;
		st[x][y] = true;
	}

	f[1][1] = 1;
	for(int i = 1; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++){
			f[i][j] += f[i - 1][j] + f[i][j - 1];
			if(st[i][j]) f[i][j] = 0;
			f[i][j] = f[i][j] % mod;
		}

	cout << f[n][n] % mod << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
