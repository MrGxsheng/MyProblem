#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	string s,ss;
	cin >> n >>  s >> ss;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == 'l') s[i] = '1';
		if(s[i] == 'o') s[i] = '0';
	}

	for(int i = 0 ; i < n ; i++){
		if(ss[i] == 'l') ss[i] = '1';
		if(ss[i] == 'o') ss[i] = '0';
	}


	for(int i = 0 ; i < n ; i++){
		if(s[i] != ss[i]){
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