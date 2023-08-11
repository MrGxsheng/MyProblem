#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 210;
char s[N][N],vs[N][N];
void solve(){
	int n;
    cin >> n;
    for(int i = 1 ;i <= n; i++) 
    	for(int j = 1 ; j <= n ; j++)
      		cin >> s[i][j];
    
    for(int i = n;i >= 1;i --) {
        if(i == 1) vs[1][1] = s[2][1];
        else vs[1][i] = s[1][i - 1];
    } 
    for(int i = n;i >= 2;i --) vs[i][n] = s[i - 1][n];
    for(int i = 1;i < n;i ++) vs[n][i] = s[n][i + 1];
    for(int i = 2;i < n;i ++) vs[i][1] = s[i + 1][1];
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            if(i == 1 || j == 1 || i == n || j == n) cout << vs[i][j];
            else cout << s[i][j];
        }
        cout << endl;
    }
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