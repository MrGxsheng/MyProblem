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
int cnt;
LL res;
char path[14];
bool ok;
int a;
string t;
LL qmi(int a, int b, int p)
{
    LL res = 1 % p;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * (LL)a % p;
        b >>= 1;
    }
    return res;
}

void dfs(int u){
	if(u == cnt){
		if(res == s[cnt - 1] - '0'){
			ok = true;
			for(int i = 0 ; i < a ; i++){
				cout << s[i] << path[i];
			}
			cout << s[a] << '=' << s[cnt - 1];
		}
		return;
	}

	path[u] = '+';
	res = s[u] + s[u + 1] - '0';
	s[u + 1] += s[u];
	dfs(u + 1);
	s[u + 1] -= s[u];

	path[u] = '-';
	res = s[u] - s[u + 1] - '0';
	s[u + 1] -= s[u];
	dfs(u + 1);
	s[u + 1] += s[u];

	path[u] = '#';
	res = qmi(s[u] - '0',s[u] - '0',s[u + 1] - '0');
	string aa = s[u + 1];
	s[u + 1] = res;
	dfs(u + 1);
	s[u + 1] = aa;

}

void solve(){
	cin >> t;

	for(int i = 0 ; i < t.length() ; i ++){
		if(t[i] != '?' && t[i] != '='){
			int j = i;
			while(t[j] != '+') {
				s[cnt] += t[j];
				j++;
			}
			i = j;
			cnt++;
		}else if(t[i] == '?'){
			a++;
		}
	}

	dfs(0);
	if(!ok) cout << -1 << endl;
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
f