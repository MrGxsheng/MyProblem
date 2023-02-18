#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
constexpr int MAXN = 2000;
int n,m;
void solve(){
	cin >> n >> m;
	vector<bitset<MAXN>> f(n);
	for(int i = 0 ; i < m ; i++){
		int a,b;
		cin >> a >> b;
		a--,b--;
		f[a][b] = 1;
	}

	int Q;
	cin >> Q;
	vector<int> s(Q), t(Q), ans(Q, -1);
	for(int i = 0 ; i < Q ; i++){
		cin >> s[i] >> t[i];
		s[i]--,t[i]--;
	}

	for(int k = 0 ; k < n ; k++){
		f[k][k] = 1;
		for(int i = 0 ; i < n ; i++){
			if(f[i][k]) f[i] |= f[k];
		}

		for(int i = 0 ; i < Q ; i++){
			if(ans[i] == -1 && k >= max(s[i],t[i]) && f[s[i]][t[i]]){
				ans[i] = k + 1;
			}
		}
	}

	for(int i = 0 ; i < Q ; i++){
		cout << ans[i] << endl;
	}
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
