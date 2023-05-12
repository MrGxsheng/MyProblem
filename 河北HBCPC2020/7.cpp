#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
LL n,m,l,r;
void solve(){
	cin >> n >> l >> r;
	vector<LL> a(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];

	vector<LL> s(n + 1);

	for(int i = 0 ; i < n ; i++) s[i + 1] = s[i] + a[i];

	vector<PII> ans;
	for(int i = 1 ; i <= n ; i++){
		for(int j = i ; j <= n ; j++){
			LL sum = s[j] - s[i - 1];

			if(sum >= l && sum <= r){
				ans.push_back({j,i});
				break;
			}
		}
	}
	int cnt = 0;

	sort(ans.begin(),ans.end());
	int pre = -1;
	for(int i = 0 ; i < ans.size() ; i++){

		if(ans[i].second > pre) {
			cnt++;
			pre = ans[i].first;
		}
	}

	cout << cnt << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}