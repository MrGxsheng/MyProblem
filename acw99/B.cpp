#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
    map<int,int> mp;
    map<int,int> mpp;
    for(int i = 0 ; i < n ; i++){
        char op;
        int a,b;
        cin >> op;
        cin >> a >> b;
        if(op == 'B') mp[a] += b;
        else mpp[a] += b;
    }
    
    vector<PII> a(n);
    vector<PII> b(n);
    int cnt = 0;
    int cntt = 0;
    for(auto [x,y] : mp){
        a[cnt++] = {x,y};    
    }
    sort(a.begin(),a.begin() + cnt,greater<PII>());
    
    for(auto [x,y] : mpp){
        b[cntt++] ={x,y};
    }
    
    sort(b.begin(),b.begin() + cntt);

    for(int i = min(m,cntt) - 1 ; i >= 0 ; i--)
            cout << "S " << b[i].first << ' ' << b[i].second << endl;

    for(int i = 0 ; i < cnt && i < m ; i++)
            cout << "B " << a[i].first << ' ' << a[i].second << endl;
    
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