#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;

	LL len = 0;
	if(n > 4) len = 1ll * (n - 4) * (5 + n);
	
	LL ans = 26;
	cout <<1ll *  ans + (n - 4) + len << endl; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}