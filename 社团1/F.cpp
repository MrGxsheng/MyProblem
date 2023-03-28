#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 2010;
int n,m;
int l[N][N],r[N][N],a[N];
void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++ ){
		cin >> a[i];
		l[i][i] = r[i][i] = a[i];
	} 

	for(int len = 2 ; len <= n ; len++){
		for(int i = 1 ; i + len - 1 <= n ; i++){
			int j = i + len - 1;
			int L = l[i][j - 1] , R = r[i][j - 1] ,x = a[j];
			if(R == x)  l[i][j] = 0;
			else if(x > L && x > R) l[i][j] = x;
			else if(x < L && x < R) l[i][j] = x;
			else if(x < L && x > R) l[i][j] = x - 1;
			else l[i][j] = x + 1;

			L = l[i + 1][j], R = r[i + 1][j], x = a[i];
			if(L == x) r[i][j] = 0;
			else if(x > L && x > R ) r[i][j] = x;
			else if(x < L && x < R ) r[i][j] = x;
			else if(x < L && x > R ) r[i][j] = x + 1;
			else r[i][j] = x - 1;
		}
	}

	if(a[1] == l[2][n]) cout << 0 << endl;
	else cout << 1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}