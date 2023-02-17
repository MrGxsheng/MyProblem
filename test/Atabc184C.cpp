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
void solve(){
	int r1,c1,r2,c2;
	cin >> r1 >> c1 >> r2 >> c2;
	if(r1 == r2 && c1 == c2) cout << 0 << endl;
	else {
		int a1 = r1 + c1;
		int a2 = r1 - c1;
		int a3 = abs(r1 - r2);
		int b1 = r2 + c2;
		int b2 = r2 - c2;
		int b3 = abs(c1 - c2);
		int r = r2 - r1, c = c2 - c1;
		if(a1 == b1 || a2 == b2 || a3 + b3 <= 3 || abs(r1 - r2) == abs(c1 - c2)) {
			cout << 1 << endl;
			return;
		}

		if((r ^ c ^ 1) & 1 || ( abs(r + c) <= 3 || abs(r - c) <= 3 || abs(r) + abs(c) <= 6)) {
			cout << 2 << endl;
			return;
		}

		cout << 3 << endl;

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
