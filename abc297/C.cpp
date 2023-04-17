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
	for(int i = 0 ; i < n ;  i++) cin >> s[i];

	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++){
			if(j + 1 < m && s[i][j] == 'T' && s[i][j + 1] == 'T'){
				s[i][j] = 'P';
				s[i][j + 1] = 'C';
				j++;
			}
		}
	for(int i = 0 ; i < n ; i++) cout << s[i] << endl;
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