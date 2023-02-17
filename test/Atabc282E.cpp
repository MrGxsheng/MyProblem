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
int p[N];
struct Node{
	int x,y,v;
	bool operator<(const Node &other) const{
		return v > other.v;
	}
};

int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

LL qmi(int a,int b){
	LL res = 1 % m;
	while(b){
		if(b & 1) res = res * a % m;
		a = 1ll * a * a % m;
		b >>= 1;
	}
	return res % m;
}
void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) p[i] = i;
	for(int i = 0 ; i < n ; i++) cin >> a[i];

	LL ans = 0;
	vector<Node> e;
	for(int i = 0 ; i < n ; i++) 
		for(int j = i + 1 ; j < n ; j++){
			int v = (LL)(qmi(a[i],a[j]) + qmi(a[j] , a[i])) % m;
			e.push_back({i,j,v});
	}
	sort(e.begin(),e.end());

	for(auto x : e){
		int pa = find(x.x) , pb = find(x.y);
		if(pa != pb){
			p[pa] = pb;
			ans += x.v;
		}
	}

	cout << ans << endl;
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
