#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;

LL n,l,r,x;

LL ans;
void solve(){
	cin >> n >> l >> r >> x;
    
    vector<int> a(n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    
   
    for (int i = 1; i < 1 << n; i ++ ){
        int mi = 2e9, mx = 0, cnt = 0;
        LL sum = 0;
        
       for (int j = 0; j < n; j ++ )
             if (i >> j & 1){
                cnt ++ ;
                mi = min(mi, a[j]);
                mx = max(mx, a[j]);
                sum += a[j];
            }
        if(cnt == 1) continue;
        if (sum >= l && sum <= r && mx - mi >= x) ans ++ ;
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