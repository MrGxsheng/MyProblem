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
LL n,m;
void solve(){
	cin >> n;

	LL ans = 0;
	ans += 1;

	if(n >= 3) ans++;

	for(int d = 3 ; (1ll << (d - 1)) <= n ; d++){
		LL b = pow(n,1. / (d - 1)) + 1;
		while(true){
			LL pw = 1;
			for(int i = 1 ; i < d ; i++){
				pw = min(n + 1 , pw * b);
			}
			if(pw > n) b -= 1;
			else break;
		}

		if(b == 1) break;
		bool ok = true;
		LL x = n;
		for(int i =0 ; i < d ; i++){
			if(x % b > 1){
				ok = false;
				break;
			}
			x /= b;
		}
		if(x > 0) ok = false;
		ans += ok;
	}

	cout << ans << endl;
	
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	// T = 1;
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
