#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int ans = min((x1 != 1) + (x1 != n) + (y1 != 1) + (y1 != m),(x2 != 1) + (x2 != n) + (y2 != 1) + (y2 != m));
	cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}