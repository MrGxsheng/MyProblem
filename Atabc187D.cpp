#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int a[N];
int b[N];
PII aa[N];


int cmp(pair<int,int>a,pair<int,int>b){
    return 2LL * a.fi +  a.se > 2LL * b.fi + b.se;
}

void solve(){
	cin >> n;
	LL x = 0,y = 0;
	for(int i = 0 ; i< n ; i++){
		cin >> a[i] >> b[i];
		aa[i].fi = a[i],aa[i].se = b[i];
		x += a[i];
		// y += b[i];
		// cout << x << ' ' << y << endl;
	}

	sort(aa,aa + n,cmp);

	int cnt = 0;
	while(x >= y){
		 // cout << aa[cnt].fi << endl;
		x -= aa[cnt].fi;
		y += aa[cnt].fi + aa[cnt].se;
		cnt++;
	}
	// cout << x <<' ' <<  y << endl;
	cout << cnt<< endl;


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
