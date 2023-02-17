#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
void solve(){
	LL k,b,s;
	cin >> n >> k >> b >> s;
	LL cur = s / k;
    if (b > cur) {
        cout << "-1\n";
        return;
    }
    
    vector<LL> a(n);
    a[0] = s;
    
    for (int i = 1; i < n; i++) {
        if (cur > b && a[0] >= k) {
            cur -= (a[0] % k != k - 1);
            a[0] -= k - 1;
            a[i] = k - 1;
        }
    }
    
    if (cur != b) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
