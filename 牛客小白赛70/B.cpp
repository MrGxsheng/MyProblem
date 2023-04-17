#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1010;
int n,m;
int a[N][N];
void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++) cin >> a[i][j];
	for(int i = 1 ; i <= n ; i += 2)
		for(int j = 1 ; j <= m ; j += 2)
			a[i][j] = (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1]) / 4;
	for(int i = 1 ; i <= n ; i += 2){
		for(int j = 1 ; j <= m ; j += 2)
			cout << a[i][j] << ' ';
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