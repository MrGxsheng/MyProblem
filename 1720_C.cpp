#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
int a[510][510];
void solve(){
	cin >> n >> m;
	int res = 0;
	for(int i = 1 ; i <= n ; i++) 
		for(int j = 1 ; j <= m ; j++){
			scanf("%1d",&a[i][j]);
			res += a[i][j];
	}
	
	int t = 100;
	for(int i = 1 ; i <= n - 1; i++)
		for(int j = 1 ; j <= m - 1 ; j++){
			int x1 = a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
			int x2 = a[i][j] + a[i][j + 1] + a[i + 1 ][j + 1];
			int x3 = a[i][j] + a[i + 1][j] + a[i + 1][j + 1];
			int x4 = a[i][j] + a[i + 1][j] + a[i][j + 1];

			if(x1 > 0) t = min(t,x1);
			if(x2 > 0) t = min(t,x2);
			if(x3 > 0) t = min(t,x3);
			if(x4 > 0) t = min(t,x4);
		}
	
	
	if(res > 0) res -= t - 1;
	
	
	cout << res<< endl;

}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
