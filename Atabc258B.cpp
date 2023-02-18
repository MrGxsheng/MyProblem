#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 110;
int n,m;
char a[N][N];
int dx[]= {0,0,1,-1,1,-1,1,-1};
int dy[]= {1,-1,0,0,1,1,-1,-1};

void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			cin >> a[i][j];

	string s = "0";
	for(int k = 0 ; k < 8 ; k ++)
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++){
				string ss = "";
				int x = i , y = j;
				for(int z = 1 ; z <= n ; z++){
					ss += a[x][y];
					x = x + dx[k];
					y = y + dy[k];
					if(x <= 0) x = n;
					if(y <= 0) y = n;
					if(x > n) x = 1;
					if(y > n) y = 1;
					
				}
				s = max(s,ss);

			}
			cout << s << endl;
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
