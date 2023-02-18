#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m,k;
//将体力看做背包 将石子看做物品 
int f[N];
int v[N];
int w[N];
void solve(){
	cin >> m >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> v[i] >> w[i];

	for(int i = 1 ; i <= n ; i++)
		for(int j = k ; j >= w[i] ; j--)
			f[j] = max(f[j],f[j - w[i]] + v[i]); // 状态转移方程

	//从小到大枚举体力 靠前的剩余的体力最多
	for(int i = 1 ; i <= m ; i++){
		if(f[i] >= m){//代表能填完
			cout << k - i << endl;
			return;
		}
	}
	cout << "Impossible" << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
