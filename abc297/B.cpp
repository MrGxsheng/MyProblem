#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	string s;
	cin >> s;

	map<char,int> mp,mpp;

	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == 'B' && mp[s[i]]){
			if(((i + 1) & 1 ) == ( mp[s[i]] & 1 ) ){
				cout << "No" << endl;
				return;
			}
		} 

		if(s[i] == 'K' && (!mp['R'] || mpp['R'] == 2)){
			cout << "No" << endl;
			return;
		}

		mp[s[i]] = i + 1;
		mpp[s[i]]++;

	}

	cout << "Yes" << endl;
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