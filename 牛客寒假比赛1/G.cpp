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
int a[N];
int maxx[N],minn[N];
LL sum[N];

void push(int u){
	maxx[u] = max(maxx[u << 1] , maxx[u << 1 | 1]);
	minn[u] = min(minn[u << 1] , minn[u << 1 | 1]);
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
}

void build(int u , int l , int r){
	if (r - l == 1){
		maxx[u] = minn[u] = sum[u] = a[l];
		if(a[l] == 0) maxx[u] = minn[u] = 100;
		return;
	}

	int mid = l + r >> 1;
	build(u << 1 , l , mid);
	build(u << 1 | 1 , mid , r);
	push(u);
}

void modify(int u , int l , int r , int x , int y , int k){
	if(maxx[u] <= 100 && minn[u] >= 99) return;
	if(l >= y || r <= x) return;
	if (r - l == 1){
		while(k && maxx[u] != 100 && maxx[u] != 99){
			maxx[u] = sqrt(maxx[u]) * 10 + .5;
			k--;
		}
		minn[u] = sum[u] = maxx[u];
		return;
	}

	int mid = l + r >> 1;
	modify(u << 1 , l , mid , x , y , k);
	modify(u << 1 | 1 , mid , r , x , y , k);
	push(u);
}

void solve(){
	cin >> n >> m;


	for(int i = 0 ; i < n ; i++) cin >> a[i];

	build(1,0,n);
	while(m--){
		int op;
		cin >> op;
		if(op == 1){
			int l , r , k;
			cin >> l >> r >> k;
			l--;
			modify(1,0,n,l,r,k);
		}else{
			cout << sum[1] << endl;
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
