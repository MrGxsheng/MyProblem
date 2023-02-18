#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m,k;
bool st[10010][10010];
void solve(){
	cin >> n >> m >> k;
	while(k--){
		int a,b;
		cin >> a >> b;
		st[a][b] = true;
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++)
			if(st[i][j]) cout << "# ";
			else cout << ". ";
			cout << endl;
	}
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
