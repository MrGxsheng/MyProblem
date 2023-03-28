#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int cnt[10];
void solve(){
	map<vector<int>,int> mp;
	string s;
	cin >> s;
	LL ans = 0;

	vector<int> v;
	for(int i = 0 ; i <= 9 ; i++) v.push_back(0);
	mp[v]++;

	for(int i = 0 ; i < s.size() ; i++){
		v.clear();
		cnt[s[i] - '0']++;
		for(int j = 0 ; j <= 9 ; j ++) v.push_back(cnt[j] & 1);
		ans += mp[v];
		mp[v] ++;
	}

	cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}