#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m,k;
LL s;
LL a[N];
LL res;

void dfs(int x , int y , LL cnt , LL num , int idx){
	if(x == n) x = idx , y += 1;
	if(num < a[y] || y == k){
		res = max(res,cnt);
		return;
	}
	dfs(x + 1, y , cnt + 1 , num - a[y],idx);

}

void solve(){
	cin >> n >> k >> m;
	for(int i = 0 ; i < k ; i ++) {
		cin >> a[i];
		s += a[i];
	}
	
	sort(a,a + k);

	int b = 0;
	if(k >= 1) b = m / s;

	if(s == 0 || b >= n){
		cout << k * n + n<< endl;
		return;
	}

	if(b)
		for(int i = 0 ; i <= min(b,n); i++)
			dfs(i , 0, k * i + i , m - s * i , i);
	
	else dfs(0,0,0,m,0);
	
	cout << res << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
