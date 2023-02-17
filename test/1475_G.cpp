#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int a[N], have[N], in[N], dp[N], vis[N];
vector<int> G[N];
void solve()
{
    int n;
    cin >> n;
    int ans = n - 1;
    for (int i = 1; i <= 2e5; i++)
    {
        vis[i] = dp[i] = in[i] = have[i] = 0;
        G[i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        have[a[i]]++;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[i - 1])
            continue;
        for (int j = a[i] + a[i]; j <= 2e5; j += a[i])
        {
            if (have[j])
            {
                in[j]++;
                G[a[i]].push_back(j);
            }
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        dp[a[i]] = have[a[i]];
        ans = min(ans, n - dp[a[i]]);
        if (in[a[i]] == 0)
        {
            q.push(a[i]);
        }
    }
    while (q.size())
    {
        int v = q.front();
        q.pop();
        vis[v] = true;
        for (auto x : G[v])
        {
            dp[x] = max(dp[x], dp[v] + have[x]);
            if (!vis[x])
            {
                q.push(x);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, n - dp[a[i]]);
    }
    cout << ans << endl;
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
