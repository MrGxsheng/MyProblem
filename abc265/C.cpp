#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	vector<string> s(n);
	for(int i = 0 ; i < n ; i++) cin >> s[i];

	map<PII,int> mp;
	for(int i = 0 ; i < n ; )
		for(int j = 0 ; j < m ; ){
			char x = s[i][j];
			if(mp[{i,j}]){
				cout << -1 << endl;
				return;
			}			
			mp[{i,j}] = 1;

			if(x == 'U') i = i - 1;
			else if(x == 'D') i = i + 1;
			else if(x == 'L') j = j - 1;
			else if(x == 'R') j = j + 1;
			if(i < 0) {
				cout << 1 << ' ' << j + 1 << endl;
				return;
			}else if(i >= n) {
				cout << n << ' ' << j + 1 << endl;
				return;
			}
			else if(j < 0){
				cout << i + 1 << ' ' << 1 << endl;
				return;
			}else if(j >= m){
				cout << i + 1<< ' ' << m  << endl;
				return;
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