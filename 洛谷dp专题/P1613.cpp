#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
bool g[55][55][66];
int d[55][55];
void solve(){
	cin >> n >> m;
	memset(g,false,sizeof g);
	memset(d,10,sizeof d);

	for(int i = 1 ; i <= m ; i++){
		int u,v;
		cin >> u >> v;
		d[u][v] = 1;
		g[u][v][0] = true;
	}

    for(int k = 1 ; k <= 64 ; k++)
    	for(int i = 1 ; i <= n ; i++)
    		for(int t = 1 ; t <= n ; t++)
    			for(int j = 1 ; j <= n ; j++)
    				if(g[i][t][k - 1] && g[t][j][k - 1]){
    					g[i][j][k] = true;
    					d[i][j] = 1;
    				}
    for(int k = 1 ; k <= n ; k++)
    	for(int i = 1 ; i <= n ; i++)
    		for(int j = 1 ; j <= n ; j++)
    			d[i][j] = min(d[i][j],d[i][k] + d[k][j]);

    cout << d[1][n] << endl;

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