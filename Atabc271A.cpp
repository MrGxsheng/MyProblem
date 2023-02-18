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
	vector<char> a(100);
	for(int i = 0 ; i <= 9 ; i++) a[i] = i + '0';
	for(int i = 10 ; i <= 16 ; i++) a[i] = i - 10 + 'A';
	cout << a[n / 16] << a[n % 16] << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
