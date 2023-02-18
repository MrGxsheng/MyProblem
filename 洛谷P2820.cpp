/**
 * Kruscal 算法 求最小生成树
 */
#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 110;
int n,m;
int p[N];

struct Node{
	int a,b,w;

	bool operator< (const Node &t) const{
		return w < t.w;
	}
}edge[N << 2];

int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) p[i] = i;

	for(int i = 0 ; i < m ; i++) cin >> edge[i].a >> edge[i].b >> edge[i].w;

	sort(edge,edge + m);
	
	int res = 0;
	for(int i = 0 ; i < m ; i++){
		int pa = find(edge[i].a);
		int pb = find(edge[i].b);
		int w = edge[i].w;
		if(pa != pb) p[pa] = pb;
		else res += w;
	}
	 cout << res << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
