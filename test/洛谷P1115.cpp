#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
int f[N];
LL s;
void solve(){
	cin >> n;
	int x = 0;
	int maxx;
	cin >> maxx;
	s = maxx;
	LL res = maxx;
	for(int i = 2 ; i <= n ; i++){
		cin >> x;
		if(s < 0) s = 0; 
		s += x;
		res = max(res,s);
	} 

	cout << res << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
