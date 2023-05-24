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
	sort(s.begin(),s.end());
	do{
		bool st = true;
		for(int i = 0 ; i < n - 1 ; i ++){
			int diff = 0 ;
			for(int j = 0 ; j < m ; j++)
				if(s[i][j] != s[i + 1][j])
					diff++;
			if(diff != 1){
				st = false;
				break;
			}
		}
		if(st){
			cout << "Yes" << endl;
			return;
		}

	}while(next_permutation(s.begin(), s.end()));
	cout << "No" << endl;
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