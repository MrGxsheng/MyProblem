#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
map<char,int> mp;

bool check(char x){
	if(x == 'C' || x == 'G' || x == 'H' || x == 'J' || x == 'L' || x == 'W' || x == 'X' || x == 'Y' || x == 'Z') return true;
	return false;
}

void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		char a;
		cin >> a;
		mp[a]++;
	}

	while(m--){
		char x;
		cin >> x;
		if(mp[x] && check(x)) printf("%d OrzOrzOrz\n",mp[x]);
		else if(mp[x]) cout << mp[x] << endl;
		else cout << 0 << endl;
	}
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
