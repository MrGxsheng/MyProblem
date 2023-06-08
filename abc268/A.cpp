#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	map<int,int> mp;
	mp[a]++;
	mp[b]++;
	mp[c]++;
	mp[d]++;
	mp[e]++;
	cout << mp.size() << endl;
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