#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	if(n % 3 == 0) cout << n << endl;
	else if((n + 1) % 3 == 0) cout << n + 1 << endl;
	else if((n + 2) % 3 == 0)cout << n + 2 << endl;
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