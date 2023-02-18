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
	int now = 0;
	set<int> s;
	s.insert(0);
	int a = 0;
	int res = n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a;
		now ^= a;
		if(s.count(now)) res--,s.clear();
		s.insert(now);
	}
	cout << res << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
