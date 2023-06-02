#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
LL f[55][55],root[55][55];

void dfs(int l , int r){
	if(l > r) return;
	cout << root[l][r] << ' ';
	if(l == r) return;
	dfs(l,root[l][r] - 1);
	dfs(root[l][r] + 1,r);
}

void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		cin >> f[i][i];
		f[i][i - 1] = 1;
		root[i][i] = i;
	}

	for(int len = 1 ; len < n ; len++)
		for(int l = 1 ; l + len <= n ; l++){
			int r = l + len ;
			f[l][r] = f[l + 1][r] + f[l][l];
			root[l][r] = l;
			for(int k = l + 1 ; k < r ; k++)
				if(f[l][r] < f[l][k - 1] * f[k + 1][r] + f[k][k]){
					f[l][r] = f[l][k - 1] * f[k + 1][r] + f[k][k];
					root[l][r] = k;
				}
		}

	cout << f[1][n] << endl;

	dfs(1,n);

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