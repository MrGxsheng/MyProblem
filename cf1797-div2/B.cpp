#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,k;
void solve(){
	cin >> n >> k;
	int minn = 0;
	vector a(n,vector<int>(n));
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> a[i][j];
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			minn += a[i][j] != a[n - 1 - i][n - 1 - j];
	minn /= 2;

	if(k >= minn && (n % 2 == 1 || (k - minn) % 2 == 0)){
		cout << "YES" << endl;
	}else cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}