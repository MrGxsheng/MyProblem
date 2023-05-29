#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
int n, m;
    cin >> n >> m;
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<LL> b1(n + 1), b2(n + 1);
    for (int i = 1; i <= n; ++i){
        while (a[i] % 2 == 0)
        {
            b1[i]++;
            a[i] /= 2;
        }
        while (a[i] % 5 == 0)
        {
            b2[i]++;
            a[i] /= 5;
        }
    }
    partial_sum(b1.begin(), b1.end(), b1.begin());
    partial_sum(b2.begin(), b2.end(), b2.begin());


	LL ans = 0;
	for(int i = 1 ; i <= n ; i++){
		if (b1[i] >= m && b2[i] >= m){
            int l = lower_bound(b1.begin(), b1.begin() + i, b1[i] - m) - b1.begin();
            int r = upper_bound(b1.begin(), b1.begin() + i, b1[i] - m) - b1.begin();
 
            int L = lower_bound(b2.begin(), b2.begin() + i, b2[i] - m) - b2.begin();
            int R = upper_bound(b2.begin(), b2.begin() + i, b2[i] - m) - b2.begin();
            LL res = min(R, r) - min(l, L);
            ans += res;
        }
	}
	cout << ans << endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}