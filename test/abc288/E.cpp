#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
constexpr LL inf = 1e18;

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n),c(n);
	for(int i = 0 ; i < n ; i ++) cin >> a[i];
	for(int i = 0 ; i < n ; i ++) cin >> c[i];
	vector<bool> must(n);

	for(int i = 0 ; i < m ; i++) {
		int x;
		cin >> x;
		x--;
		must[x] = true;
	}

	vector<LL> dp(n + 1,inf);
	dp[0] = 0;

	for(int i = 0 ; i < n ; i++){
		vector<LL> g(n + 1,inf);
		int cost = 1e9;
		for(int j = 0 ; j <= i ; j++){
			cost = min(cost,c[i - j]);
			g[j + 1] = min(g[j + 1],dp[j] + cost + a[i]);
			if(!must[i]){
				g[j] = min(g[j],dp[j]);
			}
		}
		swap(dp,g);
	}

	auto ans = *min_element(dp.begin(), dp.end());
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

/*
*
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/

//        _                                    _  _  _         _                   
//       | |                                  (_)| || |       | |                  
//   ___ | |__    ___  _ __    __ _ __      __ _ | || |  __ _ | | __    ___  _ __  
//  / __|| '_ \  / _ \| '_ \  / _` |\ \ /\ / /| || || | / _` || |/ /   / __|| '_ \ 
//  \__ \| | | ||  __/| | | || (_| | \ V  V / | || || || (_| ||   <  _| (__ | | | |
//  |___/|_| |_| \___||_| |_| \__, |  \_/\_/  |_||_||_| \__,_||_|\_\(_)\___||_| |_|
//                             __/ |                                               
//                            |___/                                             
