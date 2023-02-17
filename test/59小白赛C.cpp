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

LL qmi(int a, int b){
	if(a == 0) return 1;
	LL res = 1;
	while(b){
		if(b & 1) res *= a;
		a = (LL)a * a;
		b >>= 1;
	}
	return res;

}

void solve(){
	LL l,r,k;
	cin >> l >> r >> k;
	bool st = false;

	if(k == 0){
		if(l == 0){
			cout << 0 << ' ';
			st = true;
		}
		if(l <= 1 && r >= 1){
			cout << 1 << ' ';
			st = true;
		}
	}else if(k == 1){
		if(l <= 1 && r >= 1){
			cout << 1 << ' ';
			st = true;
		}
	}else{
		LL Q = 1;
        while (Q <= r) {
            if (Q >= l) cout << Q << ' ', st = true;
            if ((1ull << 63) / Q >= k) Q *= k; else break;
            }
        }

	if(!st) cout << "None." << endl;
	else cout << endl;
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
