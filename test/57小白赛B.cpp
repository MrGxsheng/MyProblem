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
	string s;
	cin >> s;

  	if(s.find('0') == s.npos){
   		cout << 0 << endl;
   		return;
   	}

	if(s[0] == '1' || s[n - 1] == '1'){
		cout << 1 << endl;
		return;
	}

	cout << 2 << endl;
 
	
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
