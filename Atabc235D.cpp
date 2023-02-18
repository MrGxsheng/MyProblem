#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
typedef pair<int,LL> PII;
const int N = 1000010;
int n,m,mul,ans;
int res;
int num(LL x){
	int res = 0;
	while(x){
		res++;
		x /= 10;
	}
	return res;
}

void dfs(int u,LL k){
	if(u >= res) return;
	if(u >= 1000) return;
	if(num(k) >= num(ans) + 1) return;
	if(k == ans){
		res = min(u,res);
		return;
	}
	dfs(u + 1, k * mul);
	if(k % 10) dfs(u + 1 , k / 10 + (num(k) - 1) * 10 * (k % 10));
	
}

void bfs(){
	queue<PII> q;
	q.push({0,1});
	int kk = num(ans);
	while(q.size()){
		auto t = q.front();
		q.pop();

		int dist = t.first;
		int k = t.second;
		if(num(k) >= kk + 1) continue;

		if(k == ans){
			res = dist;
			return;
		}

		if(k % 10 && k / 10) q.push({dist + 1,(LL) k / 10 + (num(k) - 1) * 10 * (k % 10)});
		q.push({dist + 1,(LL)k * mul});
	}
}

void solve(){
	cin >> mul >> ans;
	res = 0x3f3f3f3f;
	// dfs(0,1);
	 bfs();

	if(res == 0x3f3f3f3f) cout << -1 << endl;
	else 
	cout << res << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
