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
PII a[N];
int b[N];
void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++){
		cin >> a[i].fi >> a[i].se;
        b[a[i].fi]++;
        b[a[i].se + 1]--;
    }
    LL ans = 0;

    for(int i = 1 ; i <= N ; i++) b[i] += b[i - 1];
    
    for(int i = 1 ; i < N ; i++){
       if(n - 1 < N && n - i > 0 )
        ans = (ans % mod + 1LL * b[i] * b[n - i]) % mod;
    }
    
    for(int i = 1 ; i <= m ; i++){
        int newl = n - a[i].se, newr = n - a[i].fi;
        int mid = min(newr,a[i].se) - max(newl,a[i].fi) + 1;
        if(mid < 0) mid = 0;
        ans = (ans % mod - mid + mod) % mod;
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
