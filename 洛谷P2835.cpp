#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 210;
int n,m;
int p[N];
bool st[N][N];
int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve(){
	cin >> n;
	int x;
	for(int i = 1 ; i <= n ; i++) p[i] = i;
	for(int i = 1 ; i <= n ; i++) {
		while(true){
			cin >> x;
			if(!x) break;
			st[i][x] = true;
		}
	}

	for(int k = 1 ; k <= n ; k++)
		for(int i = 1 ; i <= n ; i++)
			for(int j =1 ; j <= n ; j++)
				if(st[i][k] && st[k][j]) st[i][j] = true;

	for(int i = 1; i <= n ; i++)
		for(int j =1 ; j <= n ; j++)
			if(st[i][j]) p[j] = p[i];
				
	int res = 0;
	for(int i = 1 ; i <= n ; i++) 
		if(i == p[i]) res++;
	cout << res << endl; 
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}