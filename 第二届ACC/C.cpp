#include <bits/stdc++.h>
#define endl '\n'
#define inf 1e18
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1010;
int n,m,k;
int x1,yy1,x2,y2;
char c[N][N];
LL d[N][N];
bool st[N][N][4];

void bfs(){
	queue<PII> q;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            d[i][j] = inf;

    q.push({x1, yy1});
    d[x1][yy1] = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        int x = t.first , y = t.second;
        for (int i = 0; i < 4; i ++ )
            for(int j = 1 ; j <= k ; j++){
                LL nx = t.first + dx[i] * j, ny = t.second + dy[i] * j;

                if(x < 1 || x > n || y < 1 || y > m) break;
                if(c[nx][ny] == '#') break;
                if(st[nx][ny][i]) break;
                if(d[nx][ny] > d[x][y] + 1){
                    d[x][y] = d[x][y] + 1;
                    q.push({nx,ny});
                } 
            }
        
    }

}

void solve(){
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            cin >> c[i][j]; 
	cin >> x1 >> yy1 >> x2 >> y2;
	bfs();



	if(d[x2][y2] > inf / 2) cout << -1 << endl;
    else cout << d[x2][y2] << endl;
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