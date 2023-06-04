#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1010;
int d[N][N];
int n,m;
void solve(){
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            cin >> d[i][j];
    
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            ans = max(ans,d[i][j]);
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