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
void solve(){
	cin >> n >> m;

	vector<int> a,b,ans;
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		if(x >= 0) a.push_back(x);
		else if(x < 0) b.push_back(x);
	}

	sort(b.begin(),b.end());	

	if(b.size() == 1) a.push_back(b[b.size() - 1]);
	else {
        if(b.size() & 1){
            for(int i = 0 ; i < b.size() ; i += 2) {
                if(i + 1 < b.size())
                    ans.push_back(b[i] * b[i + 1]);
            }
            a.push_back(b[b.size() - 1]);
        }else {
		  for(int i = 0 ; i < b.size(); i += 2) {
                ans.push_back(b[i] * b[i + 1]);
            }
        }
	}

	sort(a.begin() , a.end());

	for(int i = a.size() - 1 ; i >= 0 ; i -= 2){
        if(i - 1 >= 0) ans.push_back(a[i] * a[i - 1]);
	}

	sort(ans.rbegin(),ans.rend());

	LL sum = 0;
	for(int i = 0 ; i < m ; i++) {
        sum += ans[i];
    }
	cout << sum << endl;
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
