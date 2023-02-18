#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
void solve(){
	int a1,h1,a2,h2,x,k,a3,h3;
	cin >> a1 >> h1 >> a2 >> h2 >> x >> k >> a3 >> h3;
	LL a = (h2 + a1 / 2) / a1;
	int hack = 0;
	if(a > 1)  hack = (a - 1) * a2 * x;
	if(hack >= h1) puts("No Franxx!");
	else{
		hack += k * a3;
		LL b = (h3 + a1  / 2) / a1;
		hack += b * a3;
		if(hack >= h1) puts("No Franxx!");
		else cout << (a ? a : 1) * x  + (b ? b : 1) << endl;
	}
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
