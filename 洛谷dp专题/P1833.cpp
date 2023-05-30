#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1010;
int n,m;
int z[2];
int dp[N];
void solve(){
	 
	 for(int i = 0 ; i < 2 ; i++){
	 	int a,b;
	 	char ch;
	 	cin >> a >> ch >> b;
	 	z[i] = a * 60 + b;
	 }
	 m = z[1] - z[0];

	 cin >> n;

	 vector<tuple<int,int,int>> a(n + 1);
	 for(int i = 1 ; i <= n ; i++){
	 	int x,y,z;
	 	cin >> x >> y >> z;
	 	a[i] = {x,y,z};
	 }

	 for(int i = 1 ; i <= n ; i++){
	 	auto [x,y,z] = a[i];
	 	if(z == 0){ // 完全背包
	 		for(int j = x ; j <= m ; j++) dp[j] = max(dp[j],dp[j - x] + y);
	 	}else{
	 		for(int l = 1 ; l <= z ; l++)
	 			for(int j = m ; j >= l * x ; j--)
	 				dp[j] = max(dp[j],dp[j - x] + y);
	 	}

	 }

	 cout << dp[m] << endl;
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