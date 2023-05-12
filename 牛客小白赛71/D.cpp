#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;

struct ca{
	int i,a,c;

	bool operator<(const ca &e ) const{
		return this -> a < e.a;
	}
}cat[N];

PII zr[N];

bool cmp(PII a , PII b){
	return a.second < b.second;
}
int ans[N];
void solve(){
	cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> cat[i].a;
    for(int i = 1;i <= n;i++){
        cat[i].i = i;
        cin >> cat[i].c;
    }
    for(int i = 1;i <= m;i++)
        cin >> zr[i].first;
    for(int i = 1;i <= m;i++)
        cin >> zr[i].second;
    sort(zr + 1,zr + 1 + m,cmp);
    sort(cat + 1,cat + 1 + n);

    int top = 1;
    int ma = 0;
    for(int i = 1 ; i <= n ; i++){
    	while(top <= m && cat[i].a >= zr[top].second){
    		ma = max(ma,zr[top].first);
    		top++;
    	}
    	if(ma >= cat[i].c) ans[cat[i].i] = ma;
    	else ans[cat[i].i] = -1;
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