#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 101;
int n,m;
double dp[N][N][N];

double f(int a,int b,int c)
{
    if(a == 100 || b == 100 || c == 100) return dp[a][b][c] = 0;
    if(dp[a][b][c] > -1) return dp[a][b][c];
    dp[a][b][c] = 0;
    dp[a][b][c] += (f(a + 1,b,c) + 1.0) * a / (1.0 * a + b + c);
    dp[a][b][c] += (f(a,b + 1,c) + 1.0) * b / (1.0 * a + b + c);
    dp[a][b][c] += (f(a,b,c + 1) + 1.0) * c / (1.0 * a + b + c);
    return dp[a][b][c];
}
void solve()
{
    int a,b,c;
    cin >> a >> b >> c;
    for(int i = 0;i <= 100;i++)
        for(int j = 0;j <= 100;j++)
            for(int k = 0;k <= 100;k++)
                dp[i][j][k] = -1.0;
    cout << fixed << setprecision(9) << f(a,b,c) << endl;
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
