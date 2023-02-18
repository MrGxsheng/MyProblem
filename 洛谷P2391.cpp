/**
 * 并查集维护序列连通性
 */
#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m,p,q;
int fa[N];
int color[N];
int find(int x){
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

void solve(){
	cin >> n >> m >> p >> q;
	for(int i = 1 ; i <= n ; i++) fa[i] = i;
	for(int i = m ; i >= 1 ; i--){ //依照题意，倒序染色（颜色以最后一次染上的颜色为准）
		int l = (i * p + q) % n + 1;
		int r = (i * q + p) % n + 1;
		if(l > r) swap(l,r);
		for(int j = r ; j >= l;){
			int pa = find(j);
			if(pa == j){
				color[j] = i;
				fa[j] = find(j - 1); //维护连通性
			}
			j = fa[j]; //直接跳到下一个可染色的点
		}
	}
	for(int i =1 ; i <= n ; i++)
		cout << color[i] << endl;
	
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
