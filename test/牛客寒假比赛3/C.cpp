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
int res[N];
void solve(){
	 cin >> n;
    if (n <= 3 || n == 7) cout << -1 << endl;
    else {
        int m = n / 4 * 4;
        for ( int i = 1; i <= m; i += 4 ) {
            res[i] = i + 2;
            res[i + 1] = i + 3;
            res[i + 2] = i;
            res[i + 3] = i + 1;
        }
        m -= 4;
        m ++;
        if (n % 4 == 1) {
            res[m] = m + 2;
            res[m + 1] = m + 3;
            res[m + 2] = m + 4;
            res[m + 3] = m;
            res[m + 4] = m + 1;
        } else if (n % 4 == 2) {
            res[m] = m + 3;
            res[m + 1] = m + 4;
            res[m + 2] = m + 5;
            res[m + 3] = m;
            res[m + 4] = m + 1;
            res[m + 5] = m + 2;
        } else if (n % 4 == 3) {
            m -= 4;
            res[m] = m + 2;
            res[m + 1] = m + 3;
            res[m + 2] = m + 4;
            res[m + 3] = m;
            res[m + 4] = m + 1;
            m += 5;
            res[m] = m + 3;
            res[m + 1] = m + 4;
            res[m + 2] = m + 5;
            res[m + 3] = m;
            res[m + 4] = m + 1;
            res[m + 5] = m + 2;
        }

        for ( int i = 1; i <= n; i ++ ) cout << res[i] << " ";
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
