#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 2010;
int n,m,X,x,y,xx,yy;
PII c[4000010];
int a[2010][2020];
int d[2010][2010];
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
bool st[4000010];


void bfs(int nowx,int nowy){
	queue<PII> q;
	memset(d,-1,sizeof d);
	q.push({nowx,nowy});
	d[nowx][nowy] = 0;

	while(q.size()){
		auto t = q.front();
		q.pop();

		for(int i = 0 ; i < 4 ; i ++){
			int aa = t.fi + dx[i];
			int bb = t.se + dy[i];
			if(aa <= 0 || aa > n || bb <= 0 || bb > m || a[aa][bb] == -1 || d[aa][bb] != -1) continue;
			d[aa][bb] = d[t.fi][t.se] + 1;
			q.push({aa,bb});
		}
	}
}


void solve(){
	int cnt = 0;
	cin >> n >> m >> X;
	cin >> x >> y >> xx >> yy;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j ++){
			cin >> a[i][j];
			if(a[i][j] > X) c[cnt++] = {i,j};
		}

	if(cnt == 0){
		cout << -1 << endl;
		return;
	}
    
    bfs(x,y);
    int res[cnt];

	for(int i = 0 ; i < cnt ; i ++){
        res[i] = d[c[i].fi][c[i].se];
        if(res[i] == -1) st[i] = true;
	}
    
	int ans[cnt];
    bfs(xx,yy);
	for(int i = 0 ; i < cnt ; i ++){
		ans[i] = d[c[i].fi][c[i].se];
		if(ans[i] == -1) st[i] = true;
	}

	int kk = 0x3f3f3f3f;
	for(int i = 0 ; i < cnt ; i ++) {
		if(st[i]) continue;
		kk = min(res[i] + ans[i],kk);
	}

    if(kk == 0x3f3f3f3f) cout << -1 << endl;
    else 
	cout << kk << endl;
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
