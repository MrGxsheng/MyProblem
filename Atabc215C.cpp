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
char a[9];
void solve(){
	string s;
	cin >> s >> n;
	map<int,int> mp;
	m = s.length();
	for(int i = 0 ; i < m ; i++) {
		a[i] = s[i];
		mp[s[i] - 'a']++;
	}
	int ans = 0;
	for(int i = 0 ; i < 26 ; i++)
		while(mp[i]--) a[ans++] = char(i + 'a');
	
	int cnt = 1;
	do{
		 if(cnt == n){
			for(int i = 0 ; i < m ; i++)
				cout << a[i];
			 return;
		 }
		cnt++;
	}while(next_permutation(a,a+m));

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
