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
string a[5];
void solve(){

	for(int i = 0; i <= 3 ; i++) cin >> a[i];

	bool st = false;
	for(int i = 0 ;i <= 2 ; i++)
		for(int j = 0; j <= 2 ; j++)
			if((a[i][j] == '.' && a[i][j + 1] == '.' && a[i + 1][j + 1] == '.' && a[i + 1][j] == '.')
				|| (a[i][j] == '#' && a[i][j + 1] == '#' && a[i + 1][j + 1] == '#' && a[i + 1][j] == '#'))
			st = true;
			
	if(st) puts("Yes");
	else puts("No");
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
