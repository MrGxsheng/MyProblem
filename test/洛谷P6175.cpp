#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 110 , INF = 0x3f3f3f3f;
int n,m;
int d[N][N],g[N][N];
int pos[N][N];
int path[N];
int res;
int cnt;

// void get_path(int i, int j){
// 	if(pos[i][j] == 0) return;

// 	int k = pos[i][j];
// 	get_path(i,k);
// 	path[cnt++] = k;
// 	get_path(k,j);
// }

void solve(){
	cin >> n >> m;
	memset(g,0x3f,sizeof g);
	for(int i = 1 ; i <= n ; i++) g[i][i] = 0;

	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b],c);
	}
	res = INF;
	memcpy(d,g,sizeof d);
	for(int k = 1 ; k <= n ; k++){

		//环 k是环上最大值
		for(int i = 1 ; i < k ; i++)
			for(int j = i + 1 ; j < k ; j++)
				if((LL) d[i][j] + g[j][k] + g[k][i] < res){
					res = d[i][j] + g[j][k] + g[k][i];
					// cnt = 0;
					// path[cnt++] = k;
					// path[cnt++] = i;
					// get_path(i,j);
					// path[cnt++] = j;
				}
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1; j <= n ; j++){
				if(d[i][j] > d[i][k] + d[k][j]){
					d[i][j] = d[i][k] + d[k][j];
					// pos[i][j] = k;
				}
			}
		}
	}

	if(res == INF) puts("No solution.");
	else cout << res << endl;

}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
