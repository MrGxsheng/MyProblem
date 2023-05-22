#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010, mod = 1e9 + 7;
int n,m;
LL val[N], sum[N];
int idx;
void solve(){
	cin >> n;
	int index = lower_bound(val + 1 , val + 1 + idx , n) - val;
	if(val[index] > n) index --;
	LL ans = (sum[index - 1] + (n - val[index] + 1) * index % mod) % mod;
	cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;

	int now = 1;
	while(now <= 1e9){
		val[++ idx] = now;
		int dis = ceil(sqrt(now));
		sum[idx] = (sum[idx - 1] + idx * dis) % mod;
		now += dis;
	}
	val[++ idx] = 1e9 + 1;
	cin >> T;
	while(T--) solve();
	return 0;
}