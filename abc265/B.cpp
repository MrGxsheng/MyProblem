#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
int n,m;
void solve(){
    LL t;
	cin >> n >> m >> t;
    
    vector<int> a(n - 1), v(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        v[x] = y;
    }
    for (int i = 0; i < n - 1; i++) {
        t -= a[i];
        if (t <= 0) {
            cout << "No\n";
            return;
        }
        t += v[i + 1];
    }
    cout << "Yes\n";
    
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