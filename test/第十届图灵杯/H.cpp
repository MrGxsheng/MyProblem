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
LL n,p,k,b,T;
map<int,int> mp;
void solve(){
	cin >> n >> p >> k >> b >> T;
	vector<LL> a(n),s(n + 1);
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}
	vector<int> st(n,0);
	vector<int> q;
	do{
		q.push_back(p);
		st[p] = 1;
		p = (1ll * k * p + b) % n;
	}while(!st[p]);

	int pos = find(q.begin(), q.end(), p) - q.begin();
	for(int &i : q) i = a[i];

	vector<int> cir(q.begin() + pos , q.end());
	q = vector<int>(q.begin(), q.begin() + pos);

	LL dec = min(LL(q.size()) , T);
	LL res = accumulate(q.begin(),q.begin() + dec , 0ll);

	T -= dec;
	if(T > 0){
		int len = cir.size();
		LL tot = accumulate(cir.begin() , cir.end() , 0ll);
		res += T / len * tot + accumulate(cir.begin() , cir.begin() + T % len , 0ll);
	}
	cout << res << endl;
}	


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	// cin >> T;

	solve();
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
