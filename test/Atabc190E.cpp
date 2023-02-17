#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 100010 , M = N * 2 , INF = 0x3f3f3f3f;
int n,m,k;
int h[N],e[M],ne[M],idx;
int d[N][18];
int c[N];
int dp[1 << 18][18];
void add(int a,int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;

}

void bfs(int u , int id){
	queue<int> q;
	q.push(u);
	d[u][id] = 0;

	while(q.size()){
		int t = q.front();
		q.pop();
		
		for(int i = h[t] ; ~i ; i = ne[i]){
			int j = e[i];
			if(d[j][id] == -1){
				d[j][id] = d[t][id] + 1;
				q.push(j);
			}
		}
	}
}

void solve(){
	cin >> n >> m;
	memset(h,-1,sizeof h);
	for(int i = 1 ; i <= m ; i++){
		int a,b;
		cin >> a >> b;
		add(a,b);
		add(b,a);
	}

	cin >> k;

	for(int i = 0; i < k ; i++) cin >> c[i];

	for(int i = 1 ; i <= n ; i++)
        for(int j = 0 ; j < k ; j++)
            d[i][j] = -1;
 
	for(int i = 0 ; i < k ; i++) bfs(c[i],i);

	for(int i = 0 ; i < ( 1 << k) ; i++)
        for(int j = 0 ; j < k ; j++)
            dp[i][j] = INF;

 	for(int i = 0 ; i < k ; i++) dp[1 << i][i] = 0;

 	for(int i = 1 ; i < (1 << k) ; i++)
        for(int j = 0 ; j < k ; j++)
            if((i & (1 << j)))
                for(int j2 = 0 ; j2 < k ; j2++){
                    if(j == j2) continue;
                    
                    if(d[c[j]][j2] != -1 && dp[(i ^ (1 << j))][j2] != INF)
                        dp[i][j] = min(dp[i][j],dp[(i ^ (1 << j))][j2] + d[c[j]][j2]);
                    
                }
            
    int ans = INF;
    for(int i = 0 ; i < k ; i++)
        ans = min(ans,dp[(1 << k) - 1][i]);
    
    if(ans == INF) cout << -1 << endl;
    else cout << ans + 1 << endl;;
    
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
