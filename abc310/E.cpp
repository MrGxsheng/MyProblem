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

	array<int,2> f{};
	LL ans = 0;
	for(auto c : s){
		if(c == '0'){
			f[1] += f[0];
			f[0] = 1;
		}else{
			swap(f[0],f[1]);
			f[1]++;
		}
		ans += f[1];
	}
	cout << ans << endl;
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