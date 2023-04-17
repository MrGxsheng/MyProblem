#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1010;
int n,m;
char a[N][N];
bool st[N][N];
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
int ans;
void bfs(int x,int y){
	queue<PII> q;
	q.push({x,y});
	st[x][y] = true;

	while(q.size()){
		PII t = q.front();
		q.pop();

		for(int i = 0 ; i < 4 ; i++){
			int ax = t.first + dx[i];
			int ay = t.second + dy[i];

			if(ax >= 1 && ax <= n && ay >= 1 && ay <= m && !st[ax][ay]){
				st[ax][ay] = true;
				if(a[ax][ay] == '!') ans++;
				q.push({ax,ay});
			}
		}
	}
}

void solve(){
	cin >> n >> m;
    int x,y;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++){
			cin >> a[i][j];
			if(a[i][j] == '#') st[i][j] = true;
            if(a[i][j] == '@') x = i , y = j;
		}

	bfs(x,y);
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