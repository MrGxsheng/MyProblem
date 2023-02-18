#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
int n,m;
void solve(){
	cin >> n;

	vector<int> p(n);
	int r = n , x = 2 *sqrt(n);
	while(r > 0){
		while(x * x > 2 * r - 2) x--;
		int v = x * x;
		for(int i = v - r + 1  ; i < r ; i ++) p[i] = v - i;
		r = v - r  + 1;
	}

	for(int i = 0 ; i < n ; i++) cout << p[i] << " \n"[i == n - 1];
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
