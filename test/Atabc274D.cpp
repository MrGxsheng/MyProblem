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
const int M = 1000010;
int n,m;
void solve(){
	int N, x, y;
    cin >> N >> x >> y;
 
    int buf = 10001, scope = 20010;
    vector<bool> dp_x1(scope, false), dp_y1(scope, false);
    vector<bool> dp_init(scope, false);
    int x_now;
    int y_now = 0;
    cin >> x_now;
    dp_x1[x_now + buf] = true;
    dp_y1[y_now + buf] = true;
 
    for (int i = 0; i < N-1; i++) {
        if (i % 2 == 0) {
            int tate;
            cin >> tate;
            vector<bool>dp_y2 = dp_init;
            for (int j = 0; j < scope; j++) {
                if (dp_y1[j]) {
                    dp_y2[j-tate] = true;
                    dp_y2[j+tate] = true;
                }
            }
            dp_y1 = dp_y2;
        }
        else {
            int yoko;
            cin >> yoko;
            vector<bool>dp_x2 = dp_init;
            for (int j = 0; j < scope; j++) {
                if (dp_x1[j]) {
                    dp_x2[j-yoko] = true;
                    dp_x2[j+yoko] = true;
                }
            }
            dp_x1 = dp_x2;
        }
    }
 
    if (dp_x1[x + buf] && dp_y1[y + buf]) cout << "Yes" << endl;
    else cout << "No" << endl;
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
