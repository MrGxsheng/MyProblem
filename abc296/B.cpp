#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	vector<string> s(8);
	for(int i = 0 ; i < 8 ; i++) cin >> s[i];

	for(int i = 7 ; i >= 0 ; i --)
		for(int j = 0 ; j < 8 ; j++)
			if(s[i][j] == '*'){
				cout << char(j + 'a') << 8 - i << endl;
				return;
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