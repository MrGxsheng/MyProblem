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
int pos[11];

void solve()
{
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	s1 = " " + s1;
	s2 = " " + s2;
	memset(pos, 0, sizeof pos);
	for(int i = 1; i <= n; i ++)
		pos[s1[i] - '0'] = i;
	for(int i = 1; i <= n; i ++)
	{
		if(s2[i] > s1[i])
		{
			if(i != n)	cout << i + 1 << " " << i + 1 << '\n';
			else cout << i - 1 << " " << i - 1 << '\n';
			return;
		}
		else if(s1[i] > s2[i])
		{
			cout << i << " " << i << "\n";
			return;
		}
		else
		{
			int x = s1[i] - '0';
			for(int k = x + 1; k <= 9; k ++)
				if(pos[k] > i)
				{
					cout << pos[k] << " " << i << '\n';
					return;
				}
		}
	}
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
