#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
vector<int> G[N];
int p[N];

int find(int x ){
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}
void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) p[i] = i;
	for(int i = 0 ; i < m ; i++){
		int u,v;
		cin >> u >> v;
		int pa = find(u);
		int pb = find(v);
		if(pa != pb)
			p[pa] = pb;
		
	}	

	int k;
	cin >> k;
	map<PII,int> mp;
	for(int i = 0 ; i < k ; i++){
		int x,y;
		cin >> x >> y;
		mp[{find(x),find(y)}]++;
	}

	int Q;
	cin >> Q;
	while(Q--){
		int p1,p2;
		cin >> p1 >> p2;
		int pa = find(p1);
		int pb = find(p2);

		if(mp[{pa,pb}] || mp[{pb,pa}]) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}