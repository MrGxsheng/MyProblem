#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m,k;
void solve(){
	cin >> n >> k;
	int cnt = 0;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		x--;
		cnt += (x % k != i % k); // 如果同余的话 代表 x 从 i 回到原本x 的位置的距离是m的倍数 d % m == 0
	}
	// 如果有两个以上的数的不能通过普通的交换的话 初始交换只能最多交换两个数 也就是说最少有一个数不能回到原本你都位置
	if(cnt > 2){
		cout << -1 << endl;
		return;
	}
	cout << cnt / 2 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}