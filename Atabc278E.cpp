#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 310;
int windows[N][N][N], a[N][N], cnt[N];
void solve()
{
    int n, m, k, h, w;
    int tot = 0;
    cin >> n >> m >> k >> h >> w;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (!cnt[a[i][j]])
                tot++;
            cnt[a[i][j]]++;
            for (int k = 1; k <= 300; k++)
            {
                windows[i][j][k] += windows[i - 1][j][k];
                windows[i][j][k] += windows[i][j - 1][k];
                windows[i][j][k] -= windows[i - 1][j - 1][k];
            }
            windows[i][j][a[i][j]]++;
        }
    }
    for (int i = h; i <= n; i++)
    {
        for (int j = w; j <= m; j++)
        {
            vector<int> tmp(301, 0);
            int ans = tot;
            for (int k = 1; k <= 300; k++)
            {
                tmp[k] = windows[i][j][k];
                tmp[k] -= windows[i - h][j][k];
                tmp[k] -= windows[i][j - w][k];
                tmp[k] += windows[i - h][j - w][k];
                if (cnt[k] && tmp[k] == cnt[k])
                    ans--;
            }
            cout << ans << ' ';
        }
        cout << endl;
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
