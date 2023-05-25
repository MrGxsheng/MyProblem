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
	int cnt = 0;
	if(n >= 2){
		for(int i = 0 ; i < n - 1 ; i++)
			if(s[i] == s[i + 1]){
				cout << "No" << endl;
				return;
			}
	
	}

	cout << "Yes" << endl;
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