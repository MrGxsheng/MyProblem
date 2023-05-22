#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
LL pre,ans,a;
void solve(){
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin >> a;
			ans += pre * a;
			pre += a;
		}
	cout << ans << endl;
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