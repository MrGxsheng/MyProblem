#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m,k;
constexpr int P = 998244353;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};
void solve(){
	cin >> n >> m >> k;
	vector<Z> fac(n + 1) ,invfac(n + 1);
	fac[0] = 1;
	for(int i = 1 ; i <= n ; i++)
		fac[i] = fac[i - 1] * i;
	invfac[n] = fac[n].inv();
	for(int i = n ; i ; i--)
		invfac[i - 1] = invfac[i] * i;

	vector<int> deg(n);
	for(int i = 0 ; i < m ; i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		deg[u] ^= 1;
		deg[v] ^= 1;
	}

	const int cnt0 = count(deg.begin(), deg.end(),0);
	const int cnt1 = n - cnt0;

	Z ans = 0;
	for(int i = 0 ; i <= cnt1 && i <= k ; i += 2){
		if(k - i <= cnt0)
			ans += fac[cnt0] * invfac[k - i] * invfac[cnt0 - (k - i)] * fac[cnt1] * invfac[i] * invfac[cnt1 - i];
	}

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