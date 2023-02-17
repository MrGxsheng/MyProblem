#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	memset(g,0,sizeof g);
	for(int i = 1 ; i <= n ; i++){
		int a,b;
		cin >> a >> b;
		g[a][b] += a * b;
	}

	for(int i = 1 ; i <= 1000 ; i ++){
		for(int j = 1 ; j <= 1000 ; j ++){
			g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
		}
	}

	while(m--){
		int a1 , b1 , a2 , b2;
		cin >> a1 >> b1 >> a2 >> b2;
		a1++,b1++,a2--,b2--;
		cout << g[a2][b2] - g[a2][b1 -1] - g[a1 - 1][b2] + g[a1 -1 ][b1 - 1]<< endl;
	}
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
