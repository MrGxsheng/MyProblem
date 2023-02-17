#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
int f[50][50];
void solve(){
	cin >> n >> m;
	f[0][1] = 1;
	for(int i = 1; i <= m ; i++)
		for(int j = 1 ; j <= n ; j++){
			int a = j == 1 ? n : j - 1;
			int b = j == n ? 1 : j + 1;
			f[i][j] += f[i - 1][a] + f[i - 1][b];
		}
	cout << f[m][1] << endl;

}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
