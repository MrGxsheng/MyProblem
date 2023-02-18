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

void solve(){
	cin >> n >> m;
	vector<int>a,b;
	vector<int> v(n);

	for(int &e : v) cin >> e;
	for(int &e : v){
		int x;
		cin >> x;
		if(x == 1) a.push_back(e);
		else b.push_back(e);
	}

	sort(a.rbegin() , a.rend());
	sort(b.rbegin() , b.rend());

	LL sumA = 0;
	int r = (int) b.size();
	LL sumB = accumulate(b.begin() , b.end() , 0ll);

	int ans = INT_MAX;
	for(int l = 0 ; l <= a.size() ; l++){
		while(r > 0 && sumA + sumB - b[r - 1] >= m){
			r--;
			sumB -= b[r];
		}

		if(sumB + sumA >= m) ans = min(ans,2 * r + l);
		if(l != a.size()) sumA += a[l];
	}
	cout << (ans == INT_MAX ? -1 : ans) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
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
