#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 8010,M = 8000010;
int n,m;
int h[N],e[M],ne[M],idx;
int dfn[N],low[N],top,skt[N],ts;
bool ins[N];
int cnt,id[N];
char a[N][N], b[N][N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ ts;
    skt[ ++ top] = u, ins[u] = true;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        } else if (ins[j]) low[u] = min(low[u], dfn[j]);
    }

    if (low[u] == dfn[u])
    {
        int y;
        cnt ++ ;
        do
        {
            y = skt[top -- ], ins[y] = false, id[y] = cnt;
        } while (y != u);
    }
}


void solve(){
	cin >> n;

	memset(h,-1,sizeof h);
	memset(dfn, 0, sizeof dfn);
	ts = idx = cnt = 0;

	for (int i = 0; i < n; i++) scanf("%s", a[i]);
    for (int i = 0; i < n; i++) scanf("%s", b[i]);
 
	for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != b[i][j])
            {
                add(j + n * 3, i);
                add(i, j + n * 3);
                add(i + n, j + 2 * n);
                add(j + 2 * n, i + n);
            }
            else
            {
                add(i + n, j + 3 * n);
                add(j + n * 3, i + n);
                add(j + n * 2, i);
                add(i, j + n * 2);
            }
        }
    }
    for (int i = 0; i < 4 * n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (id[i] == id[i + n])
        {
            puts("NO");
            return;
        }
    }
    for (int i = 2 * n ; i < 3 * n; i++)
    {
        if (id[i] == id[i + n])
        {
            puts("NO");
            return;
        }
    }
    puts("YES");

}

int main(){
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
