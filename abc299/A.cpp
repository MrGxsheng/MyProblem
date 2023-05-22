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
	bool pre = false;
	bool in = false;
	bool st = false;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == '|' && !in){
			pre = true;
		}else if(s[i] == '|' && in){
			st = true;
		}else if(s[i] == '*' && pre) in = true;
	}

	if(pre && in && st) cout << "in" << endl;
	else cout << "out" << endl;
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