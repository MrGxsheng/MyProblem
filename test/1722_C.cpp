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
	map<string,int> mp;
	string s;
	for(int i = 0 ; i < n ; i++) {
		cin >> s;
		mp[s] = 4;
	}

	for(int i = 0 ; i < n ; i++) {
		cin >> s;
		if(mp[s] == 4) mp[s] = 9;
		else mp[s] = 5;
	}

	for(int i = 0 ; i < n ; i++) {
		cin >> s;
		if(mp[s] == 4) mp[s] = 10;
		else if(mp[s] == 5) mp[s] = 11;
		else if(mp[s] == 9) mp[s] = 12;
		else mp[s] = 6;
	}

	int res1 = 0 , res2 = 0 , res3 = 0;
	for(auto i : mp){
		if(i.second == 4) res1 += 3;
		else if(i.second == 5) res2 += 3;
		else if(i.second == 6) res3 += 3;
		else if(i.second == 9) res1 += 1 , res2 += 1;
		else if(i.second == 10) res1 += 1 , res3 += 1;
		else if(i.second == 11) res2 += 1 , res3 += 1;
	}
	cout << res1 << ' ' << res2 << ' ' << res3 << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
