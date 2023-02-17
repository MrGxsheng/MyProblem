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
	vector<int> a(n + 1);
	// memset(f,-0x3f,sizeof f);
	// f[0] = 0;
	for(int i = 1; i <= n ; i++) cin >> a[i];
	f[0] = 1; //初始化！！！
	for(int i = 1 ; i <= n ; i++)
		for(int j = m ; j >= a[i] ; j--)
			f[j] = f[j] + f[j - a[i]];
	cout << f[m] << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
