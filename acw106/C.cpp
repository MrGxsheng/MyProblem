#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int,pair<int, int>> Pii;

const int N = 200010;
int a[N];
int n;
string s;
int l[N],r[N];
bool st[N];
void solve(){
	cin >> n >> s;
    s = '?' + s;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        l[i] = i - 1;
        r[i] = i + 1;
    }
    
    priority_queue<Pii , vector<Pii> , greater<Pii> > heap;
    
    for(int i = 1 ; i <= n - 1; i++){
        if(s[i] != s[i + 1]){
            int x = abs(a[i] - a[i + 1]);
            heap.push({x,{i,i + 1}});
        }
    }
    vector<PII> ans;
    while(heap.size() ){
        auto t = heap.top();
        int x = t.second.first;
        int y = t.second.second;
        heap.pop();
        
        if(st[x] || st[y]) continue;
        st[x] = true;
        st[y] = true;
        ans.push_back({x,y});
        if(l[x] > 0 && r[y] <= n && !st[l[x]] && !st[r[y]]  && s[l[x]] != s[r[y]]){
            int w = abs(a[l[x]] - a[r[y]]);
            heap.push({w,{l[x],r[y]}});
        }
        
        r[l[x]] = r[y];
        l[r[y]] = l[x];
    }
    cout << ans.size() << endl;
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i].first << ' ' << ans[i].second  << endl;
    }
    
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