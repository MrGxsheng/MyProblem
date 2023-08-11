#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	int sum = 0;
	for(int i = 0 ; i < n ; i++) {
		int x;
		cin >> x;
		sum += x;
	}
	cout << (sum == m ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}