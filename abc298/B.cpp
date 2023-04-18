#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 110;
int n,m;
int a[N][N];
int b[N][N];
int c[N][N];
bool turn(){
	memcpy(c,a,sizeof c);
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++){
			a[i][j] = c[n + 1 - j][i];
		}

	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			if(a[i][j] == 1)
				if(b[i][j] != 1) return false;
	return true;
}

void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			cin >> a[i][j];
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			cin >> b[i][j];

	for(int i = 0 ; i < 4 ; i++){
		if(turn()){
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;

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