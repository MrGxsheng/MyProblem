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

int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}


void solve(){
	int Q;
	cin >> n >> m >> Q;
	for(int i =1 ; i <= n ; i++) p[i] = i;
	int pa,pb;
	int a , b;

	while(m--){
		cin >> a >> b;
		pa = find(a);
		pb = find(b);
		p[pa] = pb;
	}

	while(Q--){
		cin >> a >> b;
		pa = find(a);
		pb = find(b);
		if(pa == pb) puts("Yes");
		else puts("No");
	}
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
