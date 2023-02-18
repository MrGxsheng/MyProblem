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
LL d[70], p[70], cnt;
const int mod = 10086;
bool zero = false;
void init()
{
    cnt = 0;
    zero = false;
    memset(d, 0, sizeof(d));
    memset(p, 0, sizeof(p));
}
LL qpow(LL a, int p)
{
    LL res = 1;
    while (p)
    {
        if (p & 1)
            res = res * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return res;
}
void insert(LL x)
{
    for (int i = 59; i >= 0; i--)
    {
        if (x >> i)
        {
            if (!p[i])
            {
                p[i] = x;
                return;
            }
            x ^= p[i];
        }
    }
    zero = true;
}
void rebuild()
{
    for (int i = 0; i <= 59; i++)
        for (int j = i - 1; j >= 0; j--)
            if (p[i] & (1LL << j))
                p[i] ^= p[j];
    for (int i = 0; i <= 59; i++)
        if (p[i])
            d[cnt++] = p[i];
}
LL ask_kmax(LL k)
{
    k -= zero;
    if (!k)
        return 0;
    if (k >= (1LL << cnt))
        return -1;
    LL res = 0;
    for (int i = 59; i >= 0; i--)
        if (k & (1LL << i))
            res ^= d[i];
    return res;
}
LL ask_kmin(LL k)
{
    k -= zero;
    if (!k)
        return 0;
    if (k >= (1LL << cnt))
        return -1;
    LL res = 0;
    for (int i = 0; i <= 59; i++)
        if (k & (1LL << i))
            res = res ^ d[i];
    return res;
}
LL ask_max()
{
    LL res = 0;
    for (int i = 59; i >= 0; i--)
        res = max(res, res ^ d[i]);
    return res;
}
LL ask_min()
{
    if (zero)
        return 0;
    for (int i = 0; i <= 59; i++)
        if (d[i])
            return d[i];
    return 0;
}
LL ask_firstX(int n, LL x)
{
    LL res = 0;
    for (int i = 0; i <= 59; i++)
        if (p[i])
            d[cnt++] = i;
    for (int i = 0; i < cnt; i++)
        if (x & (1LL << d[i]))
            (res += (1LL << i)) %= mod;
    res = ((res * qpow(1LL * 2, n - cnt) + 1) % mod) % mod;
    return res;
}
bool exist(LL x)
{
    for (int i = 59; i >= 0; i--)
    {
        if (x & (1 << i))
            x ^= p[i];
        if (!x)
            return true;
    }
    return false;
}                                          


void solve(){
	init();
    LL n, x, L, R;
    scanf("%lld%lld%lld", &n, &L, &R);
    for (LL i = 1; i <= n; i++)
    {
        scanf("%lld", &x);
        insert(x);
    }
    rebuild();
    for (LL i = L; i <= R; i++)
    {
        printf("%lld ", ask_kmax(i - !(zero)));
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
