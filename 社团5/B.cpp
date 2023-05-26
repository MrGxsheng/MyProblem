#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
LL a[N],b[N];
void solve(){
	cin >> n;
	LL ans = 0;
    for(int i = 1 ; i <= n ; i++){
    	int x;
        cin >> x;
        a[i] = i * i + x * x ;
        b[i] = i * i - x * x;
    }
    sort(a + 1 , a + 1 + n);
    sort(b + 1 , b + 1 + n);
    ans = max(a[n] - a[1] , b[n] - b[1]);
    cout << ans << endl;
	
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