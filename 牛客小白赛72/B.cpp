#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int cnt[N];
void get(){
	for(int i = 1 ; i <= 4000 ; i++){
		int res = 0;
		for(int j = 1 ; j <= i ; j++){
			if(i % j == 0) res++;
		}
		cnt[i] = res & 1;
	}
}

void solve(){
	cin >> n;
	int ans = 0;
	for(int i = 1 ; i <= n ; i++) {
		// cout << cnt[i] << ' ';
		ans += cnt[i];
	}
	cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	get();
	cin >> T;
	while(T--) solve();
	return 0;
}