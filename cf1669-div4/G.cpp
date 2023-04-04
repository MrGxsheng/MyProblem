#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
char a[55][55];
void solve(){
	cin >> n >> m;

	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			cin >> a[i][j];

	for(int i = 0 ; i < m ; i++){
		int ans = 0;
		for(int j = 0 ; j < n ; j++){
			if(a[j][i] == '*') {
				ans++;
				a[j][i] = '.';
			}
			if(a[j][i] == 'o'){
				int cnt = ans;
				for(int z = j - 1; z >= j - cnt  ; z--) a[z][i] = '*';
				ans = 0;
			}
		}
		if(ans){
				int cnt = ans;
				for(int z = n - 1 ; z >= n - cnt ; z--) a[z][i] = '*';
			}
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++)
			cout << a[i][j];
		cout << endl;
	}
	cout << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}