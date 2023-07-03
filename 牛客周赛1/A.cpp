#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 500;
int n,m;
char a[N][N];
void solve(){
	cin >> n;
	for(int i = 0 ; i < 3 * n ; i++)
		for(int j = 0 ; j < 2 * n ; j++)
			if(j < n) a[i][j] = '*';
			else a[i][j] = '.';
	for(int i = 0 ; i < 3 * n ; i++)
		for(int j = 2 * n ; j < 4 * n ; j++)
			if(j < 3 * n) a[i][j] = '.';
			else a[i][j] = '*';

	for(int i = 3 * n ; i < 4 * n ; i++)
		for(int j = i - 3 * n + 1 ; j < i + n - 3 * n + 1 ; j++)
			a[i][j] = '*';

	for(int i = 3 * n ; i < 4 * n ; i++)
		for(int j = 0 ; j < 2 * n ; j++)
			if(a[i][j] != '*') a[i][j] = '.';

	for(int i = 3 * n ; i < 4 * n ; i++)
		for(int j = 4 * n - (i - 3 * n + 2) ; j > 4 * n - (i - 3 * n + 2) - n ; j--)
			a[i][j] = '*';

	for(int i = 3 * n ; i < 4 * n ; i++)
		for(int j = 2 * n ; j < 4 * n ; j++)
			if(a[i][j] != '*') a[i][j] = '.';

	for(int i = 0 ; i < 4 * n ; i++){
		for(int j = 0 ; j < 4 * n ; j++)
			cout << a[i][j];
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