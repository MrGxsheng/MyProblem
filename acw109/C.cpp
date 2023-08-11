#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 21;
int n,m;
int a[N], b[N];
double v;
void solve(){
	cin >> n >> v;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) cin >> b[i];
    if (n == 1) // 如果只有一种饮品
	{
        cout << fixed << setprecision(4) << (b[1] > v ? v : b[1]) << endl; // 判断是否大于v
        return;
    }
    double minv = 1e9;
    for (int i = 1; i <= n; i ++ ) 
    {
        double x = b[i] * 1.0 / a[i];
        minv = min(minv, x); // 找出最小“性价比”
    }
    double ans = 0;
    for (int i = 1; i <= n; i ++ ) ans = ans + minv * a[i]; // 相加
    if (ans > v) cout << fixed << setprecision(4) << v << endl; // 判断是否大于v
    else cout << fixed << setprecision(4) << ans << endl;

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