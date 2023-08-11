#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
const int MAXN = 1e9 + 7;
int n, k, base[1200], a[100007], b[100007];
vector<int> v;
void dfs(LL x) {
    if (x > MAXN) return;
    if (x) v.push_back(x);
    dfs(x * 10 + 4), dfs(x * 10 + 7);
}
bool check(int x) {
    while (x > 0) {
        if (x % 10 != 4 && x % 10 != 7) return 0;
        x /= 10;
    }
    return 1;
}

void solve(){
	dfs(0);
	base[0] = 1;
	for(int i = 1 ; i <= 15 ; i++) base[i] = base[i - 1] * i;
	cin >> n >> k;
	int pos = 0;

	for(int i = 1 ; i <= min(15,n) ; i++){
		if(base[i] >= k){
			pos = i;
			break;
		}
	}

	if(base[pos] < k){
		cout << -1 << endl;
		return;
	}

	int ans = 0;
	for(int i = 0 ; i < v.size() ; i++)
		if(v[i] < n - pos + 1)
			ans++;
	for(int i = 1 ; i <= pos ; i++) a[i] = n - i + 1;
	sort(a + 1, a + pos + 1) ; 
	k--;
	for(int i = 1 ; i <= pos ; i++){
		if(k <= 0) break;
		if(k < base[pos - i]) continue;
		int p = k / base[pos - i];
		swap(a[i],a[i + p]);
		k %= base[pos - i];
		sort(a + i + 1 , a + pos + 1);
	}

	for(int i = 1 ; i <= pos ; i++)
		if(check(i + n - pos) && check(a[i]))
			ans++;
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