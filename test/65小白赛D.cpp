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
LL a,b;
void solve(){
	 cin >> a >> b;
        if( min(a - 2, b - 1) % 3 == 0)
            printf("niuniu\n");
        else if( min(a - 1, b - 2) % 3 == 0)
            printf("niuniu\n");
        else printf("niumei\n");


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
