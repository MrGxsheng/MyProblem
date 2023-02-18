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
int n, k;
char g[N][5];
bool st[N][5], rst[N][5];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
 
void solve()
{
    cin >> n >> k;
    for ( int i = 1; i <= n; i ++ ) {
        for ( int j = 1; j <= 3; j ++ ) {
            g[i][j] = '.';
            st[i][j] = false;
            rst[i][j] = false;
        }
    }
 
    while (k --) {
        int x, y;
        cin >> x >> y;
        if (g[x][y] == '.') g[x][y] = '@';
        else g[x][y] = '.';
    }
 
    queue<PII> q;
    q.push({1, 1});
    st[1][1] = true;
    while (q.size()) {
        auto t = q.front();
        q.pop();
 
        for ( int i = 0; i < 2; i ++ ) {
            int a = t.fi + dx[i], b = t.se + dy[i];
            if (a < 1 || a > n || b < 1 || b > 3) continue;
            if (st[a][b] || g[a][b] == '@') continue;
            st[a][b] = true;
            q.push({a, b});
        }
    }
 
    q.push({n, 3});
    rst[n][3] = true;
    while (q.size()) {
        auto t = q.front();
        q.pop();
 
        for ( int i = 2; i < 4; i ++ ) {
            int a = t.fi + dx[i], b = t.se + dy[i];
            if (a < 1 || a > n || b < 1 || b > 3) continue;
            if (rst[a][b] || g[a][b] == '@') continue;
            rst[a][b] = true;
            q.push({a, b});
        }
    }
 
    int res = 0;
    for ( int i = 1; i <= n; i ++ ) {
        for ( int j = 1; j <= 3; j ++ ) {
            if (st[i][j] && rst[i][j]) res ++;
        }
    }
    cout << max(0, res - 1) << endl;
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
