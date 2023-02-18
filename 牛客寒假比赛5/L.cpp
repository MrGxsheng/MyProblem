#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;
const int N = 1000010;
int n,m;
LL f[N];
PII v[N];

void solve(){
	cin >> n >> m;

	for(int i = 1 ; i <= m ; i++) cin >> v[i].se >> v[i].fi;
	LL x = n , nn = n;
	while(1){
		x = nn;
		for(int i = 1 ; i <= m ; i++){
			if(v[i].fi >= nn) continue;
			x = min(nn / v[i].fi * v[i].fi,x);
		} 
		if(x == nn) break;
		nn = x;
	}
	
	memset(f,0x3f,sizeof f);

	f[n] = 0;
	for(int i = n ; i >= x ; i--) 
		for(int j = 1 ; j <= m ; j++){
            if(v[j].fi >= i) continue;
			LL t = i / v[j].fi * v[j].fi;
            f[t] = min(f[t],f[i] + v[j].se);
		}


	cout << f[x] << endl;
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
