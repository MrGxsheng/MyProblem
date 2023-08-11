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
	int x = count(s.begin(), s.end(),'(');
	int y = n - x;
	if(x != y) {
		cout << -1 << endl;
		return;
	}

	LL ans = 0;
	int sum = 0;
	for(char c : s){
		if(c == '(') sum++;
		else{
			sum--;
			if(sum < 0) ans -= sum;
		}
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