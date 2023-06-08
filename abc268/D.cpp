#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	int n, m;
    cin >> n >> m;
    
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    set<string> used;
    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        used.insert(t);
    }
    
    int sum = n - 1;
    for (int i = 0; i < n; i++) {
        sum += s[i].length();
    }
    
    int more = 16 - sum;
    
    vector<bool> vis(n);
    
    function<void(string, int)> dfs = [&](string t, int more) {
        if (vis == vector(n, true)) {
            if (3 <= t.length() && t.length() <= 16 && !used.count(t)) {
                cout << t << "\n";
                exit(0);
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            if (t.empty()) {
                dfs(s[i], more);
            } else {
                for (int j = 0; j <= more; j++) {
                    dfs(t + string(1 + j, '_') + s[i], more - j);
                }
            }
            vis[i] = false;
        }
    };
    dfs("", more);
    
    cout << -1 << "\n";
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