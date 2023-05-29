#include <bits/stdc++.h>
#define endl '\n'
#define v first
#define w second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 60, M = 32010;
int n, m;
PII master[N];
vector<PII> servent[N];
int f[M];
void solve(){
	cin >> m >> n;

    for (int i = 1; i <= n; i ++ )
    {
        int v, p, q;
        cin >> v >> p >> q;
        p *= v;
        if (!q) master[i] = {v, p};
        else servent[q].push_back({v, p});
    }

    for (int i = 1; i <= n; i ++ )
        for (int u = m; u >= 0; u -- )
        {
            for (int j = 0; j < 1 << servent[i].size(); j ++ )
            {
                int v = master[i].v, w = master[i].w;
                for (int k = 0; k < servent[i].size(); k ++ )
                    if (j >> k & 1)
                    {
                        v += servent[i][k].v;
                        w += servent[i][k].w;
                    }
                if (u >= v) f[u] = max(f[u], f[u - v] + w);
            }
    }

    cout << f[m] << endl;
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