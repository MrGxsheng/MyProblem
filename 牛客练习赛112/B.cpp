#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int sum[N];
int cnt[N][35];

bool check(int p , int mid){
	int res = 0;
	for(int i = 0 ; i <= 30 ; i++)
		if(cnt[mid][i] - cnt[p - 1][i] == mid - p + 1) res++;
	return res == 0;
}

void solve(){
	cin >> n;
	vector<int> a(n);
	for(int i = 1 ; i <= n ; i++) {
		int x;
		cin >> x;
		for(int j = 0 ; j <= 30 ; j++){
			cnt[i][j] = cnt[i - 1][j];
			if((x >> j) & 1) cnt[i][j]++;
		}
	}

	LL ans = 0;
	for(int i = 1 ; i <= n ; i++){
		if(!check(i,n)) continue;
		int l = i , r = n;
		while(l < r){
			int mid = l + r >> 1;
			if(check(i,mid)) r = mid;
			else l = mid + 1;
		}
		ans += (n - r + 1);
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