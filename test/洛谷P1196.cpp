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
int size[N],d[N];

int find(int x){
	if(p[x] != x){
		int root = find(p[x]);
		d[x] += d[p[x]];
		p[x] = root;
	}
	return p[x];
}

void solve(){
	cin >> n;
	char op;
	int a,b;
	for(int i = 1 ; i <= 300010 ; i++){
		p[i] = i;
		size[i] = 1;
	}
	for(int i = 1; i <= n ; i++) {
		cin >> op >> a >> b;
		if(op == 'M'){
			int pa = find(a);
			int pb = find(b);
			d[pa] = size[pb];
			size[pb] += size[pa];
			p[pa] = pb;
		}else {
			int pa = find(a);
			int pb = find(b);
			if(pa != pb) puts("-1");
			else 
				printf("%d\n", max(0,abs(d[a] - d[b]) - 1));
		}
	}
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
