#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
LL n,m;
LL d[N];

void solve(){
	cin >> n >> m;
	priority_queue <int> q;

	for(int i = 1 ;  i<= m ; i++) 
		cin >> d[i];
	
	sort(d + 1, d + 1 + m);
	for(int i = 1 ; i <= m - 1 ; i++)
		q.push(d[i + 1] - d[i] - 1);
	q.push(n - d[m] + d[1] - 1);	

	LL ans = 0;
	for(int i = 0; i + 1 > 0; i ++){  //i代表天数 
        if(!q.empty() && q.top() - i * 4 > 0){  //经过一天，下一个区间长度 -4 
            int k = q.top() - i * 4;  //设k为当前区间经过i天后未感染的区间长度 
            if(k > 1) k --;  //对于一个端点的保护，会使另一个端点被感染(长度-1)，若区间长度仅为1，则只能保护1长度 
            ans += k;  //累计保护到的区间长度 
            q.pop();
        }
        else break;
    }
	cout << ans << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
