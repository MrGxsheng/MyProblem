#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
constexpr int mod = 998244353;
int n,m;

void solve(){
	string s;
	cin >> n >> s;
	vector<LL> p(n + 1);
	p[0] = 1;
	for(int i = 1 ; i <= n ; i++) p[i] = p[i - 1] * 2 % mod;

	vector<int> a(n + 1);
	
	for(int i = 1 ; i < n ; i++)
		if(n % i == 0){
			vector<bool> vis(i);
			for(LL j = 0 ; j < n ; j++)
				if(s[j] == '.'){
					vis[j % i] = 1;
				}

			LL ct = count(vis.begin(), vis.end(),1);
			// cerr << ct << endl; cerr 不会被测评机 检测到
 			a[i] = p[i - ct];
			for(LL j = 1 ; j < i ; j++){
				if(i % j == 0){
					a[i] = (a[i] - a[j] + mod) % mod; // 去重
				}
			}
		}
	LL ans = 0;
	for(LL i = 1 ; i < n ; i++)
		ans = (ans + a[i]) % mod;
	

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