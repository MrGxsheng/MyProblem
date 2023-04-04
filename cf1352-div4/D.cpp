#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];

	int tep = 0;
	int ans1 = 0;
	int ans2 = 0;
	int pre = 0;
	for(int i = 0 , j = n - 1 ; i <= j ; ){
		int cnt1 = 0;
		int cnt2 = 0;
		bool st1 = false;
		bool st2 = false;
		while(i <= j && cnt1 <= pre){
			ans1 += a[i];
			cnt1 += a[i];
			st1 = true;
			i++;
		}
		if(st1) tep++;
		pre = cnt1;

		while(i <= j && cnt2 <= pre){
			ans2 += a[j];
			cnt2 += a[j];
			st2 = true;
			j--;
		}
		if(st2)tep ++;
		pre = cnt2;
	}

	cout << tep << ' ' << ans1 << ' ' << ans2 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}