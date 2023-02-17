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
int t[N];
struct Node
{
	int x,y,t;
	bool operator < (const Node &w) const{
		return t < w.t;
	}
}a[N];
int find(int x){
	if(p[x] != x) {
		t[p[x]] = min(t[p[x]] , t[x]);
		p[x] = find(p[x]);
	}

	return p[x];
}

void solve(){
	cin >> n >> m;
	memset(t,0x3f3,sizeof t);
	for(int i = 1 ; i <= n + 1 ; i++) p[i] = i;
	int pa,pb;

	for(int i = 1 ; i <= m ; i++) cin >> a[i].x >> a[i].y >> a[i].t;
	sort(a + 1 , a + 1 + m);
	
	for(int i = 1 ; i <= m ; i++){
		pa = find(a[i].x);
		pb = find(a[i].y);
		if(pa != pb) p[pa] = pb , n--;
		if(n == 1){
			cout << a[i].t << endl;
			return;
		} 
	}

	cout << -1 << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
