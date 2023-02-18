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
const int N = 10000010;
int n,m,k;
int chr[N];
int who[N];

void dp(int s){
	for(int x = s ; x ; x -= x & -x){
		int p = s ^ (x & -x);
		if(chr[p] < chr[s]){
			chr[p] = chr[s];
			who[p] = who[s];
		}
	}
}

void dfs(int tot , int now , int pos, int sta){
	if(pos == k) return dp(sta);
	if(now + k - pos > tot) dfs(tot , now , pos + 1 , sta);
	if(now < tot) dfs(tot,now + 1,pos + 1,sta + (1 << pos));
}

void solve(){
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		int charm,sum,x;
		cin >> charm >> sum;
		int s = 0;
		for(int j = 1 ; j <= sum ; j++){
			cin >> x;
			s |= (1 << (x - 1));
		}

		if(charm > chr[s]){
			chr[s] = charm;
			who[s] = i;
		}
	}

	for(int i = k ; i >= 2 ; i--) dfs(i,0,0,0);

	cin >> m;
	while(m--){
		int sum,x;
		cin >> sum;
		int s = 0;
		for(int j = 1 ; j <= sum ; j++){
			cin >> x;
			s |= (1 << (x - 1));
		}

		if(who[s] == 0) cout << "OMG!" << endl;
		else cout << who[s] << endl; 
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
