#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
vector<int> a[N];
void solve(){
	cin >> n >> m;

	for(int i = 1; i <= n ; i++){
		int k;
		cin >> k;
		for(int j = 0 ; j < k ; j++){
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	while(m--){
		int x,y;
		cin >> x >> y;
		cout << a[x][y - 1] << endl;;
	}
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
