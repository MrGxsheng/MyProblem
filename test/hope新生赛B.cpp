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
	int x,w,t,s;
	cin >> x>> w>> t >> s;
	int v = 0;
	if(w <= x)v = 2;
	else v = 1;
	if(s <= t * v) puts("YES");
	else puts("NO"); 
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}

