#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	string s,ss;
	cin >> s >> ss;
	if(ss.size() < s.size()){
		cout << "No" << endl;
		return;
	}

	ss = ss.substr(0,s.size());
	if(ss != s) cout << "No" << endl;
	else cout << "Yes" << endl;
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