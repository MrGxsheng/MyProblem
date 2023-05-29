#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	vector<PII> moves;
	for(int i = 0 ; i < n && i * i < m; i++){
		int j = sqrt(m - i * i);
		if(i * i + j * j == m){
			moves.emplace_back(i, j);
            moves.emplace_back(j, -i);
            moves.emplace_back(-i, -j);
            moves.emplace_back(-j, i);
		}
	}

	vector dis(n,vector<int>(n,-1));
	queue<tuple<int,int,int>>q;
	q.emplace(0,0,0);

	while(!q.empty()){
		auto [x,y,d] = q.front();
		q.pop();

		if(dis[x][y] != -1) continue;
		dis[x][y] = d;

		for(auto [dx,dy] : moves){
 			int nx = x + dx;
            int ny = y + dy;
            
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                q.emplace(nx, ny, d + 1);
            }
		}
	}

		for (int i = 0; i < n; i++) 
        	for (int j = 0; j < n; j++) 
            	cout << dis[i][j] << " \n"[j == n - 1];
        	
    	
	
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