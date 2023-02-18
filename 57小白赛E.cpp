#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;

bool check (int n){
	int len = 0;
	int tmp;
	while(n){
		tmp = (n & 1);
		n >>= 1;
		if (tmp) len ++;
		else len = 0;
		if (len == 3) return true; 
	}
	return false;
}

void solve(){
	string s;
	cin >> s;
	LL n = 0;
	bool st = false;
	for (int i = 0; i < s.length(); i++){
		if (st){
			n += (1ll << (s.length() - i - 1));
			continue;
		}
		if (s[i] > '1') st = true, n += (1ll << (s.length() - i - 1));
		if (s[i] == '1') n += (1ll << (s.length() - i - 1));
	}

	LL res = 0;
	for(int i = 1 ; i <= n ; i++)
		if(check(i)) res++;
	cout << res << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
