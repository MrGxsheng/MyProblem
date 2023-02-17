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
void solve(){
	cin >> n;
    f[1] = 1;
    for(int i = 2 ; i <= n ; i++)
    {
         f[i] = (f[i-1] + f[i-2] + 1) % 998244353;
    }
    cout << f[n];
	
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
