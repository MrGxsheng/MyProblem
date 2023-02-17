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
	int a,b,c;
	cin >> a >> b >> c;
	int x = a - 1;
	int y = abs(c - b) + c - 1;
	if(x < y) cout << 1 << endl;
	else if(x > y) cout << 2 << endl;
	else cout << 3 << endl;

}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
