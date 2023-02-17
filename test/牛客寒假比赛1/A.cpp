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
	string s;
	cin >> s;
	int ans1 = 0;
    int ans2 = 0;
	for(int i = 0 ; i < 10 ; i++) {
		if((i & 1) && s[i] == '1') ans2++;
        else if(s[i] == '1')ans1++;
        
        if((i % 2 == 0) &&  ans1 > ans2 && ans1 - ans2 > (10 - (i + 1)) / 2 + 1) {
            cout << i + 1 << endl;
            return;
        }
        
        if((i % 2 == 0) &&  ans2 > ans1 && ans2 - ans1 > (10 - (i + 1)) / 2) {
            cout << i + 1 << endl;
            return;
        }
        
        if((i & 1) && ans2 > ans1 && ans2 - ans1 > (10 - (i + 1)) / 2){
            cout << i + 1 << endl;
            return;
        }
        
        if((i & 1) && ans1 > ans2 && ans1 - ans2 > (10 - (i + 1)) / 2){
            cout << i + 1 << endl;
            return;
        }
	}
	cout << -1 << endl;
		
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	// T = 1;
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
