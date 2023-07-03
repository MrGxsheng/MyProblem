#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using pos = tuple<int, int, bool>;
using stat = pair<int, pos>;

const int N = 1e3 + 10;

int n, m;
char s[N][N];
 
int dis[N][N][2];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> (s[i] + 1);
    memset(dis, 0x3f, sizeof dis);
    dis[1][1][s[1][1] - '0'] = 0;
    priority_queue<stat, vector<stat>, greater<stat> > q;
    q.push({0, {1, 1, s[1][1] - '0'}});
    while(q.size()) {
        auto [a, b] = q.top();
        q.pop();
        auto [x, y, z] = b;
        if(a > dis[x][y][z]) continue;
        auto update = [&q](int x, int y, bool z, int d) {
            if(x < 1 || x > n || y < 1 || y > m) return;
            d ++;
            if(z == (s[x][y] - '0')) d ++;
            if(dis[x][y][!z] > d) {
                dis[x][y][!z] = d;
                q.push({d, {x, y, !z}});
            }
        };
        update(x - 1, y, z, a);
        update(x + 1, y, z, a);
        update(x, y - 1, z, a);
        update(x, y + 1, z, a);
    }
    cout << min(dis[n][m][0], dis[n][m][1]);
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