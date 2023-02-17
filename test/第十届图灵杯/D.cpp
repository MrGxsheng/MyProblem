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
string s[N];
void solve(){
	int cnt = 0;
	vector<string> v;
	string tp, t = "WOW NEUQ", t2 = "NEUQ";
	while(getline(cin, tp))
	{
		if(tp == "#")	break;
		for(int i = 0; i < tp.size(); i ++)
		{
			if(tp[i] == ' ')	continue;
			string tpp = "";
			tpp += tp[i];
			int j = i;
			while(j + 1 < tp.size() && tp[j + 1] != ' ')
				j ++, tpp += tp[j];
			i = j;
			
			if(tpp.size() == 4 && t2 != tpp)
			{
				if((tpp[0] == 'N' || tpp[0] == 'n') && (tpp[1] == 'E' || tpp[1] == 'e') && (tpp[2] == 'U' || tpp[2] == 'u') && (tpp[3] == 'Q' || tpp[3] == 'q') )
					cnt ++;
			}
			if(tpp == t2)	tpp = t;
			tpp += " ";
			v.push_back(tpp);
		}		
		v.push_back("\n");
	}
	cout << cnt << '\n';
	for(int i = 0; i < v.size() - 1; i ++)
	{
		cout << v[i];
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
