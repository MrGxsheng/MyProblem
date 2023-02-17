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
void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	int cnt = 1;
	while(a[cnt] < a[cnt + 1]) cnt++;

	cout << a[cnt] << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
