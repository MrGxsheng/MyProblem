/**
 * 并查集+01背包
 *
 */
#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m,vol;
int p[N];
int f[N];
int v[N],w[N];

int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve(){
	cin >> n >> m >> vol;
	for(int i = 1 ; i <= n ; i ++) p[i] = i;
	for(int i = 1 ; i <= n ; i ++) cin >> v[i] >> w[i];

	while(m--){
		int a,b;
		cin >> a >> b;
		int pa = find(a);
		int pb = find(b);
		if(pa != pb){
			v[pb] += v[pa];
			w[pb] += w[pa];
			p[pa] = pb;
		}
	}

	for(int i = 1 ; i <= n ; i++)
		if(p[i] == i)
			for(int j = vol ; j >= v[i] ; j--)
				f[j] = max(f[j],f[j - v[i]] + w[i]);
	
	cout << f[vol] << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}

