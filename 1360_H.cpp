#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
#define endl '\n'
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	map<int,int> vis;
	cin >> n >> m;
	int mid = pow(2,m - 1) - 1;
	int len = pow(2,m);
	string s;
	for(int i = 1 ; i <= n ; i++){
		cin >> s;
		int cnt = 0;
		for(int j = s.size() - 1 , k = 1 ; j >= 0 ; j-- , k *= 2)
			if(s[j] == '1') cnt += k;
		if(len % 2 == 0){
			if(cnt <= mid){
				mid ++;
				while(vis[mid]) mid++;
			}
		}else{
			if(cnt >= mid){
				mid--;
				while(vis[mid]) mid--;
			}
		}
		vis[cnt] = 1;
		len--;
	}

	string ans;
	for(int i = 0 ; i < m ; i++){
		char x = '0' + mid % 2;
		ans += x;
		mid /= 2;
	}
	reverse(ans.begin(),ans.end());
	cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
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
