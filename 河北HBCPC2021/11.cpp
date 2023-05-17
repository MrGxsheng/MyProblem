#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 100010;
int n,m;
vector<int> v[N];
int a[N];
int res[N];
int dp[N];
int primes[N], cnt;
bitset<N * 2> st;
void prime(int x){
	for(int i = 2; i <= x; i ++){
		if(!st[i])	primes[cnt ++] = i;
		for(int j = 0; i * primes[j] <= x; j ++){
			st[i * primes[j]] = true;
			if(i % primes[j] == 0)	break;
		}
	}
}

void divide(){
	for(int i = 1 ; i <= n ; i++){
		int x = a[i];
		for(int j = 0; primes[j] * primes[j] <= x; j ++){
			if(x % primes[j] == 0){
				v[i].push_back(primes[j]);
				while(x % primes[j] == 0){
					x /= primes[j];
				}
			}
		}
		if(x > 1) v[i].push_back(x);
	}
}


void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + 1 + n);

	divide();
	int ans = 0;
	vector<int> dp(n + 2);
	
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 0 ; j < v[i].size() ; j++){
			dp[i] = max(dp[i],res[v[i][j]] + 1);
			ans = max(dp[i],ans);
		}
		for(int j = 0 ; j < v[i].size() ; j++) res[v[i][j]] = dp[i];
	}
	if(ans < 3) cout << -1 << endl;
	else cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	prime(N);
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}