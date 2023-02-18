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
	int res = 0;
	if(abs(n) == 1) res = 2; 
	else{
		res = abs(n) / 3;
		if(n % 3) res++;
	}
	cout << res << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
