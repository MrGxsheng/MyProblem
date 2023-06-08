#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

void solve(){
	cin >> n;
	vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
	
	DSU dsu(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(x[i] - x[j]) == 1 && y[i] == y[j]) {
                dsu.merge(i, j);
            }
            if (abs(y[i] - y[j]) == 1 && x[i] == x[j]) {
                dsu.merge(i, j);
            }
            if (abs(x[i] - x[j]) == 1 && x[i] - x[j] == y[i] - y[j]) {
                dsu.merge(i, j);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dsu.leader(i) == i;
    }
    cout << ans << "\n";
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