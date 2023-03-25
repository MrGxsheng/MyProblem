#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 20;
LL n,t,p;
LL a[N],b[N],c[N],x[N],y[N];
LL ans;
bool st[N];
void dfs(int u, LL cnt , LL tt){
    if(tt <= t) ans = max(ans,cnt);
    if(tt > t) return;
	if(u == n){
		ans = max(ans,cnt);
		return;
	}

    for(int i = 0 ; i < n ; i++){
        if(!st[i]){
            st[i] = true;
            dfs(u + 1,cnt + max(c[i],a[i] - (tt + x[i]) * b[i] - y[i] * p), tt + x[i]);
            st[i] = false;
        }
    }
    
	dfs(u + 1 ,cnt ,tt);
}

void solve(){
	cin >> n >> t >> p;	
	for(int i = 0 ; i < n ; i++) cin >> a[i] >> b[i] >> c[i] >> x[i] >> y[i];
	dfs(0,0,0);
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