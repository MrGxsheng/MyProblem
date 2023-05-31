#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int q[5];
bool st[5][5][5];
bool dp[210][210][5];
void solve(){
	map<char,int> mp;
	mp['W'] = 1;
	mp['I'] = 2;
	mp['N'] = 3;
	mp['G'] = 4;

	for(int i = 1 ; i <= 4 ; i++) cin >> q[i];	
	for(int i = 1 ; i <= 4 ; i++){
		for(int j = 1 ; j <= q[i] ; j++){
			string s;
			cin >> s;
			st[i][mp[s[0]]][mp[s[1]]] = true;
		}
	}

	string s;
	cin >> s;
	n = s.size();
	
	s = '?' + s;

	for(int i = 1 ; i <= n ; i++) dp[i][i][mp[s[i]]] = true;

	for(int len = 1 ; len <= n ; len++)
		for(int l = 1 ; l + len - 1 <= n ; l++){
			int r = l + len - 1;
			for(int k = l ; k < r ; k++)
				for(int z = 1 ; z <= 4 ; z++)
					for(int z1 = 1 ; z1 <= 4 ; z1++)
						for(int z2 = 1 ; z2 <= 4 ; z2++)
							if(st[z][z1][z2] && dp[l][k][z1] && dp[k + 1][r][z2]) // z -> z1 + z2
								dp[l][r][z] = true;

		}
	bool vis = false;
	if(dp[1][n][1]){
		vis = true;
		cout << 'W';
	}
	if(dp[1][n][2]){
		vis = true;
		cout << 'I';
	}
	if(dp[1][n][3]){
		vis = true;
		cout << 'N';
	}
	if(dp[1][n][4]){
		vis = true;
		cout << 'G';
	}

	if(!vis)  cout << "The name is wrong!" << endl;
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