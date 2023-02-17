#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m,q,Q;
int p[N];
int size[N];

int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve(){
	cin >> n >> m >> q >> Q;
	for(int i = 1 ; i <= 100000 ;  i++) {
		p[i] = i;
		size[i] = 1;
	}
	while(q--){
		int a , b;
		cin >> a >> b;
		int pa = find(a);
		int pb = find(b);
		if(pa != pb){
			size[pb] += size[pa];
			p[pa] = pb;
		}
	}

	while(Q--){
		int a , b;
		cin >> a >> b;
		a += 50000;
		b += 50000;
		int pa = find(a);
		int pb = find(b);
		if(pa != pb){
			size[pb] += size[pa];
			p[pa] = pb;
		}
	}

	cout << min(size[find(1)],size[find(49999)]) << endl;

}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
