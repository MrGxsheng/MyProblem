#include <bits/stdc++.h>
#define endl '\n'
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int f[N][3];
int n;
PII a[N];
void solve(){
	    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i].x >> a[i].y;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    
    f[1][0] = 1;
    f[1][1] = a[1].x + a[1].y < a[2].x;
    f[1][2] = 0;
    
    for(int i = 2 ; i <= n ; i++){
        bool le = a[i - 1].x < a[i].x - a[i].y;
        bool ri = i == n || a[i].x + a[i].y < a[i + 1].x;
        f[i][2] = max({f[i -1][0],f[i - 1][1],f[i - 1][2]});


        if(ri) f[i][1] = max(f[i][1],max({f[i - 1][0],f[i - 1][1],f[i - 1][2]}) + 1);
        
        if(le){
            f[i][0] = max(f[i - 1][0],f[i - 1][2]) + 1;
            if(a[i - 1].x + a[i - 1].y < a[i].x - a[i].y) f[i][0] = max(f[i][0],f[i - 1][1] + 1);
        } 
    
    }
    
    int ans = max({f[n][0] ,f[n][1],f[n][2]});
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