#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int mp[N];
void solve(){
	cin >> n;
    vector<int> a(n + 1);
    vector<int> ans(n + 1);
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];

    }


    for(int l = 1 ; l <= n ; l++){
        int cnt = 0 , id = 0;
        for(int i = 1 ; i <= n ; i++) mp[i] = 0;
        for(int r = l ; r <= n ; r++){
            mp[a[r]]++;
            if(mp[a[r]] > cnt) id = r , cnt = mp[a[r]];
            else if(mp[a[r]] == cnt && a[r] < a[id]) id = r;
            ans[a[id]]++;
        }
    }




    for(int i = 1 ; i <= n ; i++) cout << ans[i] << ' ';
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