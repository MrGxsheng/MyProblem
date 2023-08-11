#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;

 
LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    LL g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

void solve(){
	LL A,B,x;
	cin >> A >> B >> x;
	if(A > B){
		swap(A,B);
	}

	LL u,v;
	LL g = exgcd(A,B,u,v);
	A /= g,
	B /= g;
	if(x % g != 0){
		cout << -1 << endl;
		return;
	}

	x /= g;

	u = (u * x % B + B) % B;
	v = (x - u * A) / B;

	LL ans = 1E18;
	if(v >= 0){
		ans = min(ans,2 * (u + v));
	}

	u -= B;
	v += A;
	ans = min(ans,2  *(-u + v) - 1);

	v = (v % A + A) % A;
	u = (x - v * B) / A;
	if(u >= 0){
		ans = min(ans,2 * (u + v));
	}

	v -= A;
	u += B;
	ans = min(ans, 2 * (u - v) - 1);
	cout << ans << endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}