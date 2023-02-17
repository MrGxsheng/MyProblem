#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
double n,m,x,y,r;
double w[N],v[N],xx[N],yy[N];
bool st[N];
int res = 0;

double get(double x1, double y1, double x2, double y2)
{
    double x = x1 - x2;
    double y = y1 - y2;
    return sqrt(x * x + y * y);
}

bool dfs(int u, int pre, int now){
    double len;
    if(pre == -1) len = get(x, y, xx[now], yy[now]);
    else len = get(xx[now], yy[now], xx[pre], yy[pre]);
    
    if(len > r) return false; 


    double num = 400 + n + 0.5 * m + 0.25 * (v[now] - w[now]);
    if(num < w[now]) return false;

    res = max(u , res);
    if(u == 5) return true;

    for(int i = 0 ; i < 5 ; i ++){
        if(!st[i]){
            st[i] = true;
            if(dfs(u + 1, now, i)) return true;
            st[i] = false;
        }
    }

    return false;
}

void solve(){
    cin >> n >> m >> x >>  y>> r;
    for(int i = 0 ; i < 5 ; i++) 
        cin >> w[i] >> v[i] >> xx[i] >> yy[i];
    for(int i = 0 ; i < 5 ; i++){
        memset(st,0,sizeof st); 
        st[i] = true;
        if(dfs(1,-1,i)){
            puts("YES");
            return;
        }
    }
    puts("NO");
    cout << res << endl;

}

int main(){
    int T;
    // cin >> T;
    T = 1;
    while(T--) solve();
    return 0;
}