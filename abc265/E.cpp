#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;

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
	cin >> n >> m;
	LL a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	set<array<LL,2>> bad;
	for(int i = 0 ; i < m ; i++){
		int x,y;
		cin >> x >> y;
		bad.insert({x,y});
	}

	vector dp(n + 1,vector(n + 1,vector<Z>(n + 1)));
	dp[0][0][0] = 1;
	Z ans = 0;
    // 枚举各个传送的数量
	for(int i = 0 ; i <= n ; i++) 
		for(int j = 0 ; i + j <= n ; j++)
			for(int k = 0 ; i + j + k <= n ; k++){
				if(bad.count({i * a + j * c + k * e,i * b + j * d + k * f})){
					dp[i][j][k] = 0;
				}
				if(i + j + k < n){
					dp[i + 1][j][k] += dp[i][j][k];
					dp[i][j + 1][k] += dp[i][j][k];
					dp[i][j][k + 1] += dp[i][j][k];
				}else ans += dp[i][j][k];
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