/**
 * 带权并查集
 */
#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
int p[N];
int d[N];

int find(int x){
	if(p[x] != x){
		int root = find(p[x]);
		d[x] += d[p[x]];
		p[x] = root;
	} 
	return p[x];
}

void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) p[i] = i;
	int res = 0;
	while(m--){
		int op ,a ,b;
		cin >> op >> a >> b;
		if(a > n || b > n ) res++;
		else{
			int pa = find(a);
			int pb = find(b);
			if(op == 1){
				if(pa == pb && (d[a] - d[b]) % 3) res++;
				else if(pa != pb){
					p[pa] = pb;
					d[pa] = d[b] - d[a];
				}
			}else{
				if(pa == pb && (d[a] - d[b] - 1) % 3) res++;
				else if(pa != pb){
					p[pa] = pb;
					d[pa] = d[b] - d[a] + 1;
				}
			}
		}
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
