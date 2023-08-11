#include <bits/stdc++.h>
#define endl '\n'
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair <int,int> PII;
const int N = 2010;
const int dx[] = {0,0,1,-1},dy[] = {1,-1,0,0};
int n,m;
int g[N][N];
int dist[N][N];
void bfs () {
    queue <PII> q;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (g[i][j]) q.push ({i,j});
        }
    }
    while (q.size ()) {
        PII t = q.front ();
        q.pop ();
        for (int i = 0;i < 4;i++) {
            int a = t.x + dx[i],b = t.y + dy[i];
            if (a < 1 || a > n || b < 1 || b > m || g[a][b] || dist[a][b]) continue;
            dist[a][b] = dist[t.x][t.y] + 1;
            q.push ({a,b});
        }
    }
}

void solve(){
	cin >> n >> m;
    int k;
    cin >> k;
    while (k--) {
        int x,y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    bfs ();
    int x = 1,y = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (dist[i][j] > dist[x][y]) x = i,y = j;
        }
    }
    cout << x << ' ' << y << endl;
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