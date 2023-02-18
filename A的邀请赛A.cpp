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
	cin >> n;
	if(n == 1) puts("One Sail Wind Go");
	else if(n == 6) puts("Six Six Big Go");
	else if(n == 10) puts("Ten OK Ten OK");
	else puts("Hello , HAUE");
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
