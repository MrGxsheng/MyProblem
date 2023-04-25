#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	// 打个深搜
	cin >> n;

	if(n == 1) cout << 1 << endl;
	else if(n % 2 != 0) cout << -1 << endl;
	else {
		cout << n << ' ' << n - 1 << ' ';
		for(int i = 1 ; i <= (n - 2) >> 1 ; i++)
			cout << 2 * i << ' ' << n - 1 - 2 * i << ' ';
		cout << endl;
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}