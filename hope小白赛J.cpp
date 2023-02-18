#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m,k;
int a[N];
void solve(){
	cin >> n >> k;
    int f = 0;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        if (a[i] == k) f = 1;
    }
    if (!f)
    {
        cout << "NO" << endl;
        return;
    }
    if (n == 1)
    {
        cout << "YES" << endl;
        return;
    }
    f = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] >= k && i + 1 <= n && (a[i + 1] >= k || (i + 2 <= n && a[i + 2] >= k)))
        {
            f = 1;
            break;
        }
    }
    if (f) cout << "YES" << endl;
    else cout << "NO" << endl;
    system("pause");
    return;
	

}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
