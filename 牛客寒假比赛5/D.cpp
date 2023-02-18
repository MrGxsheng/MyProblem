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
const int N = 100010;
int n,m;
PII a[N],b[N];
priority_queue<PII,vector<PII>,greater<PII>> q;
priority_queue<PII,vector<PII>,greater<PII>> qq;

void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i].fi >> a[i].se;
	}

	int la = 0 ,ra = 0;
	int lb = 0 ,rb = 0;


	for(int i = 1 ; i <= n ; i++){
		cin >> b[i].fi >> b[i].se;
	}

	for(int i = 1 ; i <= n ; i++){
		int l1 = a[i].fi , r1 = a[i].se;
		int l2 = b[i].fi , r2 = b[i].se;
		if(ra + 1 >= l1 ) ra = max(r1,ra);
		else{
			q.push(a[i]);
			while(q.size()){
				auto t = q.top();
				q.pop();
				if(ra + 1 < t.fi) {
					q.push(t);
					break;
				}
				else ra = max(ra,t.se);
			}

		}
		if(rb + 1 >= l2) rb = max(r2,rb);
		else{
			qq.push(b[i]);
			while(qq.size()){
				auto t = qq.top();
				qq.pop();
				if(rb + 1 < t.fi){
					qq.push(t);
					break;
				} 
				else rb = max(rb,t.se);
			}

		}

		if(ra < rb) {
			cout << "ya_win!" << endl;
			cout << rb - ra << endl;
		}
		else if(ra > rb){
			cout << "sa_win!" << endl;
			cout << ra - rb << endl;
		} 
		else {
			cout << "win_win!" << endl;
			cout << 0 << endl;
		}
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
