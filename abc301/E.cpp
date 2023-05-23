#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
constexpr int dx[] = {0,0,-1,1};
constexpr int dy[] = {-1,1,0,0};
void solve(){
	int H,W,T;
	cin >> H >> W >> T;
	vector<string> S(H);
	for(int i = 0 ; i < H ; i++) cin >> S[i];

	// 把起点，终点，糖果都存起来！	
	string s = "SoG";
	vector<PII> p;
	for(auto c : s){
		for(int i = 0 ; i < H ; i++)
			for(int j = 0 ; j < W ; j++)
				if(S[i][j] == c)
					p.emplace_back(i,j);
	}


	// 对 起点，终点，糖果都跑bfs 找最短路径！
	n = p.size();
	vector dis(n,vector<int>(n));
	for(int i = 0 ; i < n ; i++){
		queue<PII> q;
		vector d(H,vector(W,-1));
		q.push(p[i]);
		d[p[i].first][p[i].second] = 0;

		while(q.size()){
			auto [x,y] = q.front();
			q.pop();

			for(int k = 0 ; k < 4 ; k++){
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (0 <= nx && nx < H && 0 <= ny && ny < W && S[nx][ny] != '#' && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.emplace(nx,ny);
				}
			}
		}

		//把找出来的 路径存起来！
		for(int j = 0 ; j < n ; j++)
			dis[i][j] = d[p[j].first][p[j].second];
	}

	// 开始dp
	vector dp(1 << n , vector(n,T + 1));
	dp[1][0] = 0;

	int ans = -1;
	for(int s = 1 ; s < (1 << n) ; s += 2){ // += 2是因为 要保证 最高位和最低位是1 也就是说 起点和终点都要过
		if(dp[s][n - 1] <= T){
			ans = max(ans,__builtin_popcount(s) - 2); // __builtin_popcount 返回二进制中1的个数 -2 是因为有起点和重点 
		}
		// 1 代表 已经获得了该糖果
		for(int i = 0 ; i < n ; i++){
			if(s >> i & 1){ // 通过该位去拓展别的 糖果或者是别的
				for(int j = 0 ; j < n ; j++){ // ~ 是因为要找0的 也就是没得到的 dis同理
					if((~s >> j & 1) && dis[i][j] != -1){
						// << 优先级比 | 高  也就是说S状态去拓展J点
						dp[s | 1 << j][j] = min(dp[s | 1 << j][j] , dp[s][i] + dis[i][j]);
					}
				}
			}
		}
	}

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