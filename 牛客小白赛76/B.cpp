#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	int cnt = 0;
	int maxx = 0;
	m = n;
	while(n){
		if(n & 1) maxx = max(cnt,maxx);
		cnt++;
		
		n >>= 1;
	}
	if(__builtin_popcount(m) == 1) cout << maxx << endl;
	else cout << maxx + 1 << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}