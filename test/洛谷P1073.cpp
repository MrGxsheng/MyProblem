/**
 * SPFA + dp思想
 * 1 - k 买的最小值 mink
 * k - n 卖的最大值 maxk
 * 答案就是 maxk - mink
 */
#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010 , M = N * 2;
int n,m;
int hs[N],ht[N],e[M],ne[M],idx,w[N];
bool st[N];
int dist[N];
int q[N];
int mink[N],maxk[N];


void add(int h[] , int a , int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

//spfa 用的是循环队列
void spfa(int h[] , int dist[] , int type){
    if(type == 0){
        memset(dist,0x3f,sizeof mink);
        dist[1] = w[1];
        q[0] = 1;
    }else {
        memset(dist,-0x3f,sizeof maxk);
        dist[n] = w[n];
        q[0] = n;
    }
    
    int hh = 0 , tt = 1; 
    while(hh != tt){
        int t = q[hh++];
        if(hh == N) hh = 0;
        st[t] = false; // 代表t出队
        
        for(int i = h[t] ; ~i ; i = ne[i]){
            int j = e[i];
            if(type == 0 && dist[j] > min(dist[t] , w[j]) || type == 1 && dist[j] < max(w[j] , dist[t])){
                if(type == 0)
                    dist[j] = min(dist[t],w[j]);  
                else
                    dist[j] = max(dist[t],w[j]);
                
                q[tt++] = j;
                if(tt == N) tt = 0;
                st[j] = true; //j进队
            }
        }
    }
}

void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> w[i];
	
	memset(hs,-1,sizeof hs);
	memset(ht,-1,sizeof ht);
	while(m--){
		int a ,b,c;
		cin >> a >> b >> c;
		add(hs,a,b); //注意反向建边！！
		add(ht,b,a);
		if(c == 2) add(hs,b,a),add(ht,a,b);
	}

	spfa(hs,mink,0);
	spfa(ht,maxk,1);

	int res = 0;
	for(int i = 1 ; i <= n ; i++) res = max(res,maxk[i] - mink[i]);
	cout << res << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
