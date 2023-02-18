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
	cin >> n >> m;
	for(int i = 1; i <= n ; i++) p[i] = i;
	int a,b,c;
	int pb,pc;
	while(m--){
		cin >> a >> b >> c;
		pb = find(b);
		pc = find(c);
		if(a == 1){
			p[pc] = pb;
		}else{
			if(pb == pc) puts("Y");
			else puts("N");
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
