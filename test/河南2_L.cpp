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
	string s;
	cin >> s;
	int len = s.length();
	int res = 0;
	if(len >= 3)
		for(int i = 0 ; i < n - 2 ; i++)
			if(s[i] == 'H' && s[i + 1] == 'P' && s[i + 2] == 'U') res++;
		
	cout << res << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
