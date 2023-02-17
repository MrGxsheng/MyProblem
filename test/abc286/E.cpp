#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1e8)
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 310;
int n,m;

void solve(){
	cin >> n;
	vector<int> a(n); 
	for(int i = 0 ; i < n ; i++) cin >> a[i];

	vector<vector<int>> d(n,vector<int>(n,inf));
	vector<vector<LL>> f(n,vector<LL>(n,0));
	for(int i = 0 ; i < n ; i++){
		string s;
		cin >> s;
		for(int j = 0 ; j < s.length() ; j++){
			if(i == j){
				d[i][j] = 0;
				f[i][j] = a[i];
			}else if(s[j] == 'Y'){
				d[i][j] = 1;
				f[i][j] = a[i] + a[j];
			}
		}
	}

	for (int k = 0; k < n; k ++ )
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ ){
            	if(d[i][k] + d[k][j] < d[i][j]){
                	d[i][j] = d[i][k] + d[k][j];
                	f[i][j] = f[i][k] + f[k][j] - a[k];
            	}else if(d[i][j] == d[i][k] + d[k][j]){
            		f[i][j] = max(f[i][j],f[i][k] + f[k][j] - a[k]);
            	}
            }

	cin >> m;
	for(int i = 0 ; i < m ; i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		if(d[u][v] == inf){
			cout << "Impossible" << endl;
		}else  cout << d[u][v] << ' '<< f[u][v] <<  endl;
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
