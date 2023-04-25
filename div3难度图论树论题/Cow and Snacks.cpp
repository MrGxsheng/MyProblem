#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int p[N];
int siz[N];
int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) p[i] = i , siz[i] = 1;

	for(int i = 0 ; i < m ; i++){
		int a,b;
		cin >> a >> b;
		int pa = find(a);
		int pb = find(b);
		if(pa != pb){
			siz[pb] += siz[pa];	
			p[pa] = pb;
		}
	}

	int ans = 0;
	for(int i = 1 ; i <= n ; i++){
		if(p[i] == i){
			ans += siz[i] - 1;
		}
	}

	cout << m - ans << endl;
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