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
const int N = 1000010 , mod = 998244353;
int n,m;
LL f[N];
void solve(){
	cin >> n;
	f[0] = 1;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = i ; j <= n ; j++)
		f[j] = (f[j] + f[j - i]) % mod; 
	}
	cout << f[n] << endl;
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
