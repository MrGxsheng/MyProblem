#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 10010;
int n,m,h,x;
int a[N];
int sum = 0;
void solve(){
	cin >> n >> m >> h;
	for(int i = 1 ; i <= m ; i++){
		cin >> a[i];
		sum += a[i];
		if(h == i) x = a[i];
	} 

	if(sum < n){
		cout << -1 << endl;
		return;
	}
	if(sum - a[h] < n - 1){
		cout << 1 << endl;
		return;
	}
    double ans = 1.0;
    double x = sum - a[h], y = sum - 1;
    for(int i = 1; i <= n - 1; i++){
        ans *= x / y;
        x--, y--;
    }
	cout << fixed << setprecision(6) << 1.0 - ans << endl;

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