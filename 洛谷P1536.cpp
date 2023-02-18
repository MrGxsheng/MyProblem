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
	while(cin >> n , n){
		cin >> m;
		vector<int> size(n + 1,1);
		for(int i = 1 ; i <= n ; i ++) p[i] = i;

		while(m--){
			int a,b;
			cin >> a>> b;
			int pa = find(a);
			int pb = find(b);

			if(pa != pb){
				size[pb] += size[pa];
				p[pa] = pb;
			}
		}

		int cnt = 0;
		for(int i = 1 ; i <= n ; i++)
			if(p[i] == i) cnt++;
		
		cout << cnt - 1 << endl;

	}
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
