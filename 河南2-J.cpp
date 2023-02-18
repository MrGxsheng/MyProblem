#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
int a[N];
map<LL,LL> c;
map<LL,LL> b;
void solve(){
	cin >> n;
	for(int i = 1; i <= n ; i++){ 
		cin >> a[i];
		c[a[i]] = 1;
	}

	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			b[a[i] + a[j]] = 1;

	bool st = false;
	for(int i = 1; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			if(b.count(a[i] - a[j])){
				st = true;
				break;
			}
	if(st) puts("Yes");
	else puts("No");
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
