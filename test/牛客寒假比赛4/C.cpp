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
LL n,m;
LL w[N],v[N];
LL res;
LL f[N];
bool check(LL mid ,int x , LL maxh){
    fill(f,f + 110 , 0);
	for(int i = 1 ; i <= n ; i++){	
        if(i == x){
            for(int j = m ; j >= v[i] ; j--)
                f[j] = max(f[j], f[j - v[i]] + w[i] + mid);
        }else{
            for(int j = m ; j >= v[i] ; j--)
                f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

	return f[m] > maxh;
}
void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> v[i] >> w[i];
    
	for(int i = 1 ; i <= n ; i++)	
		for(int j = m ; j >= v[i] ; j--)
				f[j] = max(f[j], f[j - v[i]] + w[i]);
			
    res = f[m]; 
    
	for(int i = 1 ; i <= n ; i++){
        fill(f,f + 110 , 0);
        for(int j = 1 ; j <= n ; j++){
            if(i == j) continue;
            for(int k = m ; k >= v[j] ; k--)
			{
				f[k] = max(f[k], f[k - v[j]] + w[j]);
			}
        }
		if(f[m] >= res){
            LL l = 1 , r = 1e18 + 10;
            LL ans;
            while(l <= r){
                LL mid = l + r >> 1;
                if(check(mid,i,res)) {
                    r = mid - 1;
                    ans = mid;
                }        
                else l = mid + 1;
            }
            cout << ans << endl;
        }else cout << 0 << endl;
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
