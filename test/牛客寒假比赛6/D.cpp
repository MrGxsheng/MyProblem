#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<LL,int> PII;
const int N = 1000010;
int n,m;
string s;
LL dp1[N][3];
LL dp2[N][3];
void solve(){

	string s;
	cin >> s;
	int n = s.size();
	s  = " " + s;
	for(int i = 1; i <= n; i ++)
	{
		if(s[i] == 'd')	dp1[i][1] += dp1[i-1][0];
		dp1[i][1] += dp1[i-1][1];
		
		if(s[i] == 'u')	dp1[i][2] += dp1[i-1][1];
		dp1[i][2] += dp1[i-1][2];
		
		if(s[i] == 'u')	dp1[i][0] ++;
		dp1[i][0] += dp1[i-1][0];
	
	}
	
	
	for(int i = n; i >= 1; i --)
	{
		if(s[i] == 'u')	dp2[i][0] ++;
		dp2[i][0] += dp2[i+1][0];
		
		if(s[i] == 'd')	dp2[i][1] += dp2[i+1][0];
		dp2[i][1] += dp2[i+1][1];
		
		if(s[i] == 'u')	dp2[i][2] += dp2[i+1][1];
		dp2[i][2] += dp2[i+1][2];
	
	}
	
	LL res = 0, pos = - 1;
	
	
	for(int i = 1; i <= n; i ++)
	{
		if(s[i] != 'u' && s[i] != 'd')	continue;
		
		if(s[i] == 'u')
		{
			LL tp = dp1[i-1][1] + dp2[i+1][1];	//	减少的数量  1 到 i - 1 的 ud, i + 1 到 n 的 ud
			if(tp > res)
				res = tp, pos = i;
		}
		else if(s[i] == 'd')
		{
			LL tp = dp1[i-1][0] * dp2[i+1][0];
			if(tp > res)
				res = tp, pos = i;
		}
		
	}
		// cout << pos << '\n';
	

	if(pos != -1)
		s[pos] = 'v';
		
	for(int i = 1; i <= n; i++)	cout << s[i];			

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
