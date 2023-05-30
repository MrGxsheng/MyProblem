#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

constexpr int P = 1000000007;
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

constexpr int N = 1005;
// 表示到a串的第i个位置为止使用p个子串匹配b串前j位字符且第i个位置选或不选（v）的方案数。
Z f[2][N][N][2];

void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	string s,ss;
	cin >> s >> ss;
	s = '?' + s;
	ss = '?' + ss;
	f[0][0][0][0] = f[1][0][0][0] = 1;
	int val = 1;
	for(int i = 1 ; i <= n ; i++ ,val ^= 1 ){
		for(int j = 1 ; j <= m ; j++)
			for(int p = 1 ; p <= k ; p++){
				if(s[i] == ss[j]){
					f[val][j][p][0] = f[val ^ 1][j][p][0] + f[val ^ 1][j][p][1];
					f[val][j][p][1] = f[val ^ 1][j - 1][p][1] + f[val ^ 1][j - 1][p - 1][0] + f[val ^ 1][j - 1][p - 1][1];	
				}else{
					f[val][j][p][0] = f[val ^ 1][j][p][0] + f[val ^ 1][j][p][1];
					f[val][j][p][1] = 0;

				}
			}
	}

	cout << f[n & 1][m][k][0] + f[n & 1][m][k][1] << endl;


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