#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m,e;
using i64 = long long;
 
struct DSU {
    std::vector<int> f, siz, elec;
    DSU(int n) : f(n), siz(n, 1), elec(n) { std::iota(f.begin(), f.end(), 0); }
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
        elec[x] |= elec[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

void solve(){
	cin >> n >> m >> e;

	vector<int> u(e),v(e);
	for(int i = 0 ; i < e ; i++){
		cin >> u[i] >> v[i];
		u[i]--;
		v[i]--;
	}

	int q;
	cin >> q;
	vector<int> a(q);
	vector<bool> del(e);

	for(int i = 0 ; i < q ; i++){
		cin >> a[i];
		a[i]--;
		del[a[i]] = true;
	}

	DSU dsu(n + m);
	for(int i = n ; i < n + m ; i++){
		dsu.siz[i] = 0;
		dsu.elec[i] = 1;
	}

	int cur = 0;
	auto merge = [&](auto x,auto y){
		 if (dsu.same(x, y)) {
            return;
        }
        x = dsu.leader(x);
        y = dsu.leader(y);
        cur -= dsu.siz[x] * dsu.elec[x];
        cur -= dsu.siz[y] * dsu.elec[y];
        dsu.merge(x, y);
        cur += dsu.siz[x] * dsu.elec[x];
	};

	vector<int> ans(q);
	for(int i = 0 ; i < e ; i++)
		if(!del[i])
			merge(u[i],v[i]);

	for (int i = q - 1; i >= 0; i--) {
        ans[i] = cur;
        merge(u[a[i]], v[a[i]]);
    }
    	
	for(int i = 0 ; i < q ; i++){
		cout << ans[i] << endl;
	}
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