#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 100010;
int n,m;
vector<int> G[N];
void solve(){
	cin >> n >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    
    int ans = 0x3f3f3f3f;
    for(int i = 1 ; i <= n ; i++){
        for(auto x : G[i]){
            if(x == i) continue;
            for(auto z : G[x]){
                if(z == x) continue;
                for(auto k : G[z]){
                    if(k == z) continue;
                    if(k == i){
                         int cnt = G[i].size() + G[x].size() + G[z].size() - 6;
                        ans = min(cnt,ans);
                        break;
                    }
                }
            }
        }
    }
    if(ans == 0x3f3f3f3f){
        cout << -1 << endl;
    }else cout << ans << endl;
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