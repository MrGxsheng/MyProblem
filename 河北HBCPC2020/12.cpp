#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000000000;
int n,m;
void solve(){
	LL c1,c2;
	cin >> n >> c1 >> c2;
	LL cnt1 = 0;
	LL cnt2 = 0;
	for(int i = 1 ; i <= n ; i++){
		LL f1,f2;
		cin >> f1 >> f2;
		cnt1 += min(c1,c1 * f1 / N);
		cnt2 += min(c2,c2 * f2 / N);
	}

	if(cnt1 > cnt2) cout << "Rilly" << endl;
	else cout << "Northy" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}