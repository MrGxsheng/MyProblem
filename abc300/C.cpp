#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1010;
int n,m;
vector<string> a(N);
vector<int> ans(N);
bool st[110][110];
int dx[4] = {-1,-1,1,1};
int dy[4] = {-1,1,1,-1};
int H,W;
int bfs(int x, int y){

	int cnt = 1;
	while(1){
		bool res = true;
		vector<PII> zz;
		for(int i = 0 ; i < 4 ; i++){
			int xx = cnt * dx[i] + x;
			int yy = cnt * dy[i] + y;
			if(xx < 0 || xx >= H || yy < 0 || yy >= W || st[xx][yy] || a[xx][yy] != '#') {
				res = false;
				break;
			}
			zz.push_back({xx,yy});
		}

		if(cnt > 1) st[x][y] = true;
		if(res) {
			cnt++;
			for(int j = 0 ; j < 4 ; j++)
				st[zz[j].first][zz[j].second] = true;
		}
		else return cnt - 1;
	}
}

void solve(){
	cin >> H >> W;
	for(int i = 0 ; i < H ; i++) cin >> a[i];

	n = min(H,W);

	for(int i = 0 ; i < H ; i++)
		for(int j = 0 ; j < W ; j ++)
			if(a[i][j] == '#' && !st[i][j])
				ans[bfs(i,j)]++;
			


	for(int i = 1 ; i <= n ; i++)
		cout << ans[i] << ' ';
	

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