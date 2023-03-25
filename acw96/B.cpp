#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1010;
int n,m,v0,w0;
int l[N],h[N],w[N],v[N];
int s[N];
int f[20][N];
int main()
{
    cin >> n >> m >> v0 >> w0;
    for(int i = 2 ; i <= m + 1 ; i++) cin >> l[i] >> h[i] >> v[i] >> w[i];
    for(int i = 2 ; i <= m + 1 ; i++) s[i] = l[i] / h[i];
    s[1] = n / v0;
    v[1] = v0;
    w[1] = w0;
   
        for (int i = 1; i <= m + 1; i ++ )
            for (int j = 0; j <= n; j ++ )
                for (int k = 0; k <= s[i] && k * v[i] <= j; k ++ )
                    f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
        
        cout << f[m + 1][n] << endl;
        return 0;
}