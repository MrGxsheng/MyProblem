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
void solve(){
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> lc(n, -1), rc(n, -1);
    vector<int> stk;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && a[stk.back()] < a[i]) {
            rc[stk.back()] = lc[i];
            lc[i] = stk.back();
            stk.pop_back();
        }
        stk.push_back(i);
    }


    while (stk.size() >= 2) {
        int u = stk.back();
        stk.pop_back();
        rc[stk.back()] = u;
    }


	int ans = 0;

	struct Data
	{
		int pre,suf,sum;	
	};

    function<Data(int)> dfs = [&](int u) {
        if (u == -1)
            return Data{0, 0, 0};
        auto l = dfs(lc[u]), r = dfs(rc[u]);
        ans = max(ans, l.suf + r.pre);
        return Data{max(l.pre, l.sum + a[u] + r.pre), max({r.suf, l.suf + a[u] + r.sum}), l.sum + a[u] + r.sum};
    };
    dfs(stk[0]);
	cout << ans << endl;
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
