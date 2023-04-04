#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<vector<int>> cnt(12,vector<int>(12,0));

	LL ans = 0;
	for(int i = 0 ; i < n ; i++){
		string s;
		cin >> s;
		for(int j = 0 ; j < 2 ; j++)
			for(char c = 'a' ; c <= 'k' ; c++){
				if(c == s[j]) continue;
				string a = s;
				a[j] = c;
				ans += cnt[a[0] - 'a'][a[1] - 'a'];
			}
		cnt[s[0] - 'a'][s[1] - 'a']++;
	}
	cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}