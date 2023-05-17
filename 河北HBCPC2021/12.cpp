#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	vector<PII> ans;
	while(n > m){
		ans.push_back({(n * 2 + 2) / 3,2});
		n = (n * 2 + 2) / 3;
	}

	   while(n <= m / 2) {
        ans.push_back({n * 2 - 1, 2});
        n = n * 2 - 1;
    }
    if (n < m) ans.push_back({m, 2});
    cout << ans.size() << endl;
    for (auto v : ans) cout << v.first << ' ' << v.second << endl;
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