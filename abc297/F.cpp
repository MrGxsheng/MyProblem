#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010 , mod = 998244353;
int n,m;
LL fact[N];
LL factInv[N];
LL inv[N];

void compute(){
	fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
 
    inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }
 
    factInv[0] = factInv[1] = 1;
    for (int i = 2; i < N; i++) {
        factInv[i] = factInv[i - 1] * inv[i] % mod;
    }    
}

LL qmi(LL a , LL b){
	LL res = 1;
	while(b > 0){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}

	return res;
}

LL binom(LL n, LL k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return (fact[n] * factInv[k] % mod) * factInv[n - k] % mod;
}

void solve(){
	compute();
    int h, w, k; cin >> h >> w >> k;
    vector<vector<LL>> xx(h, vector<LL>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if ((i + 1) * (j + 1) < k) continue;
            xx[i][j] = binom((i + 1) * (j + 1), k) * qmi(binom(h * w, k), mod - 2) % mod;
        }
    }
 
    vector<vector<LL>> xxexact(h, vector<LL>(w));
    xxexact[0][0] = xx[0][0];
    for (int i = 1; i < h; i++) xxexact[i][0] = (xx[i][0] - xx[i - 1][0] + mod) % mod;
    for (int i = 1; i < w; i++) xxexact[0][i] = (xx[0][i] - xx[0][i - 1] + mod) % mod;
    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            xxexact[i][j] = (xx[i][j] - xx[i - 1][j] - xx[i][j - 1] + xx[i - 1][j - 1] + 2 * mod) % mod;
        }
    }
    
    LL ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans += xxexact[i][j] * (i + 1) * (j + 1) % mod;
            ans += xxexact[h - 1 - i][w - 1 - j] * (i + 1) * (j + 1) % mod;
            ans -= xxexact[i][w - 1 - j] * (i + 1) * (j + 1) % mod;
            ans -= xxexact[h - 1 - i][j] * (i + 1) * (j + 1) % mod;
            ans += xxexact[i][j] * (i + 1) % mod;
            ans += xxexact[i][j] * (j + 1) % mod;
            ans -= xxexact[h - 1 - i][j] * (i + 1) % mod;
            ans -= xxexact[i][w - 1 - j] * (j + 1) % mod;
            ans += 4LL * mod;
            ans %= mod;
        }
    }
    (++ans) %= mod;
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