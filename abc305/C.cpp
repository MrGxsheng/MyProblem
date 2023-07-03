#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void solve(){
	cin >> n >> m;
	vector<string> s(n);
	for(int i = 0 ; i < n ; i++) cin >> s[i];

	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++){
			if(s[i][j] == '.'){
				int cnt = 0;
				for(int k = 0 ; k < 4; k ++){
					int x = dx[k] + i;
					int y = dy[k] + j;
					if(x < 0 || x >= n || y < 0 || y >= m) continue;
					if(s[x][y] == '#') cnt++;
					if(cnt > 1){
						cout << i + 1 << ' ' << j + 1<< endl;
						return;
		 			}
				}	
			}
		}
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