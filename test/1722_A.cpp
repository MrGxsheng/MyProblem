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
	cin >> n >> s;
	if(n != 5) {
		puts("NO");
		return;
	}


	map<char,int> mp;
	for(int j = 0 ; j < 5 ;  j++)
		mp[s[j]]++;
	if(mp.size() == 5 && mp['T'] == 1 && mp['i'] == 1 && mp['m'] == 1 && mp['u'] == 1 && mp['r'] == 1){
		puts("YES");
		return;

	}

	puts("NO");

}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
