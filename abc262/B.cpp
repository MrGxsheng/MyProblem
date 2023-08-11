#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 110;
int n,m;
int d[N][N];
void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++){
		int u,v;
		cin >> u >> v;
		d[u][v] = 1;
		d[v][u] = 1;
	}

	LL ans = 0;
	for(int i = 1 ; i <= n ; i++)
		for(int j = i + 1 ; j <= n ; j++)
			for(int z = j + 1 ; z <= n ; z++)
				if(d[i][j] && d[j][z] && d[i][z])
					ans++;

	cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}