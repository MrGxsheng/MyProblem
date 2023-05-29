#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	vector f(n, std::vector(n, 1));
    for (int i = 0; i < m; i++) {
        vector<int> A(n);
        for (int j = 0; j < n; j++) {
            cin >> A[j];
            A[j]--;
        }
        for  (int j = 1; j < n; j++) {
            int x = A[j - 1], y = A[j];
            f[x][y] = f[y][x] = 0;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += f[i][j];
        }
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