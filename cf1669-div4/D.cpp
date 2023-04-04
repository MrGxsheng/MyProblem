#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	string s;
	cin >> s;

	int b = 0 , r = 0;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == 'W'){
			if(b == 0 && r == 0) continue;
			if(b == 0 || r == 0) {
				cout << "NO" << endl;
				return;
			}
			b = 0;
			r = 0;
		}else if(s[i] == 'R') r++;
		else b++;
	}
	if(r == 0 && b == 0) {
		cout << "YES" << endl;
		return;
	}
	if(b == 0 || r == 0) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}