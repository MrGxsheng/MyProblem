#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
constexpr LL inf = 1E18;
int n,m;
void solve(){
	int X,Y,Z;
	cin >> X >> Y >> Z;

	string S;
	cin >> S;

	array<LL,2> dp{0ll,inf};

	for(auto c : S){
		dp[0] = min(dp[0],dp[1] + Z);
		dp[1] = min(dp[1],dp[0] + Z);
		if(c == 'a'){
			dp[0] += X;
			dp[1] += Y;
		}else {
			dp[1] += X;
			dp[0] += Y;
		}
	}
	cout << min(dp[0],dp[1]) << endl;
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