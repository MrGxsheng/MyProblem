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
	if(s == "^"){
		cout << 1 << endl;
		return;
	}

	s = "^_" + s + "_^";
	n = s.size();

	vector<int> p;
	for(int i = 0 ; i < n ; i++)
		if(s[i] == '^')
			p.push_back(i);
	int ans = 0;
	for(int i =  1 ; i < p.size() ; i++)
		ans += max(0,p[i] - p[i - 1] - 2);
	cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}