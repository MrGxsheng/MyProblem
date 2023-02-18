#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
int f[N];
void solve()
{
 
    cin >> n;
    int t = 0;
    vector<int> h(n);
    vector<vector<int>> p(n);
    for(int i = 0; i < n; i++) {
        std::cin >> h[i];
        t = max(h[i], t);
        p[h[i]].push_back(i);
    }
    if(p[t].size() > 1) {
        cout << "-1\n";
        return;
    }
    for(int i = 0; i < t; i++) 
        if(p[i].size() < p[i + 1].size()) {
            cout << "-1\n";
            return;
        }
    
    cout << p[t][0] + 1 << "\n";
    for(int i = 0; i < t; i++) 
        for(int j = 0; j < p[i].size(); j++) 
            cout << p[i][j] + 1 << " " << p[i + 1][min(j,int(p[i + 1].size()-1))] + 1 << "\n";
        
    
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
