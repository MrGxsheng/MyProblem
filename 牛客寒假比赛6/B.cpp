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
const int N = 2e5 + 10, M = 4e5 + 10;
int n, q;
int a[M], gx[M];
vector<int> g(N), yz[N], ug[N];

void get_primes(int nn)
{
    for (int i = 1; i <= nn; i ++ )
        for (int j = i; j <= nn; j += i)
            yz[j].push_back(i);
}

void insert(int x, int id)
{
    for (int i : yz[x])
        if (g[i])
            ug[i].push_back(g[i] - 1);    
    gx[id] = g[x] ++ ;
}

int get(int x, int id)
{
    int t = lower_bound(ug[x].begin(), ug[x].end(), id) - ug[x].begin();
    return ug[x].size() - t;
}

void solve()
{
    get_primes(200010);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i ++ ) 
    {
       cin >> a[i];
        insert(a[i], i);
    }
    
    while (q -- )
    {
        int op, x;
        cin >> op >> x;
        if (op == 1) 
        {
            a[ ++ n] = x;
            insert(a[n], n);
        }
        else 
        {
            int t = get(a[x], gx[x]);
           	cout << t << endl;
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
