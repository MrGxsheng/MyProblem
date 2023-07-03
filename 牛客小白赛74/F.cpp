#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
vector<int> pro[N];
int n, m, q;


struct Node{
    int a, b, c;
    bool operator< (const Node &W)const {
        return c < W.c;
    }
}edge[N];
int p[N];
int find(int x){
    return x == p[x] ? x : p[x] = find(p[x]);
}

void kruskal(int mid){
    for (int i = 1; i <= m; i ++ ) {
        int a = edge[i].a, b = edge[i].b, c = edge[i].c;
        if (c <= mid) {
            a = find(a), b = find(b);
            if (a != b) p[a] = b;
        }
    }
}

bool check(int mid){
    for ( int i = 1; i <= n; i ++ ) p[i] = i;
    kruskal(mid);
    for ( int i = 1; i <= q; i ++ ) {
        int anc = find(pro[i][0]);
        for ( int j = 1; j < pro[i].size(); j ++ ) {
            if (find(pro[i][j]) != anc) return false;
        }
    }
    return true;
}

void solve(){
	cin >> n >> m;
    int l = 1, r = 0;
    for ( int i = 1; i <= m; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
        r = max(r, c);
    }
    sort(edge + 1, edge + m + 1);
    cin >> q;
    for ( int i = 1; i <= q; i ++ ) {
        int cnt;
        cin >> cnt;
        for ( int j = 1; j <= cnt; j ++ ) {
            int x; cin >> x;
            pro[i].push_back(x);
        }
    }

    while (l < r){
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;
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