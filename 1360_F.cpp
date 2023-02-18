#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
string s[N];

int check(string a,string b,int m){
    int ct = 0;
    for(int i = 0 ; i < m ; i ++) if(a[i] != b[i]) ct++;
    if(ct <= 1) return 1;
    else return 0;
}

void solve(){
	cin>>n>>m;
    string ar[n];
    for(int i= 0  ; i < n ; i++) cin>> ar[i];
    string ans = ar[0];
    int fl = 0,flag;
    for(int i = 0;i<m;i++){
        ans=ar[0];
        ans[i]='a';
        for(int j = 0 ; j < 26 ; j++){
            flag=1;
            for(int k = 0 ; k < n;k++){
                if(check(ans,ar[k],m)==0){ flag = 0; break; }
            }
            if(flag){ fl = 1; break; }
            ans[i]++;
        }
        if(fl) break;
    }
    if(fl) cout << ans << endl;
    else cout<< "-1" << endl;
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
