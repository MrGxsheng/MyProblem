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
	n = s.size();
	vector<int> a(n + 1);
	map<int,int> st;

	for(int i = 0 ; i < n ; i++){
		a[i + 1] = a[i] + (s[i] == '+' ? 1 : -1);
		st[a[i + 1]] = i + 1;
	}

	int ans = 0;
	for(int i = 0 ; i <= n ; i++) 
		ans = max(ans,st[a[i]] - i);
	
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