/**
 * 关于并查集的反集
 * 敌人的敌人是朋友
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

int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= 2 * n ; i++) p[i] = i;

	char op;
	int a,b;
	while(m--){
		cin >> op >> a >> b;
		if(op == 'F'){
			int pa = find(a);
			int pb = find(b);
			p[pa] = pb;
		}else {
			//反集合并
			int pa = find(a + n);
			int pb = find(b + n);
			p[pa] = find(b);
			p[pb] = find(a);
		}
	}

	int res = 0;
	for(int i = 1 ; i <= n ; i++)
		if(p[i] == i) res++; 
	cout << res << endl;	
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
