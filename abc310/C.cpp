#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	map<string,int> mp;
	vector<string> s(n);
	for(int i = 0 ; i < n ; i++){
		cin >> s[i];
		mp[s[i]]++;
	}

	int ans = n;

	for(int i = 0 ; i < n ; i++){
		if(!mp[s[i]]) continue;
		string ss = s[i];
		reverse(ss.begin(),ss.end());
		ans -= mp[ss];
		mp[ss] = 0;
		if(ss == s[i]) ans++;
		else{
			ans = ans -  mp[s[i]] + 1;
			mp[s[i]] = 0;
			
		}
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