#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;

int x[MAXN],y[MAXN];

// 计算两点之间的距离的平方
int dis2(int x1,int y1,int x2,int y2){
    int dx=x1-x2, dy=y1-y2;
    return dx*dx+dy*dy;
}

void solve(){
    cin >> n;
     for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(x[i]==x[j] && y[i]==y[j]) continue;  // i,j 共点
            for(int k=j+1;k<n;k++){
                if(x[i]==x[k] && y[i]==y[k]) continue;  // i,k 共点
                if(x[j]==x[k] && y[j]==y[k]) continue;  // j,k 共点
                if((x[k]-x[i])*(y[j]-y[i])==(y[k]-y[i])*(x[j]-x[i])) continue;  // 三点共线
                int a=dis2(x[i],y[i],x[j],y[j]);
                int b=dis2(x[i],y[i],x[k],y[k]);
                int c=dis2(x[j],y[j],x[k],y[k]);
                if(a==b || b==c || c==a) ans++;  // a、b、c互相比较
            }
        }
    }
    cout << ans << endl

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