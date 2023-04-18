#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	string s;
	cin >> n >> s;
	bool st = false;
	for(int i = 0 ; i < n ; i++) {
		if(s[i] == 'o'){
			st = true;
		}	

		if(s[i] == 'x'){
			cout << "No" << endl;
			return;
		}
	}
	if(st) {
		cout << "Yes" << endl;
		return;
	}

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