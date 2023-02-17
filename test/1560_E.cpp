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
int n,m;
map<char,int> mp;
int vis[30];
void solve(){
	mp.clear();
	string s,res,ans;
	cin >> s;
	for(int i = s.length() - 1 ; i >= 0 ; i--) {
		if(!mp[s[i]]) res += s[i];
		mp[s[i]]++;
		
	}

	reverse(res.begin(),res.end());

	int sum = 0;
	for(int i = 0 ; i < res.length() ; i++){
		if(mp[res[i]] % (i + 1) ){
			cout << -1 << endl;
			return;
		} 
		else mp[res[i]] /= (i + 1);
	}
	
	for(auto a : mp){
		sum += a.se;
	}
	for(int i = 0 ; i < sum ; i++) ans += s[i];
	for(int i = 0 ; i < 30  ; i++) vis[i] = 0;
	int cnt = sum;
	for(int i = 0 ; i < res.length() ; i++) {
		vis[res[i] - 'a'] = 1;
		for(int j = 0 ; j < sum ; j++){
			if(vis[ans[j] - 'a']) continue;
			cnt++;
			if(s[cnt - 1] != ans[j]) {
				cout << -1 << endl;
				return;
			}
		}
	}
	cout << ans  << ' '  << res << endl;
	
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
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
