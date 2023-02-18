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
	vector<int> a(n);
	for(int i = 0 ; i < n ; i ++) cin >> a[i];
	sort(a.begin(),a.end());
	cout << a[n - 1] + a[n - 2] - a[0] - a[1] << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
