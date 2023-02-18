#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 10010;
int n,m;
int a[N],b[N];
int c[N],d[N];
int k;
bool st[N];
int res;
void dfs(int u){
	if(u == k + 1){
		int cnt = 0;
		for(int i = 1 ; i <= m ; i++)
			if(st[a[i]] && st[b[i]]) cnt++;
		res = max(res,cnt);
		return;
	}
	bool falg = true;
	if(st[c[u]]) falg = false;
	st[c[u]] = true;
	dfs(u + 1);
	if(falg) st[c[u]] = false;

	falg = true;
	if(st[d[u]]) falg = false;
	st[d[u]] = true;
	dfs(u + 1);
	if(falg) st[d[u]] = false;


}

void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++) cin >> a[i] >> b[i];
	cin >> k;
	for(int i = 1 ; i <= k ; i++) cin >> c[i] >> d[i];
	dfs(1);
	cout << res << endl;

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

/*
*
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/
