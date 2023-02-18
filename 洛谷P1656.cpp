#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
#define x first
#define y second
using namespace std;
typedef long long LL;
const int N = 1000010;
typedef pair<int,int> PII;
int n,m;
int p[N];
PII q[N];
int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

bool check(int xx){
	for(int i = 1 ; i <= n ; i++) p[i] = i;
	for(int i = 1; i <= m ; i++){
		if(xx == i) continue;
		int pa = find(q[i].x);
		int pb = find(q[i].y);
		p[pa] = pb;
	}

	int cnt = 0;
	for(int i = 1 ; i <= n ; i++) if(i == find(i)) cnt++;
	if(cnt > 1) return false;
	return true;
}

void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++) {
		cin >> q[i].x >> q[i].y;
		if(q[i].x > q[i].y) swap(q[i].x,q[i].y);
	}

	sort(q ,q + m +1);
	for(int i = 1 ; i <= m ; i++){
		if(!check(i)) cout << q[i].x << ' '<< q[i].y << endl;
	}

	
}

int main(){
	int T;
	// cin >> T;
	T =1;
	while(T--) solve();
	return 0;
}
