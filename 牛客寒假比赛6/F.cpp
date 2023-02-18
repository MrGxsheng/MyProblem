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
PII ans[200010];
int res[200010];

int lowbit(int x){
	return x & -x;
}

int f(int x)
{
	int res = 0;
	while (x) {
		res ++;
		x -= lowbit(x);
	}
	return res;
}

void solve(){


	cin >> n >> m;
	priority_queue<int> q;
	for ( int i = 1; i <= n; i ++ ) {
		int x;
		cin >> x;
		q.push(x);
	}
	for ( int i = 1; i <= m; i ++ ) {
		int x;
		cin >> x;
		ans[i].first = x;
		ans[i].second = i;
	}
	sort(ans + 1, ans + m + 1);

	int now = 1;
	bool is = true;
	for ( int i = 1; i <= m; i ++ ) {
		int t = ans[i].first;
		if (t >= now && is) {
			for ( int j = now; j <= t; j ++ )
			{
				int tt = q.top();q.pop();
				if (tt == 1) {
					is = false;
					break;
				}
				q.push(f(tt));
				now ++;
			}
		}
		res[ans[i].second] = q.top();
	}

	for ( int i = 1; i <= m; i ++ ) cout << res[i] << endl;
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
