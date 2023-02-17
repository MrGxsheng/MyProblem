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
string s;
int k;

void solve(){

    cin >> s >> k;

    int len = s.size() - 1;
    reverse(s.begin(),s.end());
    for(int i = 0; i <= len; i ++){
        a[i] = s[i] - '0';
    }
    int x = 0;
    for(int i = 1; i <= k; i ++){     
        if(a[i - 1] >= 5){
            a[i] ++;
            a[i - 1] = 0;
        }else{
            a[i - 1] = 0;
        } 
    }
    for(int i = 0; i <= len + 1; i ++){
        if(a[i] == 10){
            a[i + 1] ++;
            a[i] = 0;
        }       
    }
    if(a[len+1]==1){
        for(int i = len+1;i>=0;i--){
            cout<<a[i];
        }
    }else if(a[len+1]==0){
        if(a[len] == 0) cout << 0;
        else
         for(int i = len;i >= 0;i --){
            cout<<a[i];
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
