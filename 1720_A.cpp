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
	LL a,b,c,d;
	cin >> a >> b >> c >> d;
	a = a * d;
	c = c * b;
	if(a == c) cout << 0 << endl;
	else if(a == 0 || c == 0) cout << 1 << endl;
	else if(a % c == 0 || c % a == 0) cout << 1 << endl;
	else cout << 2 << endl;
	
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
