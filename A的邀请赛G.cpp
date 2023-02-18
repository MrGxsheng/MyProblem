#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)

using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m,x,y;
PII q[N];
void solve(){
	cin >> n >> m >> x >> y;
	for(int i = 1 ; i <= n ; i++){
		int a,b;
		cin >> q[i].first >> q[i].second;
	}

	while(m--){
		int a;
		cin >> a;
		x += q[a].first;
		y += q[a].second;
	}
	cout << x << ' ' << y << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
